/********************************************************************************
** Form generated from reading UI file 'JournalInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOURNALINTERFACE_H
#define UI_JOURNALINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JournalInterface
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *auteurs;
    QLabel *label_2;
    QLineEdit *titre;
    QLabel *label_3;
    QSpinBox *annee;
    QLabel *label_4;
    QLineEdit *identifiant;
    QLabel *label_5;
    QLineEdit *nom;
    QLabel *label_6;
    QSpinBox *volume;
    QLabel *label_7;
    QSpinBox *numero;
    QLabel *label_8;
    QSpinBox *page;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *ok;

    void setupUi(QDialog *JournalInterface)
    {
        if (JournalInterface->objectName().isEmpty())
            JournalInterface->setObjectName(QString::fromUtf8("JournalInterface"));
        JournalInterface->resize(425, 324);
        formLayoutWidget = new QWidget(JournalInterface);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(11, 10, 401, 261));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        auteurs = new QLineEdit(formLayoutWidget);
        auteurs->setObjectName(QString::fromUtf8("auteurs"));

        formLayout->setWidget(0, QFormLayout::FieldRole, auteurs);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        titre = new QLineEdit(formLayoutWidget);
        titre->setObjectName(QString::fromUtf8("titre"));

        formLayout->setWidget(1, QFormLayout::FieldRole, titre);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        annee = new QSpinBox(formLayoutWidget);
        annee->setObjectName(QString::fromUtf8("annee"));
        annee->setMaximum(9999999);

        formLayout->setWidget(2, QFormLayout::FieldRole, annee);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        identifiant = new QLineEdit(formLayoutWidget);
        identifiant->setObjectName(QString::fromUtf8("identifiant"));

        formLayout->setWidget(3, QFormLayout::FieldRole, identifiant);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        nom = new QLineEdit(formLayoutWidget);
        nom->setObjectName(QString::fromUtf8("nom"));

        formLayout->setWidget(4, QFormLayout::FieldRole, nom);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        volume = new QSpinBox(formLayoutWidget);
        volume->setObjectName(QString::fromUtf8("volume"));
        volume->setMaximum(9999999);

        formLayout->setWidget(5, QFormLayout::FieldRole, volume);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        numero = new QSpinBox(formLayoutWidget);
        numero->setObjectName(QString::fromUtf8("numero"));
        numero->setMaximum(9999999);

        formLayout->setWidget(6, QFormLayout::FieldRole, numero);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        page = new QSpinBox(formLayoutWidget);
        page->setObjectName(QString::fromUtf8("page"));
        page->setMaximum(9999999);

        formLayout->setWidget(7, QFormLayout::FieldRole, page);

        verticalLayoutWidget = new QWidget(JournalInterface);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 280, 401, 31));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ok = new QPushButton(verticalLayoutWidget);
        ok->setObjectName(QString::fromUtf8("ok"));

        verticalLayout->addWidget(ok);


        retranslateUi(JournalInterface);
        QObject::connect(ok, SIGNAL(clicked()), JournalInterface, SLOT(validerEnregistrement()));

        QMetaObject::connectSlotsByName(JournalInterface);
    } // setupUi

    void retranslateUi(QDialog *JournalInterface)
    {
        JournalInterface->setWindowTitle(QApplication::translate("JournalInterface", "Ajouter un journal", nullptr));
        label->setText(QApplication::translate("JournalInterface", "Auteurs", nullptr));
        label_2->setText(QApplication::translate("JournalInterface", "Titre", nullptr));
        label_3->setText(QApplication::translate("JournalInterface", "Ann\303\251e", nullptr));
        label_4->setText(QApplication::translate("JournalInterface", "Code ISSN", nullptr));
        identifiant->setText(QString());
        label_5->setText(QApplication::translate("JournalInterface", "Nom", nullptr));
        label_6->setText(QApplication::translate("JournalInterface", "Volume", nullptr));
        label_7->setText(QApplication::translate("JournalInterface", "Num\303\251ro", nullptr));
        label_8->setText(QApplication::translate("JournalInterface", "Page", nullptr));
        ok->setText(QApplication::translate("JournalInterface", "Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JournalInterface: public Ui_JournalInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOURNALINTERFACE_H
