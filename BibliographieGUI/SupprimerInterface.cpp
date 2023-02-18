/**
 * \file SupprimerInterface.h
 * \brief Fichier qui contient l'implémentation de la classe SupprimerInterface qui permet de
 * de supprimer des références.
 * \author Antoine BUQUET
 * \date 3 Décembre 2022
 */

#include "SupprimerInterface.h"
#include "validationFormat.h"
#include <QMessageBox>

using namespace std;
using namespace util;


SupprimerInterface::SupprimerInterface ()
{
  widget.setupUi(this);
}


SupprimerInterface::~SupprimerInterface () { }


QString SupprimerInterface::reqIdentifiant () const
{
  return widget.identifiant->text();
}


void SupprimerInterface::validerSuppression ()
{
  string identifiant = reqIdentifiant().toStdString();
  if (identifiant.substr(0, 4) == "ISSN")
    {
      if (!validerCodeIssn(identifiant))
        {
          QString message("Le code ISSN n'est pas dans un format valide.");
          QMessageBox::information(this, "ERREUR", message);
          return;
        }
      else
        {
          QMessageBox::StandardButton reply;
          reply = QMessageBox::question(this, "Supprimer un journal", "Etes vous sur de vouloir supprimer ce journal de la bibliographie ?", QMessageBox::Yes | QMessageBox::No);
          if (reply == QMessageBox::Yes)
            {
              accept();
            }
        }
    }
  else if (identifiant.substr(0, 4) == "ISBN")
    {
      if (!validerCodeIsbn(identifiant))
        {
          QString message("Le code ISBN n'est pas dans un format valide.");
          QMessageBox::information(this, "ERREUR", message);
          return;
        }
      else
        {
          QMessageBox::StandardButton reply;
          reply = QMessageBox::question(this, "Supprimer un ouvrage", "Etes vous sur de vouloir supprimer cet ouvrage de la bibliographie ?", QMessageBox::Yes | QMessageBox::No);
          if (reply == QMessageBox::Yes)
            {
              accept();
            }
        }
    }
  else
    {
      QString message("L'identifiant n'est pas dans un format valide.");
      QMessageBox::information(this, "ERREUR", message);
      return;
    }
}
