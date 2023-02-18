/**
 * \file JournalTesteur.cpp
 * \brief Test unitaire de la classe dérivé Journal
 * \author Antoine BUQUET
 * \date 2 Novembre 2022
 */

#include <gtest/gtest.h>
#include <iostream>
#include "Journal.h"

using namespace std;
using namespace biblio;


/**
 * \test Test du constructeur
 * 		Cas valides: Creation d’un objet Journal et verification de l’assignation de tous les attributs
 * 		Cas invalides:
 * 			nom de la revue vide
 *                      volume <= 0
 *                      numero <= 0
 *                      page <= 0
 */
TEST (Journal, Constructeur)
{
  Journal unJournal("Hart", "A survey of source code management tools for programming courses", 2009, "ISSN 1937-4771", "Journal of Computing Sciences in Colleges", 24, 6, 113);
  ASSERT_EQ("Journal of Computing Sciences in Colleges", unJournal.reqNom()) << "L'attribut passé en paramètre n'a pas été correctement assigné";
  ASSERT_EQ(24, unJournal.reqVolume()) << "L'attribut passé en paramètre n'a pas été correctement assigné";
  ASSERT_EQ(6, unJournal.reqNumero()) << "L'attribut passé en paramètre n'a pas été correctement assigné";
  ASSERT_EQ(113, unJournal.reqPage()) << "L'attribut passé en paramètre n'a pas été correctement assigné";
}

//Cas invalide


TEST (Journal, ConstructeurInvalideNomRevue)
{
  ASSERT_THROW (Journal unJournal("Hart", "A survey of source code management tools for programming courses", 2009, "ISSN 1937-4771", "", 24, 6, 113), PreconditionException) << "L'attribut ne doit pas être vide";
}


TEST (Journal, ConstructeurInvalideVolume)
{
  ASSERT_THROW (Journal unJournal("Hart", "A survey of source code management tools for programming courses", 2009, "ISSN 1937-4771", "Journal of Computing Sciences in Colleges", 0, 6, 113), PreconditionException) << "L'attribut ne doit pas être inférieur ou égale à 0";
}


TEST (Journal, ConstructeurInvalideNumero)
{
  ASSERT_THROW (Journal unJournal("Hart", "A survey of source code management tools for programming courses", 2009, "ISSN 1937-4771", "Journal of Computing Sciences in Colleges", 24, 0, 113), PreconditionException) << "L'attribut ne doit pas être inférieur ou égale à 0";
}


TEST (Journal, ConstructeurInvalidePage)
{
  ASSERT_THROW (Journal unJournal("Hart", "A survey of source code management tools for programming courses", 2009, "ISSN 1937-4771", "Journal of Computing Sciences in Colleges", 24, 6, 0), PreconditionException) << "L'attribut ne doit pas être inférieur ou égale à 0";
}

/**
 * \brief Creation d’une fixture a utiliser pour les methodes public de la classe Journal
 */
class UnJournal : public ::testing::Test
{

public:


  UnJournal () :
  f_journal ("Hart", "A survey of source code management tools for programming courses", 2009, "ISSN 1937-4771", "Journal of Computing Sciences in Colleges", 24, 6, 113) { }
  Journal f_journal;
} ;


/**
 * \test Test de la méthode reqNom()
 * 		Cas valide: vérifier le retour du nom de la revue
 * 		Cas invalide: aucun
 */
TEST_F (UnJournal, reqNom)
{
  ASSERT_EQ ("Journal of Computing Sciences in Colleges", f_journal.reqNom())  << "L'accesseur ne renvoi pas la bonne valeur";
}


/**
 * \test Test de la méthode reqVolume()
 * 		Cas valide: vérifier le retour du volume
 * 		Cas invalide: aucun
 */
TEST_F (UnJournal, reqVolume)
{
  ASSERT_EQ (24, f_journal.reqVolume())  << "L'accesseur ne renvoi pas la bonne valeur";
}


/**
 * \test Test de la méthode reqNumero()
 * 		Cas valide: vérifier le retour du numero
 * 		Cas invalide: aucun
 */
TEST_F (UnJournal, reqNumero)
{
  ASSERT_EQ (6, f_journal.reqNumero())  << "L'accesseur ne renvoi pas la bonne valeur";
}


/**
 * \test Test de la méthode reqPage()
 * 		Cas valide: vérifier le retour du page
 * 		Cas invalide: aucun
 */
TEST_F (UnJournal, reqPage)
{
  ASSERT_EQ (113, f_journal.reqPage())  << "L'accesseur ne renvoi pas la bonne valeur";
}


/**
 * \test Test de la méthode reqReferenceFormate();
 *        Cas valides: vérifier le retour des informations sur l'objet Journal formaté
 *        Cas invalides: aucun
 */
TEST_F (UnJournal, reqReferenceFormate)
{
  std::ostringstream os;
  os << f_journal.reqAuteurs() << ". " << f_journal.reqTitre() << ". " << f_journal.reqNom()
          << ", vol. " << f_journal.reqVolume()  << ", no. " << f_journal.reqNumero() << ", pp. "
          << f_journal.reqPage() << ", " << f_journal.reqAnnee() << ". " << f_journal.reqIdentifiant()
          << ".";

  ASSERT_EQ(os.str(), f_journal.reqReferenceFormate()) << "L'objet formaté ne correspond pas a ce qui est attendu";
}


/**
 * \test Test de la méthode clone()
 *          Cas valide: le clone est identique à l'original
 *          Cas invalide: aucun
 */
TEST_F (UnJournal, clone)
{
  Reference* unClone = f_journal.clone();

  ASSERT_EQ(f_journal.reqAuteurs(), unClone -> reqAuteurs());
  ASSERT_EQ(f_journal.reqTitre(), unClone -> reqTitre());
  ASSERT_EQ(f_journal.reqAnnee(), unClone -> reqAnnee());
  ASSERT_EQ(f_journal.reqIdentifiant(), unClone -> reqIdentifiant());
  ASSERT_EQ(f_journal.reqReferenceFormate(), unClone -> reqReferenceFormate());

  delete unClone;
}