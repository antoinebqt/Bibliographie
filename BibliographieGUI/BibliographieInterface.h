/**
 * \file BibliographieInterface.h
 * \brief Fichier qui contient l'interface de la classe BibliographieInterface qui permet de
 * d'afficher, d'ajouter et de supprimer des références.
 * \author Antoine BUQUET
 * \date 3 Décembre 2022
 */

#ifndef _BIBLIOGRAPHIEINTERFACE_H
#define _BIBLIOGRAPHIEINTERFACE_H

#include "ui_BibliographieInterface.h"
#include "Bibliographie.h"

class BibliographieInterface : public QMainWindow
{
  Q_OBJECT

public:
  BibliographieInterface();
  virtual ~BibliographieInterface();

  void ajouterJournal(const std::string& p_auteurs, const std::string& p_titre,
                      const unsigned int p_annee, const std::string& p_identifiant,
                      const std::string& p_nom, const unsigned int p_volume,
                      const unsigned int p_numero, const unsigned int p_page);

  void ajouterOuvrage(const std::string& p_auteurs, const std::string& p_titre,
                      int p_annee, const std::string& p_identifiant,
                      const std::string& p_editeur, const std::string& p_ville);

  void supprimerReference(const std::string& p_identifiant);

  std::string reqBibliographieFormate() const;

private slots:
  void dialogJournal();
  void dialogOuvrage();
  void dialogSupprimer();

private:
  Ui::BibliographieInterface widget;
  biblio::Bibliographie m_bibliographie;
};

#endif /* _BIBLIOGRAPHIEINTERFACE_H */
