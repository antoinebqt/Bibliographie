/**
 * \file OuvrageInterface.h
 * \brief Fichier qui contient l'implémentation de la classe OuvrageInterface qui permet de
 * d'ajouter un ouvrage.
 * \author Antoine BUQUET
 * \date 3 Décembre 2022
 */

#include "OuvrageInterface.h"
#include "validationFormat.h"
#include <QMessageBox>

using namespace util;


OuvrageInterface::OuvrageInterface ()
{
  widget.setupUi(this);

  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t);
  int anneeMax = 1900 + now->tm_year;
  widget.annee->setMaximum(anneeMax);
}


OuvrageInterface::~OuvrageInterface () { }


QString OuvrageInterface::reqAuteurs () const
{
  return widget.auteurs->text();
}


QString OuvrageInterface::reqTitre () const
{
  return widget.titre->text();
}


int OuvrageInterface::reqAnnee () const
{
  return widget.annee->value();
}


QString OuvrageInterface::reqIdentifiant () const
{
  return widget.identifiant->text();
}


QString OuvrageInterface::reqEditeur () const
{
  return widget.editeur->text();
}


QString OuvrageInterface::reqVille () const
{
  return widget.ville->text();
}


void OuvrageInterface::validerEnregistrement ()
{
  if (!validerFormatNom(reqAuteurs().toStdString()))
    {
      QString message("Le nom de l'auteur n'est pas dans un format valide.");
      QMessageBox::information(this, "ERREUR", message);
      return;
    }
  if (reqTitre().isEmpty())
    {
      QString message("Le titre de la référence ne peut pas être vide.");
      QMessageBox::information(this, "ERREUR", message);
      return;
    }
  if (reqAnnee() <= 0)
    {
      QString message("L'année de création doit être positif.");
      QMessageBox::information(this, "ERREUR", message);
      return;
    }
  if (!validerCodeIsbn(reqIdentifiant().toStdString()))
    {
      QString message("Le code ISBN n'est pas dans un format valide.");
      QMessageBox::information(this, "ERREUR", message);
      return;
    }

  if (!validerFormatNom(reqEditeur().toStdString()))
    {
      QString message("Le nom de l'éditeur n'est pas dans un format valide.");
      QMessageBox::information(this, "ERREUR", message);
      return;
    }

  if (!validerFormatNom(reqVille().toStdString()))
    {
      QString message("Le nom de la ville n'est pas dans un format valide.");
      QMessageBox::information(this, "ERREUR", message);
      return;
    }

  accept();
}
