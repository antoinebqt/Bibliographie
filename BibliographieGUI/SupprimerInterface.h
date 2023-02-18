/**
 * \file SupprimerInterface.h
 * \brief Fichier qui contient l'interface de la classe SupprimerInterface qui permet de
 * de supprimer des références.
 * \author Antoine BUQUET
 * \date 3 Décembre 2022
 */

#ifndef _SUPPRIMERINTERFACE_H
#define _SUPPRIMERINTERFACE_H

#include "ui_SupprimerInterface.h"

class SupprimerInterface : public QDialog
{
  Q_OBJECT
public:
  SupprimerInterface();
  virtual ~SupprimerInterface();

  QString reqIdentifiant() const;

private slots:
  void validerSuppression();

private:
  Ui::SupprimerInterface widget;
};

#endif /* _SUPPRIMERINTERFACE_H */
