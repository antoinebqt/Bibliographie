/********************************************************************************
** Form generated from reading UI file 'BibliographieInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIBLIOGRAPHIEINTERFACE_H
#define UI_BIBLIOGRAPHIEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BibliographieInterface
{
public:
    QAction *actionAjouterJournal;
    QAction *actionAjouterOuvrage;
    QAction *actionSupprimer;
    QAction *actionQuitter;
    QWidget *centralwidget;
    QTextEdit *affichage;
    QMenuBar *menubar;
    QMenu *menuOperation;
    QMenu *menuAjouter_une_reference;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BibliographieInterface)
    {
        if (BibliographieInterface->objectName().isEmpty())
            BibliographieInterface->setObjectName(QString::fromUtf8("BibliographieInterface"));
        BibliographieInterface->resize(800, 800);
        actionAjouterJournal = new QAction(BibliographieInterface);
        actionAjouterJournal->setObjectName(QString::fromUtf8("actionAjouterJournal"));
        actionAjouterOuvrage = new QAction(BibliographieInterface);
        actionAjouterOuvrage->setObjectName(QString::fromUtf8("actionAjouterOuvrage"));
        actionSupprimer = new QAction(BibliographieInterface);
        actionSupprimer->setObjectName(QString::fromUtf8("actionSupprimer"));
        actionQuitter = new QAction(BibliographieInterface);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralwidget = new QWidget(BibliographieInterface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        affichage = new QTextEdit(centralwidget);
        affichage->setObjectName(QString::fromUtf8("affichage"));
        affichage->setGeometry(QRect(0, 0, 800, 800));
        BibliographieInterface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BibliographieInterface);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuOperation = new QMenu(menubar);
        menuOperation->setObjectName(QString::fromUtf8("menuOperation"));
        menuAjouter_une_reference = new QMenu(menuOperation);
        menuAjouter_une_reference->setObjectName(QString::fromUtf8("menuAjouter_une_reference"));
        BibliographieInterface->setMenuBar(menubar);
        statusbar = new QStatusBar(BibliographieInterface);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BibliographieInterface->setStatusBar(statusbar);

        menubar->addAction(menuOperation->menuAction());
        menuOperation->addAction(menuAjouter_une_reference->menuAction());
        menuOperation->addAction(actionSupprimer);
        menuOperation->addAction(actionQuitter);
        menuAjouter_une_reference->addAction(actionAjouterJournal);
        menuAjouter_une_reference->addAction(actionAjouterOuvrage);

        retranslateUi(BibliographieInterface);
        QObject::connect(actionQuitter, SIGNAL(triggered()), BibliographieInterface, SLOT(close()));
        QObject::connect(actionAjouterJournal, SIGNAL(triggered()), BibliographieInterface, SLOT(dialogJournal()));
        QObject::connect(actionSupprimer, SIGNAL(triggered()), BibliographieInterface, SLOT(dialogSupprimer()));
        QObject::connect(actionAjouterOuvrage, SIGNAL(triggered()), BibliographieInterface, SLOT(dialogOuvrage()));

        QMetaObject::connectSlotsByName(BibliographieInterface);
    } // setupUi

    void retranslateUi(QMainWindow *BibliographieInterface)
    {
        BibliographieInterface->setWindowTitle(QApplication::translate("BibliographieInterface", "TP4 - Bibliographie", nullptr));
        actionAjouterJournal->setText(QApplication::translate("BibliographieInterface", "Ajouter un journal", nullptr));
        actionAjouterOuvrage->setText(QApplication::translate("BibliographieInterface", "Ajouter un ouvrage", nullptr));
        actionSupprimer->setText(QApplication::translate("BibliographieInterface", "Supprimer une reference", nullptr));
        actionQuitter->setText(QApplication::translate("BibliographieInterface", "Quitter", nullptr));
        menuOperation->setTitle(QApplication::translate("BibliographieInterface", "Operations", nullptr));
        menuAjouter_une_reference->setTitle(QApplication::translate("BibliographieInterface", "Ajouter une r\303\251f\303\251rence", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BibliographieInterface: public Ui_BibliographieInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIBLIOGRAPHIEINTERFACE_H
