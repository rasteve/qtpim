include(../auto.pri)

QT += contacts contacts-private jsondb jsondb-private

SOURCES += tst_qcontactjsondbengine.cpp \
           ../../../src/plugins/contacts/jsondb/qcontactjsondbenginefactory.cpp \
           ../../../src/plugins/contacts/jsondb/qcontactjsondbengine.cpp \
           ../../../src/plugins/contacts/jsondb/qcontactjsondbrequesthandler.cpp \
           ../../../src/plugins/contacts/jsondb/qcontactjsondbrequestmanager.cpp \
           ../../../src/plugins/contacts/jsondb/qcontactjsondbconverter.cpp \
           ../../../src/plugins/contacts/jsondb/qcontactjsondbstring.cpp \
           qcontactjsondbbackup.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

INCLUDEPATH += ../../../src/plugins/contacts/jsondb

HEADERS += \
    qcontactjsondbbackup.h \
           ../../../src/plugins/contacts/jsondb/qcontactjsondbenginefactory.h \
           ../../../src/plugins/contacts/jsondb/qcontactjsondbengine.h \
           ../../../src/plugins/contacts/jsondb/qcontactjsondbenginedata.h \
           ../../../src/plugins/contacts/jsondb/qcontactjsondbrequesthandler.h \
           ../../../src/plugins/contacts/jsondb/qcontactjsondbrequestmanager.h \
           ../../../src/plugins/contacts/jsondb/qcontactjsondbconverter.h \
           ../../../src/plugins/contacts/jsondb/qcontactjsondbstring.h
