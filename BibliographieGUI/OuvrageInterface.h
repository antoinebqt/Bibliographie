/**
 * \file OuvrageInterface.h
 * \brief Fichier qui contient l'interface de la classe OuvrageInterface qui permet de
 * d'ajouter un ouvrage.
 * \author Antoine BUQUET
 * \date 3 Décembre 2022
 */

#ifndef _OUVRAGEINTERFACE_H
#define _OUVRAGEINTERFACE_H

#include "ui_OuvrageInterface.h"

class OuvrageInterface : public QDialog
{
  Q_OBJECT
public:
  OuvrageInterface();
  virtual ~OuvrageInterface();

  QString reqAuteurs() const;
  QString reqTitre() const;
  int reqAnnee() const;
  QString reqIdentifiant() const;
  QString reqEditeur() const;
  QString reqVille() const;

private slots:
  void validerEnregistrement();

private:
  Ui::OuvrageInterface widget;
};

#endif /* _OUVRAGEINTERFACE_H */
