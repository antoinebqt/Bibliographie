/**
 * \file Journal.cpp
 * \brief Implementation de la classe Journal derivée de Reference
 * \author Antoine BUQUET
 * \date 1 Novembre 2022
 */
#include "Journal.h"
#include <sstream>

using namespace std;
using namespace util;

namespace biblio
{


  /**
   * \brief Constructeur avec paramètre.
   *        Création d'un objet Journal à partir de valeurs passées en paramètres.
   * \param[in] p_auteurs le string de l'auteur de la reference
   * \param[in] p_titre le string de le titre de la reference
   * \param[in] p_annee l'entier de l'annee d'édition de la reference
   * \param[in] p_identifiant le string de l'identifiant (ISSN ou ISBN)
   * \param[in] p_nom le string du nom de la revue où la référence a été publiée
   * \param[in] p_volume l'entier correspondant au volume où la référence a été publiée
   * \param[in] p_numero l'entier correspondant au numéro où la référence a été publiée
   * \param[in] p_page l'entier correspondant au volume où la référence a été publiée
   * \pre p_nom non vide
   * \pre p_volume > 0
   * \pre p_numero > 0
   * \pre p_page > 0
   * \pre p_identifiant dans un format valide determiné par la fonction validerCodeIssn
   * \post m_nom prend la valeur p_nom
   * \post m_volume prend la valeur p_volume
   * \post m_numero prend la valeur p_numero
   * \post m_page prend la valeur p_page
   */
  Journal::Journal (const string& p_auteurs, const string& p_titre,
                    const unsigned int p_annee, const string& p_identifiant, const string& p_nom, const unsigned int p_volume,
                    const unsigned int p_numero, const unsigned int p_page) : Reference (p_auteurs, p_titre, p_annee, p_identifiant),
  m_nom (p_nom), m_volume (p_volume), m_numero (p_numero), m_page (p_page)
  {
    PRECONDITION(!p_nom.empty());
    PRECONDITION(p_volume > 0);
    PRECONDITION(p_numero > 0);
    PRECONDITION(p_page > 0);
    PRECONDITION(validerCodeIssn(p_identifiant));

    POSTCONDITION(m_nom == p_nom);
    POSTCONDITION(m_volume == p_volume);
    POSTCONDITION(m_numero == p_numero);
    POSTCONDITION(m_page == p_page);

    INVARIANTS();
  }


  /**
   * \brief Renvoi le nom de la revue dans laquelle la référence a été publiée
   * \return m_nom le string du nom de la revue
   */
  const std::string& Journal::reqNom () const
  {
    return m_nom;
  }


  /**
   * \brief Renvoi le volume dans laquelle la référence a été publiée
   * \return m_volume l'entier du volume
   */
  int Journal::reqVolume () const
  {
    return m_volume;
  }


  /**
   * \brief Renvoi le numéro dans laquelle la référence a été publiée
   * \return m_numero l'entier du numéro
   */
  int Journal::reqNumero () const
  {
    return m_numero;
  }


  /**
   * \brief Renvoi la page à laquelle la référence commence
   * \return m_page l'entier de la page
   */
  int Journal::reqPage () const
  {
    return m_page;
  }


  /**
   * \brief Affichage du nom de la revue dans laquelle la référence à été publié
   *        ainsi que le volume, le numéro et la page
   * \return Un string contenant le nom de la revue, le volume, le numéro et la page
   */
  const std::string Journal::reqReferenceFormate () const
  {
    ostringstream os;
    os << Reference::reqReferenceFormate() << " " << m_nom << ", vol. " << m_volume
            << ", no. " << m_numero << ", pp. " << m_page << ", " << Reference::reqAnnee()
            << ". " << Reference::reqIdentifiant() << ".";
    return os.str();
  }


  /**
   * \brief Fait une copie de l'objet courant et la renvoi
   * \return Un pointeur sur l'objet copié
   */
  Reference* Journal::clone () const
  {
    return new Journal(*this);
  }


  /**
   * \brief Vérifier les invariants de la classe
   */
  void Journal::verifieInvariant () const
  {
    INVARIANT(!m_nom.empty());
    INVARIANT(m_volume > 0);
    INVARIANT(m_numero > 0);
    INVARIANT(m_page > 0);
  }
} //namespace biblio