/**
 * \file JournalInterface.h
 * \brief Fichier qui contient l'implémentation de la classe JournalInterface qui permet de
 * d'ajouter un journal.
 * \author Antoine BUQUET
 * \date 3 Décembre 2022
 */

#include "JournalInterface.h"
#include "validationFormat.h"
#include <QMessageBox>
#include <ctime>

using namespace util;


JournalInterface::JournalInterface ()
{
  widget.setupUi (this);

  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t);
  int anneeMax = 1900 + now->tm_year;
  widget.annee->setMaximum(anneeMax);
}


JournalInterface::~JournalInterface () { }


QString JournalInterface::reqAuteurs () const
{
  return widget.auteurs->text();
}


QString JournalInterface::reqTitre () const
{
  return widget.titre->text();
}


int JournalInterface::reqAnnee () const
{
  return widget.annee->value();
}


QString JournalInterface::reqIdentifiant () const
{
  return widget.identifiant->text();
}


QString JournalInterface::reqNom () const
{
  return widget.nom->text();
}


int JournalInterface::reqVolume () const
{
  return widget.volume->value();
}


int JournalInterface::reqNumero () const
{
  return widget.numero->value();
}


int JournalInterface::reqPage () const
{
  return widget.page->value();
}


void JournalInterface::validerEnregistrement ()
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
  if (!validerCodeIssn(reqIdentifiant().toStdString()))
    {
      QString message("Le code ISSN n'est pas dans un format valide.");
      QMessageBox::information(this, "ERREUR", message);
      return;
    }

  if (reqNom().isEmpty())
    {
      QString message("Le nom du journal ne doit pas être vide.");
      QMessageBox::information(this, "ERREUR", message);
      return;
    }
  if (reqVolume() <= 0)
    {
      QString message("Le volume doit être positif.");
      QMessageBox::information(this, "ERREUR", message);
      return;
    }
  if (reqNumero() <= 0)
    {
      QString message("Le numéro doit être positif.");
      QMessageBox::information(this, "ERREUR", message);
      return;
    }
  if (reqPage() <= 0)
    {
      QString message("La page doit être positif.");
      QMessageBox::information(this, "ERREUR", message);
      return;
    }

  accept();
}
