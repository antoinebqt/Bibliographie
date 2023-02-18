/**
 * \file BibliographieTesteur.cpp
 * \brief Test unitaire de la classe Bibliographie
 * \author Antoine BUQUET
 * \date 2 Novembre 2022
 */

#include <gtest/gtest.h>
#include <iostream>
#include "Bibliographie.h"
#include "Ouvrage.h"

using namespace std;
using namespace biblio;


/**
 * \test Test du constructeur
 * 		Cas valides: Creation d’un objet Bibliographie et verification de l’assignation de l'attribut
 * 		Cas invalides:
 * 			nom de la bibliographie vide
 */
TEST (Bibliographie, Constructeur)
{
  Bibliographie uneBibliographie("Ma bibliographie");
  ASSERT_EQ("Ma bibliographie", uneBibliographie.reqNomBiblio()) << "L'attribut passé en paramètre n'a pas été correctement assigné";
}

//Cas invalide


TEST (Bibliographie, ConstructeurInvalideNomBiblio)
{
  ASSERT_THROW (Bibliographie uneBibliographie(""), PreconditionException) << "L'attribut ne doit pas être vide";
}

/**
 * \brief Creation d’une fixture a utiliser pour les methodes public de la classe Bibliographie
 */
class UneBibliographie : public ::testing::Test
{

public:


  UneBibliographie () :
  f_bibliographie ("Ma bibliographie") { }
  Bibliographie f_bibliographie;
} ;


/**
 * \test Test de la méthode reqNomBiblio()
 * 		Cas valide: vérifier le retour du nom de la bibliographie
 * 		Cas invalide: aucun
 */
TEST_F (UneBibliographie, reqNomBiblio)
{
  ASSERT_EQ ("Ma bibliographie", f_bibliographie.reqNomBiblio())  << "L'accesseur ne renvoi pas la bonne valeur";
}


/**
 * \test Test du constructeur par copie
 *              Cas valide: la copie possède les mêmes attributs que l'originial
 *              Cas invalide: aucun
 */
TEST_F (UneBibliographie, constructeurCopie)
{
  Bibliographie uneCopie (f_bibliographie);
  ASSERT_EQ("Ma bibliographie", uneCopie.reqNomBiblio()) << "L'accesseur ne renvoi pas la bonne valeur";
  ASSERT_EQ(f_bibliographie.reqBibliographieFormate(), uneCopie.reqBibliographieFormate())  << "L'objet formaté ne correspond pas a ce qui est attendu";
}


/**
 * \test Test de la méthode ajouterReference();
 *        Cas valides: la référence n'est pas déjà présente donc elle est ajoutée
 *        Cas invalides: la référence est déjà présente donc elle n'est pas ajutée
 */
TEST_F (UneBibliographie, ajouterReference)
{
  Ouvrage ouvrage("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "Springer", "New York");

  //Ajout de l'objet dans la liste de références de la bibliographie
  Reference& referenceOuvrage = ouvrage;
  f_bibliographie.ajouterReference(referenceOuvrage);

  std::ostringstream os;
  os << "Ma bibliographie" << endl << "===============================" << endl;
  os << "[1] Homayoon Beigi. Fundamentals of Speaker Recognition. New York : Springer, 2011. ISBN 978-0-387-77591-3.\n";

  ASSERT_EQ(os.str(), f_bibliographie.reqBibliographieFormate()) << "L'objet formaté ne correspond pas a ce qui est attendu";
}


TEST_F (UneBibliographie, ajouterReferenceDejaPresente)
{
  Ouvrage ouvrageDejaPresent("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "Springer", "New York");

  //Ajout de l'objet dans la liste de références de la bibliographie
  Reference& referenceOuvrage = ouvrageDejaPresent;
  f_bibliographie.ajouterReference(referenceOuvrage);

  std::ostringstream os;
  os << "Ma bibliographie" << endl << "===============================" << endl;
  os << "[1] Homayoon Beigi. Fundamentals of Speaker Recognition. New York : Springer, 2011. ISBN 978-0-387-77591-3.\n";

  ASSERT_EQ(os.str(), f_bibliographie.reqBibliographieFormate()) << "L'objet formaté ne correspond pas a ce qui est attendu";
}


/**
 * \test Test de l'operator d'assignation =
 *          Cas valide: la bibliographie courante est remplacer par l'autre bibliographie
 *          Cas invalide: aucun
 */
TEST_F (UneBibliographie, operatorAssignation)
{
  Bibliographie uneAutreBibliographie ("Une autre bibliographie");
  uneAutreBibliographie = f_bibliographie;

  ASSERT_EQ(f_bibliographie.reqNomBiblio(), uneAutreBibliographie.reqNomBiblio());
}
