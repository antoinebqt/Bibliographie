/**
 * \file Reference.cpp
 * \brief Implementation de la classe Reference
 * \author Antoine BUQUET
 * \date 11 Octobre 2022
 */
#include "Reference.h"
#include <sstream>

using namespace std;
using namespace util;

namespace biblio
{


  /**
   * \brief Constructeur avec paramètre.
   *        Création d'un objet Reference à partir de valeurs passées en paramètres.
   * \param[in] p_auteurs le string de l'auteur de la reference
   * \param[in] p_titre le string de le titre de la reference
   * \param[in] p_annee l'entier de l'annee d'édition de la reference
   * \param[in] p_identifiant le string de l'identifiant (ISSN ou ISBN)
   * \pre p_auteurs dans un format valide determiné par la fonction validerFormatNom
   * \pre p_titre non vide
   * \pre p_annee > 0
   * \pre p_identifiant non vide
   * \post m_auteurs prend la valeur de p_auteurs
   * \post m_titre prend la valeur de p_titre
   * \post m_annee prend la valeur de p_annee
   * \post m_identifiant prend la valeur de p_identifiant
   */
  Reference::Reference (const string& p_auteurs, const string& p_titre,
                        const unsigned int p_annee, const string& p_identifiant) :
  m_auteurs (p_auteurs), m_titre (p_titre), m_annee (p_annee), m_identifiant (p_identifiant)
  {
    PRECONDITION(validerFormatNom(p_auteurs));
    PRECONDITION(!p_titre.empty());
    PRECONDITION(p_annee > 0);
    PRECONDITION(!p_identifiant.empty());

    POSTCONDITION(m_auteurs == p_auteurs);
    POSTCONDITION(m_titre == p_titre);
    POSTCONDITION(m_annee == p_annee);
    POSTCONDITION(m_identifiant == p_identifiant);

    INVARIANTS();
  }


  /**
   * \brief Renvoi l'auteur
   * \return m_auteur le string de l'auteur de la reference
   */
  const string& Reference::reqAuteurs () const
  {
    return m_auteurs;
  }


  /**
   * \brief Renvoi le titre
   * \return m_titre le string de le titre de la reference
   */
  const string& Reference::reqTitre () const
  {
    return m_titre;
  }


  /**
   * \brief Renvoi l'annee
   * \return m_annee l'entier de l'annee de la reference
   */
  int Reference::reqAnnee () const
  {
    return m_annee;
  }


  /**
   * \brief Renvoi l'identifiant
   * \return m_identifiant le string de l'identifiant de la reference
   */
  const string& Reference::reqIdentifiant () const
  {
    return m_identifiant;
  }


  /**
   * \brief Assigne une nouvelle annee a la reference
   * \param[in] p_annee l'entier de la nouvelle annee pour la reference
   * \pre p_annee > 0
   * \post m_annee prend la valeur de p_annee
   */
  void Reference::asgAnnee (const unsigned int p_annee)
  {
    PRECONDITION(p_annee > 0);

    m_annee = p_annee;

    POSTCONDITION(m_annee == p_annee);

    INVARIANTS();
  }


  /**
   * \brief Renvoi une reference formatée dans un string
   * \return Un string d'une reference formatee
   */
  const string Reference::reqReferenceFormate () const
  {
    ostringstream os;

    os << m_auteurs << ". " << m_titre << ".";

    return os.str();
  }


  /**
   * \brief Surcharge de l'operateur ==
   * \param[in] p_reference : La reference a comparer a la reference courante
   * \return Un boolean indiquant si les references sont égales
   */
  bool Reference::operator== (const Reference& p_reference) const
  {
    return m_auteurs == p_reference.m_auteurs && m_titre == p_reference.m_titre &&
            m_annee == p_reference.m_annee && m_identifiant == p_reference.m_identifiant;
  }


  /**
   * \brief Vérifier les invariants de la classe
   */
  void Reference::verifieInvariant () const
  {
    INVARIANT(validerFormatNom(m_auteurs));
    INVARIANT(!m_titre.empty());
    INVARIANT(m_annee > 0);
    if (m_identifiant.substr(0, 4) == "ISSN")
      {
        INVARIANT(validerCodeIssn(m_identifiant));
      }
    else
      {
        INVARIANT(validerCodeIsbn(m_identifiant));
      }
  }
} //namespace biblio