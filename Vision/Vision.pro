
SOURCES += main.cpp \
    sightedobjects.cpp \
    framesholder.cpp \
    colormasks.cpp \
    vision.cpp

HEADERS += \
    sightedobjects.hpp \
    visionconstants.h \
    framesholder.hpp \
    ../hsvmask.h \
    hsvmask.h \
    colormasks.hpp \
    vision.hpp \
    sightedobject.h

CONFIG += link_pkgconfig
PKGCONFIG += opencv
