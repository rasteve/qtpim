include(../../auto.pri)

QMAKE_LIBS += -Wl,-rpath,$${QT.versit.libs}

QT += contacts versit

SOURCES += tst_qversitcontactplugins.cpp

#symbian: {
#    TARGET.CAPABILITY = ALL \
#        -TCB
#    LIBS += -lws32 \
#        -lbafl
#}
