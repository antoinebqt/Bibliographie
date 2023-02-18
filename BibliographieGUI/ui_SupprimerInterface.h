/********************************************************************************
** Form generated from reading UI file 'SupprimerInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERINTERFACE_H
#define UI_SUPPRIMERINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SupprimerInterface
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *identifiant;
    QPushButton *ok;

    void setupUi(QDialog *SupprimerInterface)
    {
        if (SupprimerInterface->objectName().isEmpty())
            SupprimerInterface->setObjectName(QString::fromUtf8("SupprimerInterface"));
        SupprimerInterface->resize(401, 90);
        gridLayoutWidget = new QWidget(SupprimerInterface);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 381, 71));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        identifiant = new QLineEdit(gridLayoutWidget);
        identifiant->setObjectName(QString::fromUtf8("identifiant"));

        gridLayout->addWidget(identifiant, 0, 1, 1, 1);

        ok = new QPushButton(gridLayoutWidget);
        ok->setObjectName(QString::fromUtf8("ok"));

        gridLayout->addWidget(ok, 1, 0, 1, 2);


        retranslateUi(SupprimerInterface);
        QObject::connect(ok, SIGNAL(clicked()), SupprimerInterface, SLOT(validerSuppression()));

        QMetaObject::connectSlotsByName(SupprimerInterface);
    } // setupUi

    void retranslateUi(QDialog *SupprimerInterface)
    {
        SupprimerInterface->setWindowTitle(QApplication::translate("SupprimerInterface", "Supprimer une r\303\251f\303\251rence", nullptr));
        label->setText(QApplication::translate("SupprimerInterface", "Identifiant", nullptr));
        ok->setText(QApplication::translate("SupprimerInterface", "Supprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupprimerInterface: public Ui_SupprimerInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERINTERFACE_H
