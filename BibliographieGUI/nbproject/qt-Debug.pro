# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = BibliographieGUI
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += BibliographieInterface.cpp JournalInterface.cpp OuvrageInterface.cpp SupprimerInterface.cpp main.cpp
HEADERS += BibliographieInterface.h JournalInterface.h OuvrageInterface.h SupprimerInterface.h
FORMS += BibliographieInterface.ui JournalInterface.ui OuvrageInterface.ui SupprimerInterface.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++-10
DEFINES += 
INCLUDEPATH += ../source 
LIBS += ../source/dist/Debug/GNU-Linux/libsource.a  
