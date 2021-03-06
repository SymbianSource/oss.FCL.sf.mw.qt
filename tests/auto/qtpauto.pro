QT = core
TEMPLATE = subdirs

# These tests use host tools and therefore can't work for cross-compiled Qt.
!cross_compile:SUBDIRS += \
           headers \
           bic \
           compiler \
           compilerwarnings \
           linguist \
           moc \
           uic \
           uic3


SUBDIRS += \
           collections \
           exceptionsafety \
           mediaobject \
#           mediaobject_wince_ds9 \   This is Windows CE only (we test the second phonon backend ds9 here)
           modeltest \
           networkselftest \
           qabstractbutton \
           qabstractitemmodel \
           qabstractitemview \
#           qabstractprintdialog \
           qabstractscrollarea \
           qabstractslider \
           qabstractsocket \
           qabstractspinbox \
           qabstracttextdocumentlayout \
           qabstractvideobuffer \
           qabstractvideosurface \
#           qaccessibility \
           qaction \
           qactiongroup \
           qalgorithms \
           qanimationgroup \
           qapplication \
           qatomicint \
           qatomicpointer \
           qbitarray \
           qboxlayout \
           qbrush \
           qbuffer \
           qbuttongroup \
           qbytearray \
           qcache \
           qchar \
           qcheckbox \
           qclipboard \
           qcolor \
           qcolordialog \
#           qcombobox \
           qcompleter \
           qcomplextext \
           qcoreapplication \
           qcryptographichash \
#           qcssparser \
           qdatastream \
           qdatawidgetmapper \
           qdate \
           qdatetime \
           qdatetimeedit \
           qdebug \
           qdesktopservices \
           qdesktopwidget \
           qdial \
           qdialog \
           qdialogbuttonbox \
           qdir \
           qdirmodel \
           qdockwidget \
           qdom \
           qdoublespinbox \
           qdoublevalidator \
           qdrag \
           qerrormessage \
           qeventloop \
           qexplicitlyshareddatapointer \
           qfile \
#           qfiledialog \
#           qfiledialog2 \
           qfileinfo \
           qfilesystemwatcher \
#           qfilesystemmodel \
           qflags \
           qfocusevent \
           qfocusframe \
           qfont \
           qfontdatabase \
           qfontdialog \
           qfontmetrics \
           qftp \
           qgetputenv \
#           qgl \
           qglobal \
           qgraphicseffect \
           qgraphicseffectsource \
           qgraphicsgridlayout \
           qgraphicsitem \
           qgraphicsitemanimation \
#           qgraphicsanchorlayout \
#           qgraphicsanchorlayout1 \
           qgraphicslayout \
           qgraphicslayoutitem \
           qgraphicslinearlayout \
           qgraphicsobject \
           qgraphicspixmapitem \
           qgraphicspolygonitem \
           qgraphicsproxywidget \
#           qgraphicsscene \
#           qgraphicssceneindex \
           qgraphicstransform \
#           qgraphicsview \
           qgraphicswidget \
           qgridlayout \
           qgroupbox \
           qguivariant \
           qhash \
           qheaderview \
#           qhelpcontentmodel \
#           qhelpenginecore \
#           qhelpgenerator \
#           qhelpindexmodel \
#           qhelpprojectdata \
           qhostaddress \
#           qhostinfo \
           qhttp \
#           qhttpnetworkreply \
#           qhttpnetworkconnection \
           qicon \
           qicoimageformat \
           qimage \
           qimageiohandler \
           qimagereader \
           qimagewriter \
           qinputdialog \
           qintvalidator \
           qiodevice \
           qitemdelegate \
           qitemeditorfactory \
           qitemmodel \
           qitemselectionmodel \
           qitemview \
#           qkeysequence \
           qlabel \
           qlayout \
           qlcdnumber \
           qlibrary \
           qline \
           qlineedit \
           qlist \
           qlistview \
#           qlistwidget \
           qlocale \
#           qmainwindow \
           qmake \
           qmap \
           qmath \
           qmatrixnxn \
           qmdiarea \
           qmdisubwindow \
           qmenu \
           qmenubar \
           qmessagebox \
           qmetaobject \
           qmetatype \
           qmouseevent \
           qmouseevent_modal \
           qmovie \
           qmutex \
           qmutexlocker \
#           qnativesocketengine \
           qnetworkcookie \
           qnetworkcookiejar \
           qnetworkinterface \
           qnetworkproxy \
           qnetworkrequest \
#           qnetworkreply \
           qnetworkaccessmanager_and_qprogressdialog \
           qnumeric \
           qobject \
           qobjectrace \
           qcontiguouscache \
           qpaintengine \
           qpainter \
           qpainterpath \
           qpalette \
           qparallelanimationgroup \
           qpauseanimation \
#           qpathclipper \
           qpen \
           qpicture \
           qpixmap \
           qpixmapcache \
           qpixmapfilter \
           qplaintextedit \
           qpoint \
           qpointer \
           qpolygon \
#           qprinter \
#           qprinterinfo \
           qprocess \
           qprogressbar \
           qprogressdialog \
           qpropertyanimation \
           qpushbutton \
           qquaternion \
           qqueue \
           qradiobutton \
           qreadlocker \
           qreadwritelock \
           qrect \
           qregexp \
           qregexpvalidator \
#           qregion \
           qresourceengine \
           qringbuffer \
           qscopedpointer \
           qscrollarea \
           qsemaphore \
#           qsharedpointer \
#           qsharedpointer_and_qwidget \
           qsequentialanimationgroup \
           qset \
#           qsettings \
           qshortcut \
           qsignalmapper \
           qsignalspy \
           qsize \
           qsizef \
           qslider \
#           qsocketnotifier \
#           qsocks5socketengine \
           qsortfilterproxymodel \
           qsound \
           qaudiodeviceinfo \
           qaudioformat \
#           qaudiooutput \
#           qaudioinput \
           qspinbox \
           qsplitter \
           qsql \
           qsqldatabase \
           qsqlerror \
           qsqlfield \
#           qsqlquery \
           qsqlquerymodel \
           qsqlrecord \
           qsqlrelationaltablemodel \
           qsqltablemodel \
           qsqlthread \
           qsslcertificate \
           qsslcipher \
           qsslerror \
           qsslkey \
#           qsslsocket \
           qstackedlayout \
           qstackedwidget \
           qstandarditem \
#           qstandarditemmodel \
           qstate \
#           qstatemachine \
           qstatusbar \
           qstl \
           qstring \
           qstringbuilder1 \
           qstringbuilder2 \
           qstringbuilder3 \
           qstringbuilder4 \
           qstringmatcher \
           qstringlist \
           qstringlistmodel \
#           qstyle \
           qstyleoption \
#           qstylesheetstyle \
           qsvgdevice \
           qsvggenerator \
#           qsvgrenderer \
           qsyntaxhighlighter \
#           qsystemtrayicon \
           qtabbar \
#           qtableview \
           qtablewidget \
           qtabwidget \
           qtcpserver \
#           qtcpsocket \
           qtemporaryfile \
           qtessellator \
           qtextblock \
           qtextboundaryfinder \
           qtextbrowser \
#           #qtextcodec \
           qtextcursor \
           qtextdocument \
           qtextdocumentfragment \
           qtextdocumentlayout \
#           qtextedit \
           qtextformat \
#           qtextlayout \
           qtextlist \
           qtextobject \
           qtextscriptengine \
           qtextstream \
           qtexttable \
           qthread \
           qthreadonce \
           qthreadstorage \
           qtime \
           qtimeline \
           qtimer \
           qtmd5 \
#           qtoolbar \
           qtoolbox \
           qtoolbutton \
           qtooltip \
           qtranslator \
           qtransform \
           qtransformedscreen \
           qtreeview \
           qtreewidget \
           qtreewidgetitemiterator \
           qtwidgets \
           qudpsocket \
           qundogroup \
           qundostack \
#           qurl \
           quuid \
           qvariant \
           qvarlengtharray \
           qvector \
           qvideoframe \
           qvideosurfaceformat \
           qvectornd \
           qwaitcondition \
#           qwidget \
           qwidgetaction \
           qwindowsurface \
           qwineventnotifier \
           qwizard \
           qwmatrix \
           qworkspace \
           qwritelocker \
           qwsembedwidget \
           qwsinputmethod \
           qwswindowsystem \
           qx11info \
           qxml \
           qxmlinputsource \
           qxmlsimplereader \
           qxmlstream \
           selftests \
           symbols \
           qrand \
           utf8 \
           gestures
           
!wince*:SUBDIRS += $$Q3SUBDIRS

contains(QT_CONFIG, OdfWriter):SUBDIRS += qzip qtextodfwriter
mac: {
    SUBDIRS += macgui \
               macplist \
               qaccessibility_mac
}

embedded:!wince* {
    SUBDIRS += qcopchannel \
               qdirectpainter \
               qmultiscreen
}
!win32: {
#    SUBDIRS += qtextpiecetable
}

# Enable the tests specific to QtXmlPatterns. If you add a test, remember to
# update runQtXmlPatternsTests.sh too. Remember that this file, auto.pro, is
# not respected by some test system, they just have a script which loop over
# the folders.

#contains(QT_CONFIG, xmlpatterns) {
#SUBDIRS += checkxmlfiles                \
#           patternistexamplefiletree    \
#           patternistexamples           \
#           patternistheaders            \
#           qabstractmessagehandler      \
#           qabstracturiresolver         \
#           qabstractxmlforwarditerator  \
#           qabstractxmlnodemodel        \
#           qabstractxmlreceiver         \
#           qapplicationargumentparser   \
#           qautoptr                     \
#           qsimplexmlnodemodel          \
#           qsourcelocation              \
#           qxmlformatter                \
#           qxmlitem                     \
#           qxmlname                     \
#           qxmlnamepool                 \
#           qxmlnodemodelindex           \
#           qxmlquery                    \
#           qxmlresultitems              \
#           qxmlschema                   \
#           qxmlschemavalidator          \
#           qxmlserializer               \
#           xmlpatterns                  \
#           xmlpatternsdiagnosticsts     \
#           xmlpatternsschema            \
#           xmlpatternsschemats          \
#           xmlpatternsvalidator         \
#           xmlpatternsview              \
#           xmlpatternsxqts              \
#           xmlpatternsxslts

#xmlpatternsdiagnosticsts.depends = xmlpatternsxqts
#xmlpatternsview.depends = xmlpatternsxqts
#xmlpatternsxslts.depends = xmlpatternsxqts
#xmlpatternsschemats.depends = xmlpatternsxqts
#}

unix:!embedded:contains(QT_CONFIG, dbus):SUBDIRS += \
           qdbusabstractadaptor \
           qdbusabstractinterface \
           qdbusconnection \
           qdbusinterface \
           qdbuslocalcalls \
           qdbusmarshall \
           qdbusmetaobject \
           qdbusmetatype \
           qdbuspendingcall \
           qdbuspendingreply \
           qdbusperformance \
           qdbusreply \
           qdbusthreading \
           qdbusxmlparser

contains(QT_CONFIG, script): SUBDIRS += \
           qscriptable \
           qscriptclass \
#           qscriptcontext \
           qscriptcontextinfo \
           qscriptengine \
#           qscriptengineagent \
           qscriptextqobject \
           qscriptjstestsuite \
           qscriptv8testsuite \
           qscriptstring \
           qscriptvalue \
           qscriptvalueiterator
#           qscriptenginedebugger

#contains(QT_CONFIG, webkit): SUBDIRS += \
#           qwebframe \
#           qwebpage \
#           qwebhistoryinterface \
#           qwebelement \
#           qwebhistory
