/*
 * Copyright (C) 2007 Apple Inc.  All rights reserved.
 * Copyright (C) 2009 Joseph Pecoraro
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

WebInspector.EventListenersSidebarPane = function()
{
    WebInspector.SidebarPane.call(this, WebInspector.UIString("Event Listeners"));
    this.bodyElement.addStyleClass("events-pane");

    this.sections = [];

    this.settingsSelectElement = document.createElement("select");

    var option = document.createElement("option");
    option.value = "all";
    if (Preferences.eventListenersFilter === "all")
        option.selected = true;
    option.label = WebInspector.UIString("All Nodes");
    this.settingsSelectElement.appendChild(option);

    option = document.createElement("option");
    option.value = "selected";
    if (Preferences.eventListenersFilter === "selected")
        option.selected = true;
    option.label = WebInspector.UIString("Selected Node Only");
    this.settingsSelectElement.appendChild(option);

    this.settingsSelectElement.addEventListener("click", function(event) { event.stopPropagation() }, false);
    this.settingsSelectElement.addEventListener("change", this._changeSetting.bind(this), false);

    this.titleElement.appendChild(this.settingsSelectElement);
}

WebInspector.EventListenersSidebarPane.prototype = {
    update: function(node)
    {
        var body = this.bodyElement;
        body.removeChildren();
        this.sections = [];

        var self = this;
        function callback(nodeId, eventListeners) {
            var sectionNames = [];
            var sectionMap = {};
            for (var i = 0; i < eventListeners.length; ++i) {
                var eventListener = eventListeners[i];
                eventListener.node = WebInspector.domAgent.nodeForId(eventListener.nodeId);
                delete eventListener.nodeId; // no longer needed
                var type = eventListener.type;
                var section = sectionMap[type];
                if (!section) {
                    section = new WebInspector.EventListenersSection(type, nodeId);
                    sectionMap[type] = section;
                    sectionNames.push(type);
                    self.sections.push(section);
                }
                section.addListener(eventListener);
            }
            
            if (sectionNames.length === 0) {
                var div = document.createElement("div");
                div.className = "info";
                div.textContent = WebInspector.UIString("No Event Listeners");
                body.appendChild(div);
                return;
            }

            sectionNames.sort();
            for (var i = 0; i < sectionNames.length; ++i) {
                var section = sectionMap[sectionNames[i]];
                section.update();
                body.appendChild(section.element);
            }
        }

        WebInspector.EventListeners.getEventListenersForNodeAsync(node, callback);
    },

    _changeSetting: function(event)
    {
        var selectedOption = this.settingsSelectElement[this.settingsSelectElement.selectedIndex];
        Preferences.eventListenersFilter = selectedOption.value;

        InspectorController.setSetting("event-listeners-filter", Preferences.eventListenersFilter);

        for (var i = 0; i < this.sections.length; ++i)
            this.sections[i].update();
    }
}

WebInspector.EventListenersSidebarPane.prototype.__proto__ = WebInspector.SidebarPane.prototype;

WebInspector.EventListenersSection = function(title, nodeId)
{
    this.eventListeners = [];
    this._nodeId = nodeId;
    WebInspector.PropertiesSection.call(this, title);

    // Changed from a Properties List
    this.propertiesElement.parentNode.removeChild(this.propertiesElement);
    delete this.propertiesElement;
    delete this.propertiesTreeOutline;

    this.eventBars = document.createElement("div");
    this.eventBars.className = "event-bars";
    this.element.appendChild(this.eventBars);
}

WebInspector.EventListenersSection.prototype = {
    update: function()
    {
        // A Filtered Array simplifies when to create connectors
        var filteredEventListeners = this.eventListeners;
        if (Preferences.eventListenersFilter === "selected") {
            filteredEventListeners = [];
            for (var i = 0; i < this.eventListeners.length; ++i) {
                var eventListener = this.eventListeners[i];
                if (eventListener.node.id === this._nodeId)
                    filteredEventListeners.push(eventListener);
            }
        }

        this.eventBars.removeChildren();
        var length = filteredEventListeners.length;
        for (var i = 0; i < length; ++i) {
            var eventListener = filteredEventListeners[i];
            var eventListenerBar = new WebInspector.EventListenerBar(eventListener);
            if (i < length - 1) {
                var connector = document.createElement("div");
                connector.className = "event-bar-connector";
                eventListenerBar.element.appendChild(connector);
            }

            this.eventBars.appendChild(eventListenerBar.element);
        }
    },

    addListener: function(eventListener)
    {
        this.eventListeners.push(eventListener);
    }
}

WebInspector.EventListenersSection.prototype.__proto__ = WebInspector.PropertiesSection.prototype;

WebInspector.EventListenerBar = function(eventListener)
{
    this.eventListener = eventListener;
    WebInspector.ObjectPropertiesSection.call(this, null, this._getFunctionDisplayName(), this._getNodeDisplayName());
    this.editable = false;
    this.element.className = "event-bar"; /* Changed from "section" */
    this.propertiesElement.className = "event-properties"; /* Changed from "properties" */
}

WebInspector.EventListenerBar.prototype = {
    update: function()
    {
        var properties = [];
        for (var propertyName in this.eventListener) {
            // Just build properties in place - no need to reach out for injected script.
            var value = this.eventListener[propertyName];
            if (value instanceof WebInspector.DOMNode)
                value = new WebInspector.ObjectProxy(value.id, [], 0, appropriateSelectorForNode(value), true);
            else
                value = WebInspector.ObjectProxy.wrapPrimitiveValue(value);
            properties.push(new WebInspector.ObjectPropertyProxy(propertyName, value));
        }
        this.updateProperties(properties);
    },

    _getNodeDisplayName: function()
    {
        var node = this.eventListener.node;
        if (!node)
            return "";

        if (node.nodeType === Node.DOCUMENT_NODE)
            return "document";
        
        return appropriateSelectorForNode(node);
    },

    _getFunctionDisplayName: function()
    {
        // TODO: v8 does not yet provide the raw function, this handles such a case with a placeholder
        // I didn't make this a UIString because it should be implemented eventually.
        if (!this.eventListener.listener)
            return "(listener)";

        // Requires that Function.toString() return at least the function's signature
        var match = this.eventListener.listener.toString().match(/function ([^\(]+?)\(/);
        return (match ? match[1] : WebInspector.UIString("(anonymous function)"));
    }
}

WebInspector.EventListenerBar.prototype.__proto__ = WebInspector.ObjectPropertiesSection.prototype;
