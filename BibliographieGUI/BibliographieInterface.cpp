/**
 * \file BibliographieInterface.h
 * \brief Fichier qui contient l'implémentation de la classe BibliographieInterface qui permet de
 * d'afficher, d'ajouter et de supprimer des références.
 * \author Antoine BUQUET
 * \date 3 Décembre 2022
 */

#include "BibliographieInterface.h"
#include "JournalInterface.h"
#include "SupprimerInterface.h"
#include "OuvrageInterface.h"
#include "Journal.h"
#include "Ouvrage.h"
#include "Reference.h"
#include "ReferenceException.h"
#include <QMessageBox>

using namespace biblio;
using namespace std;


BibliographieInterface::BibliographieInterface () :
m_bibliographie ("Ma Bibliographie")
{
  widget.setupUi(this);
  widget.affichage->setText(reqBibliographieFormate().c_str());
}


BibliographieInterface::~BibliographieInterface ()
{
  m_bibliographie.~Bibliographie();
}


void BibliographieInterface::ajouterJournal (const string& p_auteurs, const string& p_titre,
                                             const unsigned int p_annee, const string& p_identifiant,
                                             const string& p_nom, const unsigned int p_volume,
                                             const unsigned int p_numero, const unsigned int p_page)
{
  Journal journal(p_auteurs, p_titre, p_annee, p_identifiant, p_nom, p_volume, p_numero, p_page);
  try
    {
      m_bibliographie.ajouterReference(journal);
    }
  catch (const ReferenceDejaPresenteException& erreur)
    {
      QString message(erreur.what());
      QMessageBox::information(this, "ERREUR", message);
      return;
    }

}


void BibliographieInterface::ajouterOuvrage (const string& p_auteurs, const string& p_titre,
                                             int p_annee, const string& p_identifiant,
                                             const string& p_editeur, const string& p_ville)
{
  Ouvrage ouvrage(p_auteurs, p_titre, p_annee, p_identifiant, p_editeur, p_ville);
  try
    {
      m_bibliographie.ajouterReference(ouvrage);
    }
  catch (const ReferenceDejaPresenteException& erreur)
    {
      QString message(erreur.what());
      QMessageBox::information(this, "ERREUR", message);
      return;
    }
}


void BibliographieInterface::supprimerReference (const string& p_identifiant)
{
  try
    {
      m_bibliographie.supprimerReference(p_identifiant);
    }
  catch (const ReferenceAbsenteException& erreur)
    {
      QString message(erreur.what());
      QMessageBox::information(this, "ERREUR", message);
      return;
    }

}


string BibliographieInterface::reqBibliographieFormate () const
{
  return m_bibliographie.reqBibliographieFormate();
}


void BibliographieInterface::dialogJournal ()
{
  JournalInterface journalInterface;
  if (journalInterface.exec())
    {
      ajouterJournal(journalInterface.reqAuteurs().toStdString(),
                     journalInterface.reqTitre().toStdString(),
                     journalInterface.reqAnnee(),
                     journalInterface.reqIdentifiant().toStdString(),
                     journalInterface.reqNom().toStdString(),
                     journalInterface.reqVolume(),
                     journalInterface.reqNumero(),
                     journalInterface.reqPage()
                     );
      widget.affichage->setText(reqBibliographieFormate().c_str());
    }
}


void BibliographieInterface::dialogOuvrage ()
{
  OuvrageInterface ouvrageInterface;
  if (ouvrageInterface.exec())
    {
      ajouterOuvrage(ouvrageInterface.reqAuteurs().toStdString(),
                     ouvrageInterface.reqTitre().toStdString(),
                     ouvrageInterface.reqAnnee(),
                     ouvrageInterface.reqIdentifiant().toStdString(),
                     ouvrageInterface.reqEditeur().toStdString(),
                     ouvrageInterface.reqVille().toStdString()
                     );
      widget.affichage->setText(reqBibliographieFormate().c_str());
    }
}


void BibliographieInterface::dialogSupprimer ()
{
  SupprimerInterface supprimerInterface;
  if (supprimerInterface.exec())
    {
      supprimerReference(supprimerInterface.reqIdentifiant().toStdString());
    }
  widget.affichage->setText(reqBibliographieFormate().c_str());
}