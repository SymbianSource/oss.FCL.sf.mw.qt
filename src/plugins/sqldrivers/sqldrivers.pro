TEMPLATE = subdirs

contains(sql-plugins, psql)	: SUBDIRS += psql
contains(sql-plugins, mysql)	: SUBDIRS += mysql
contains(sql-plugins, odbc)	: SUBDIRS += odbc
contains(sql-plugins, tds)	: SUBDIRS += tds
contains(sql-plugins, oci)	: SUBDIRS += oci
contains(sql-plugins, db2)	: SUBDIRS += db2
contains(sql-plugins, sqlite)	: SUBDIRS += sqlite
contains(sql-plugins, sqlite2)	: SUBDIRS += sqlite2
contains(sql-plugins, ibase)	: SUBDIRS += ibase

# :QTP: Version check not working on TB9.2 and later, don't export SQLLite. Fix needed for working version check
# symbian:contains(CONFIG, system-sqlite): SUBDIRS += sqlite_symbian

