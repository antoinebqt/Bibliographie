/**
 * \file Ouvrage.cpp
 * \brief Implementation de la classe Ouvrage derivée de Reference
 * \author Antoine BUQUET
 * \date 1 Novembre 2022
 */
#include "Ouvrage.h"
#include <sstream>

using namespace std;
using namespace util;

namespace biblio
{


  /**
   * \brief Constructeur avec paramètre.
   *        Création d'un objet Ouvrage à partir de valeurs passées en paramètres.
   * \param[in] p_auteurs le string de l'auteur de la reference
   * \param[in] p_titre le string de le titre de la reference
   * \param[in] p_annee l'entier de l'annee d'édition de la reference
   * \param[in] p_identifiant le string de l'identifiant (ISSN ou ISBN)
   * \param[in] p_editeur le string de l'editeur de l'ouvrage
   * \param[in] p_ville le string de la ville d'édition de l'ouvrage
   * \pre p_editeur dans un format valide determiné par la fonction validerFormatNom
   * \pre p_ville dans un format valide determiné par la fonction validerFormatNom
   * \pre p_identifiant dans un format valide determiné par la fonction validerCodeIsbn
   * \post m_editeur prend la valeur de p_editeur
   * \post m_ville prend la valeur de p_ville
   */
  Ouvrage::Ouvrage (const string& p_auteurs, const string& p_titre, int p_annee,
                    const string& p_identifiant, const string& p_editeur,
                    const string& p_ville) : Reference (p_auteurs, p_titre, p_annee, p_identifiant),
  m_editeur (p_editeur), m_ville (p_ville)
  {
    PRECONDITION(validerFormatNom(p_editeur));
    PRECONDITION(validerFormatNom(p_ville));
    PRECONDITION(validerCodeIsbn(p_identifiant));

    POSTCONDITION(m_editeur == p_editeur);
    POSTCONDITION(m_ville == p_ville);

    INVARIANTS();
  }


  /**
   * \brief Renvoi le nom de l'éditeur de l'ouvrage
   * \return m_editeur le string du nom de l'éditeur de l'ouvrage
   */
  const std::string & Ouvrage::reqEditeur () const
  {
    return m_editeur;
  }


  /**
   * \brief Renvoi le nom de la ville d'édition de l'ouvrage
   * \return m_ville le string de la ville d'édition de l'ouvrage
   */
  const std::string & Ouvrage::reqVille () const
  {
    return m_ville;
  }


  /**
   * \brief Affichage de l'éditeur et de la ville d'édition de l'ouvrage
   * \return Un string contenant l'éditeur et la ville d'édition
   */
  const std::string Ouvrage::reqReferenceFormate () const
  {
    ostringstream os;
    os << Reference::reqReferenceFormate() << " " << m_ville << " : " << m_editeur
            << ", " << Reference::reqAnnee() << ". " << Reference::reqIdentifiant() << ".";
    return os.str();
  }


  /**
   * \brief Fait une copie de l'objet courant et la renvoi
   * \return Un pointeur sur l'objet copié
   */
  Reference * Ouvrage::clone () const
  {
    return new Ouvrage(*this);
  }


  /**
   * \brief Vérifier les invariants de la classe
   */
  void Ouvrage::verifieInvariant () const
  {
    INVARIANT(validerFormatNom(m_editeur));
    INVARIANT(validerFormatNom(m_ville));
  }
} //namespace biblio
