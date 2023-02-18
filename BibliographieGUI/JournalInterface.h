/**
 * \file JournalInterface.h
 * \brief Fichier qui contient l'interface de la classe JournalInterface qui permet de
 * d'ajouter un journal.
 * \author Antoine BUQUET
 * \date 3 Décembre 2022
 */

#ifndef _JOURNALINTERFACE_H
#define _JOURNALINTERFACE_H

#include "ui_JournalInterface.h"

class JournalInterface : public QDialog
{
  Q_OBJECT

public:
  JournalInterface();
  virtual ~JournalInterface();

  QString reqAuteurs() const;
  QString reqTitre() const;
  int reqAnnee() const;
  QString reqIdentifiant() const;
  QString reqNom() const;
  int reqVolume() const;
  int reqNumero() const;
  int reqPage() const;

private slots:
  void validerEnregistrement();

private:
  Ui::JournalInterface widget;
};

#endif /* _JOURNALINTERFACE_H */
