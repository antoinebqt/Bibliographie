/********************************************************************************
** Form generated from reading UI file 'OuvrageInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUVRAGEINTERFACE_H
#define UI_OUVRAGEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OuvrageInterface
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
    QLineEdit *editeur;
    QLabel *label_6;
    QLineEdit *ville;
    QPushButton *ok;

    void setupUi(QDialog *OuvrageInterface)
    {
        if (OuvrageInterface->objectName().isEmpty())
            OuvrageInterface->setObjectName(QString::fromUtf8("OuvrageInterface"));
        OuvrageInterface->resize(400, 260);
        formLayoutWidget = new QWidget(OuvrageInterface);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 381, 201));
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
        annee->setMaximum(999999);

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

        editeur = new QLineEdit(formLayoutWidget);
        editeur->setObjectName(QString::fromUtf8("editeur"));

        formLayout->setWidget(4, QFormLayout::FieldRole, editeur);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        ville = new QLineEdit(formLayoutWidget);
        ville->setObjectName(QString::fromUtf8("ville"));

        formLayout->setWidget(5, QFormLayout::FieldRole, ville);

        ok = new QPushButton(OuvrageInterface);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(10, 220, 379, 28));

        retranslateUi(OuvrageInterface);
        QObject::connect(ok, SIGNAL(clicked()), OuvrageInterface, SLOT(validerEnregistrement()));

        QMetaObject::connectSlotsByName(OuvrageInterface);
    } // setupUi

    void retranslateUi(QDialog *OuvrageInterface)
    {
        OuvrageInterface->setWindowTitle(QApplication::translate("OuvrageInterface", "Ajouter un ouvrage", nullptr));
        label->setText(QApplication::translate("OuvrageInterface", "Auteurs", nullptr));
        label_2->setText(QApplication::translate("OuvrageInterface", "Titre", nullptr));
        label_3->setText(QApplication::translate("OuvrageInterface", "Ann\303\251e", nullptr));
        label_4->setText(QApplication::translate("OuvrageInterface", "Code ISBN", nullptr));
        label_5->setText(QApplication::translate("OuvrageInterface", "Editeur", nullptr));
        label_6->setText(QApplication::translate("OuvrageInterface", "Ville", nullptr));
        ok->setText(QApplication::translate("OuvrageInterface", "Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OuvrageInterface: public Ui_OuvrageInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUVRAGEINTERFACE_H
