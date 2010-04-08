# The tests in this .pro file _MUST_ use QtCore and QtNetwork only
# (i.e. QT=core network).
# The test system is allowed to run these tests before the rest of Qt has
# been compiled.
TEMPLATE=subdirs
SUBDIRS=\
    networkselftest \
    qabstractnetworkcache \
    qabstractsocket \
    qeventloop \
    qftp \
    qhostaddress \
    qhostinfo \
    qhttp \
    qhttpnetworkconnection \
    qhttpnetworkreply \
    qhttpsocketengine \
    qnativesocketengine \
    qnetworkaddressentry \
    qnetworkcookie \
    qnetworkcookiejar \
    qnetworkinterface \
    qnetworkproxy \
    qnetworkrequest \
    qobjectperformance \
    qsocketnotifier \
    qsocks5socketengine \
    qsslcertificate \
    qsslcipher \
    qsslerror \
    qsslkey \
    qsslsocket \

contains(QT_CONFIG, private_tests): SUBDIRS -= \
    qhttpnetworkconnection \
    qhttpnetworkreply \
    qnativesocketengine \
    qsocketnotifier \
    qsocks5socketengine \

