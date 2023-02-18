/**
 * \file SupprimerInterface.h
 * \brief Fichier qui contient l'implémentation de la classe SupprimerInterface qui permet de
 * de supprimer des références.
 * \author Antoine BUQUET
 * \date 3 Décembre 2022
 */

#include <QApplication>
#include "BibliographieInterface.h"


int main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app(argc, argv);

  // create and show your widgets here
  BibliographieInterface fenetre;
  fenetre.show();

  return app.exec();
}
