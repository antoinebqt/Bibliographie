/**
 * \file OuvrageTesteur.cpp
 * \brief Test unitaire de la classe dérivée Ouvrage
 * \author Antoine BUQUET
 * \date 2 Novembre 2022
 */

#include <gtest/gtest.h>
#include <iostream>
#include "Ouvrage.h"

using namespace std;
using namespace biblio;


/**
 * \test Test du constructeur
 * 		Cas valides: Creation d’un objet Ouvrage et verification de l’assignation de tous les attributs
 * 		Cas invalides:
 * 			nom de l'éditeur invalide
 *                      nom de la ville invalide
 */
TEST (Ouvrage, Constructeur)
{
  Ouvrage unOuvrage("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "Springer", "New York");
  ASSERT_EQ("Springer", unOuvrage.reqEditeur()) << "L'attribut passé en paramètre n'a pas été correctement assigné";
  ASSERT_EQ("New York", unOuvrage.reqVille()) << "L'attribut passé en paramètre n'a pas été correctement assigné";
}

//Cas invalide


TEST (Ouvrage, ConstructeurInvalideEditeur)
{
  ASSERT_THROW (Ouvrage unOuvrage("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "", "New York"), PreconditionException) << "L'attribut ne respect pas le bon format";
}


TEST (Ouvrage, ConstructeurInvalideVille)
{
  ASSERT_THROW (Ouvrage unOuvrage("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "Springer", ""), PreconditionException) << "L'attribut ne respect pas le bon format";
}

/**
 * \brief Creation d’une fixture a utiliser pour les methodes public de la classe Ouvrage
 */
class UnOuvrage : public ::testing::Test
{

public:


  UnOuvrage () :
  f_ouvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "Springer", "New York") { }
  Ouvrage f_ouvrage;
} ;


/**
 * \test Test de la méthode reqEditeur()
 * 		Cas valide: vérifier le retour du nom de l'éditeur
 * 		Cas invalide: aucun
 */
TEST_F (UnOuvrage, reqEditeur)
{
  ASSERT_EQ ("Springer", f_ouvrage.reqEditeur())  << "L'accesseur ne renvoi pas la bonne valeur";
}


/**
 * \test Test de la méthode reqVille()
 * 		Cas valide: vérifier le retour du nom de la ville
 * 		Cas invalide: aucun
 */
TEST_F (UnOuvrage, reqVille)
{
  ASSERT_EQ ("New York", f_ouvrage.reqVille())  << "L'accesseur ne renvoi pas la bonne valeur";
}


/**
 * \test Test de la méthode reqReferenceFormate();
 *
 *        Cas valides: vérifier le retour des informations sur l'objet Ouvrage formaté
 *        Cas invalides: aucun
 */
TEST_F (UnOuvrage, reqReferenceFormate)
{
  std::ostringstream os;
  os << f_ouvrage.reqAuteurs() << ". " << f_ouvrage.reqTitre() << ". " << f_ouvrage.reqVille()
          << " : " << f_ouvrage.reqEditeur() << ", " << f_ouvrage.reqAnnee() << ". "
          << f_ouvrage.reqIdentifiant() << ".";

  ASSERT_EQ(os.str(), f_ouvrage.reqReferenceFormate()) << "L'objet formaté ne correspond pas a ce qui est attendu";
}


/**
 * \test Test de la méthode clone()
 *          Cas valide: le clone est identique à l'original
 *          Cas invalide: aucun
 */
TEST_F (UnOuvrage, clone)
{
  Reference* unClone = f_ouvrage.clone();

  ASSERT_EQ(f_ouvrage.reqAuteurs(), unClone -> reqAuteurs());
  ASSERT_EQ(f_ouvrage.reqTitre(), unClone -> reqTitre());
  ASSERT_EQ(f_ouvrage.reqAnnee(), unClone -> reqAnnee());
  ASSERT_EQ(f_ouvrage.reqIdentifiant(), unClone -> reqIdentifiant());
  ASSERT_EQ(f_ouvrage.reqReferenceFormate(), unClone -> reqReferenceFormate());

  delete unClone;
}