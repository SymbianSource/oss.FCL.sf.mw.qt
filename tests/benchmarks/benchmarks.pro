TEMPLATE = subdirs
SUBDIRS = containers-associative \
	qanimation \
	qbytearray \
	qfile_vs_qnetworkaccessmanager \
	qpainter \
	qtestlib-simple	events \
        qtext \
	qiodevice \
	qpixmap \
	blendbench \
	qstringlist \
	qmatrix4x4 \
	qnetworkreply \
	qobject \
	qrect \
	qregexp	\
	qregion \
	qvariant \
	qwidget	\
	qtwidgets \
	qapplication \
	qdir \
	qdiriterator \
	qgraphicsanchorlayout \
	qgraphicsitem \
	qgraphicswidget \
	qmetaobject \
	qpixmapcache \
	qquaternion \
	qscriptclass \
	qscriptengine \
	qscriptvalue \
	qstringbuilder \
	qstylesheetstyle \
	qsvgrenderer \
        qtcpserver \
	qtableview \
	qthreadstorage \
	qgraphicsview \
	containers-sequential \
	qfile \
	qgraphicsscene \
	qimagereader \
	qtemporaryfile \
	qtransform



contains(QT_CONFIG, opengl): SUBDIRS += opengl
