#-------------------------------------------------
#
# Project created by QtCreator 2011-06-05T20:41:16
#
#-------------------------------------------------

QT       += core gui sql

TARGET = qtaximetro
TEMPLATE = app

RC_FILE = src/recursos/qmoviltours.rc


SOURCES += src/main.cpp \
    src/datos/conexionbd.cpp \
    src/logica/empresa.cpp \
    src/logica/auto.cpp \
    src/logica/servicio.cpp \
    src/interfaz/qservice.cpp \
    src/interfaz/mainwindow.cpp \
    src/interfaz/qregistraautos.cpp \
    src/interfaz/qreportes.cpp \
    src/interfaz/qaboutme.cpp \
    src/interfaz/qmantenimiento.cpp \
    src/interfaz/qmautos.cpp \
    src/interfaz/qmservicio.cpp \
    src/interfaz/qtotalrecaudado.cpp

HEADERS  += \
    src/datos/conexionbd.hpp \
    src/logica/empresa.h \
    src/logica/auto.h \
    src/logica/servicio.h \
    src/logica/defines.hpp \
    src/interfaz/qservice.h \
    src/interfaz/mainwindow.h \
    src/interfaz/qregistraautos.h \
    src/interfaz/qreportes.h \
    src/interfaz/qaboutme.hpp \
    src/interfaz/qmantenimiento.h \
    src/interfaz/qmautos.h \
    src/interfaz/qmservicio.h \
    src/interfaz/qtotalrecaudado.hpp

FORMS    += \
    src/interfaz/ui/qservice.ui \
    src/interfaz/ui/mainwindow.ui \
    src/interfaz/ui/qregistraautos.ui \
    src/interfaz/ui/qreportes.ui \
    src/interfaz/ui/qaboutme.ui \
    src/interfaz/ui/qtotalrecaudado.ui

RESOURCES += \
    src/recursos/resources.qrc

INCLUDEPATH += src/datos \
    src/interfaz \
    src/logica \
    src/recursos

win32 {
    CONFIG += release
        #debug \
        #warn_on
    DESTDIR = bin/windows

    MAKEFILE = Makefile.win
    BUILDDIR = build/windows
    MOC_DIR = $$BUILDDIR/moc
    UI_DIR = $$BUILDDIR/ui
    OBJECTS_DIR = $$BUILDDIR/obj
    RCC_DIR = $$BUILDDIR/rcc
}

unix {
    CONFIG += debug \
        warn_on
    CONFIG -= release
    DESTDIR = bin/unix

    #MAKEFILE = Makefile.unix
    BUILDDIR = build/unix
    MOC_DIR = $$BUILDDIR/moc
    UI_DIR = $$BUILDDIR/ui
    OBJECTS_DIR = $$BUILDDIR/obj
    RCC_DIR = $$BUILDDIR/rcc
}

OTHER_FILES += \
    COPYING.txt \
    AUTHORS.txt \
    README \
    src/recursos/script_sql/bd-movil_tsql.sql \
    src/recursos/basedatos_sqlite/bdmovil.sqlite


