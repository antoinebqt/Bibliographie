/**
 * \file ReferenceTesteur.cpp
 * \brief Test unitaire de la classe de base Reference
 * \author Antoine BUQUET
 * \date 2 Novembre 2022
 */

#include <gtest/gtest.h>
#include <iostream>
#include "Reference.h"

using namespace std;
using namespace biblio;

/**
 * \class ReferenceDeTest
 * \brief Classe de test permettant de tester la classe abstraite Reference
 */
class ReferenceDeTest : public Reference
{

public:


  ReferenceDeTest (const string& p_auteurs, const string& p_titre,
                   int p_annee, const string& p_identifiant) :
  Reference (p_auteurs, p_titre, p_annee, p_identifiant) { };


  virtual const string reqReferenceFormate () const
  {
    return Reference::reqReferenceFormate ();
  }


  virtual Reference* clone () const
  {
    return nullptr;
  }

} ;


/**
 * \test Test du constructeur
 * 		Cas valides: Creation d’un objet Reference et verification de l’assignation de tous les attributs
 * 		Cas invalides:
 * 			nom des auteurs invalide
 * 			titre de la référence vide
 * 			année <= 0
 *                      code identifiant invalide
 */
TEST (Reference, Constructeur)
{
  ReferenceDeTest uneReference ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3");
  ASSERT_EQ("Homayoon Beigi", uneReference.reqAuteurs()) << "L'attribut passé en paramètre n'a pas été correctement assigné";
  ASSERT_EQ("Fundamentals of Speaker Recognition", uneReference.reqTitre()) << "L'attribut passé en paramètre n'a pas été correctement assigné";
  ASSERT_EQ(2011, uneReference.reqAnnee()) << "L'attribut passé en paramètre n'a pas été correctement assigné";
  ASSERT_EQ("ISBN 978-0-387-77591-3", uneReference.reqIdentifiant()) << "L'attribut passé en paramètre n'a pas été correctement assigné";
}

//Cas invalide


TEST (Reference, ConstructeurInvalideNomDesAuteurs)
{
  ASSERT_THROW (ReferenceDeTest uneReference("", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3"), PreconditionException) << "L'attribut ne respect pas le bon format";
}


TEST (Reference, ConstructeurInvalideTitre)
{
  ASSERT_THROW (ReferenceDeTest uneReference("Homayoon Beigi", "", 2011, "ISBN 978-0-387-77591-3"), PreconditionException) << "L'attribut ne doit pas être vide";
}


TEST (Reference, ConstructeurInvalideAnnee)
{
  ASSERT_THROW (ReferenceDeTest uneReference("Homayoon Beigi", "Fundamentals of Speaker Recognition", 0, "ISBN 978-0-387-77591-3"), PreconditionException) << "L'attribut ne doit pas être inférieur ou égale à 0";
}


TEST (Reference, ConstructeurInvalideCodeIdentifiant)
{
  ASSERT_THROW (ReferenceDeTest uneReference("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, ""), PreconditionException) << "L'attribut ne doit pas être vide";
}

/**
 * \brief Creation d’une fixture a utiliser pour les methodes public de la classe Reference
 */
class UneReference : public ::testing::Test
{

public:


  UneReference () :
  f_reference ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3") { }
  ReferenceDeTest f_reference;
} ;


/**
 * \test Test de la méthode reqAuteurs()
 * 		Cas valide: vérifier le retour du nom des auteurs
 * 		Cas invalide: aucun
 */
TEST_F (UneReference, reqAuteurs)
{
  ASSERT_EQ ("Homayoon Beigi", f_reference.reqAuteurs())  << "L'accesseur ne renvoi pas la bonne valeur";
}


/**
 * \test Test de la méthode reqTitre()
 * 		Cas valide: vérifier le retour du titre
 * 		Cas invalide: aucun
 */
TEST_F (UneReference, reqTitre)
{
  ASSERT_EQ ("Fundamentals of Speaker Recognition", f_reference.reqTitre())  << "L'accesseur ne renvoi pas la bonne valeur";
}


/**
 * \test Test de la méthode reqAnnee()
 * 		Cas valide: vérifier le retour de l'année
 * 		Cas invalide: aucun
 */
TEST_F (UneReference, reqAnnee)
{
  ASSERT_EQ (2011, f_reference.reqAnnee())  << "L'accesseur ne renvoi pas la bonne valeur";
}


/**
 * \test Test de la méthode reqIdentifiant()
 *              Cas valide: vérifier le retour de l'identifiant
 * 		Cas invalide: aucun
 */
TEST_F (UneReference, reqIdentifiant)
{
  ASSERT_EQ ("ISBN 978-0-387-77591-3", f_reference.reqIdentifiant())  << "L'accesseur ne renvoi pas la bonne valeur";
}


/**
 * \test Test de la méthode asgAnnee()
 *              Cas valide: vérifier le changement d'année
 * 		Cas invalide: année <= 0
 */
TEST_F (UneReference, asgAnnee)
{
  f_reference.asgAnnee(2020);
  ASSERT_EQ (2020, f_reference.reqAnnee()) << "L'attribut passé en paramètre n'a pas été correctement assigné";
}

//Cas invalide


TEST_F (UneReference, asgAnneeInvalide)
{
  ASSERT_THROW (f_reference.asgAnnee(0), PreconditionException) << "L'attribut ne doit pas être inférieur ou égale à 0";
}


/**
 * \test Test de la méthode reqReferenceFormate();
 *        Cas valides: vérifier le retour des informations sur l'objet Reference formaté
 *        Cas invalides: aucun
 */
TEST_F (UneReference, reqReferenceFormate)
{
  std::ostringstream os;
  os << f_reference.reqAuteurs() << ". " << f_reference.reqTitre() << ".";

  ASSERT_EQ(os.str(), f_reference.reqReferenceFormate()) << "L'objet formaté ne correspond pas a ce qui est attendu";
}


/**
 * \test Test de la surcharge de l'opérateur ==;
 *        Cas valides:
 *              vérifier l'égalité entre deux références identiques
 *              vérifier l'inégalité entre deux références non identique
 *        Cas invalides: aucun
 */
TEST_F (UneReference, operatorEqualTrue)
{
  ReferenceDeTest uneReference ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3");
  ASSERT_TRUE(f_reference == uneReference) << "La comparaison des deux objets devrait renvoyer true";
}


TEST_F (UneReference, operatorEqualFalse)
{
  ReferenceDeTest uneReference ("Hart", "A survey of source code management tools for programming courses", 2009, "ISSN 1937-4771");
  ASSERT_FALSE(f_reference == uneReference) << "La comparaison des deux objets devrait renvoyer false";
}

