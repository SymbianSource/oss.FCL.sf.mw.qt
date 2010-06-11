TEMPLATE = subdirs
SUBDIRS = \
	qtp_addressbook \
	qtp_analogclock \
	qtp_animatedtiles \
	qtp_collidingmice \
	qtp_masterdetail \
	qtp_qftp \
	qtp_raycasting \
	qtp_svgviewer \
	qtp_wiggly

contains(QT_CONFIG, webkit): SUBDIRS += qtp_anomaly
contains(QT_CONFIG, openvg): SUBDIRS += qtp_star

