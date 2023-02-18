/**
 * \file Bibliographie.cpp
 * \brief Implementation de la classe Biblioraphie
 * \author Antoine BUQUET
 * \date 1 Novembre 2022
 */
#include "Bibliographie.h"
#include "ReferenceException.h"
#include <sstream>
#include <iostream>
#include<iterator>

using namespace std;
using namespace util;

namespace biblio
{


  /**
   * \brief Constructeur avec paramètre.
   *        Création d'un objet Bibliographie à partir de valeurs passées en paramètres.
   * \param[in] p_nomBiblio le string du nom de la bibliographie
   * \pre p_nomBiblio non vide
   * \post m_nomBiblio prend la valeur de p_nomBiblio
   * \post La bibliographie est vide
   */
  Bibliographie::Bibliographie (const string& p_nomBiblio) : m_nomBiblio (p_nomBiblio)
  {
    PRECONDITION(!p_nomBiblio.empty());

    POSTCONDITION(m_nomBiblio == p_nomBiblio);
    POSTCONDITION(m_vReferences.empty());

    INVARIANTS();
  }


  /**
   * \bried Constructeur par copie
   * \param[in] p_bibliographie : La bibliographie à copier
   * \post m_nomBiblio prend la valeur du m_nomBiblio de p_bibliographie
   */
  Bibliographie::Bibliographie (const Bibliographie& p_bibliographie)
  {
    m_nomBiblio = p_bibliographie.m_nomBiblio;
    copierVecteur(p_bibliographie);

    POSTCONDITION(m_nomBiblio == p_bibliographie.m_nomBiblio);

    INVARIANTS();
  }


  /**
   * \brief Destructeur responsable de désallouer toutes les références du vecteur
   */
  Bibliographie::~Bibliographie ()
  {
    viderVecteur();
  }


  /**
   * \brief Renvoi le nom
   * \return m_nomBiblio le string du nom de la bibliographie
   */
  const string& Bibliographie::reqNomBiblio () const
  {
    return m_nomBiblio;
  }


  /**
   * \brief Affichage de toutes les infos de toutes les référneces enregistrées
   * \return Un string contenant la liste de toutes les references formatée
   */
  const string Bibliographie::reqBibliographieFormate () const
  {
    ostringstream os;
    int count = 0;
    vector<Reference*>::const_iterator iter;
    os << m_nomBiblio << endl << "===============================" << endl;
    for (iter = m_vReferences.begin(); iter < m_vReferences.end(); iter++)
      {
        os << "[" << ++count << "] " << (*iter)->reqReferenceFormate() << endl;
      }
    return os.str();
  }


  /**
   * \brief Vérifie si une référence est déjà enregistrées en comparant sur l'identifiant
   * \param[in] p_identifiant : L'identifiant a comparer avec les références déjà enregistrées
   * \pre p_identifiant dans un format valide determiné par une des fonctions
   *      validerCodeIssn ou validerCodeIsbn
   * \return Un boolean indiquant si la référence est déjà présente ou non
   */
  bool Bibliographie::referenceEstDejaPresente (const string& p_identifiant) const
  {
    if (p_identifiant.substr(0, 4) == "ISSN")
      {
        PRECONDITION(validerCodeIssn(p_identifiant));
      }
    else
      {
        PRECONDITION(validerCodeIsbn(p_identifiant));
      }

    bool referenceTrouve = false;

    vector<Reference*>::const_iterator iter;
    for (iter = m_vReferences.begin(); iter < m_vReferences.end(); iter++)
      {
        if ((*iter)->reqIdentifiant() == p_identifiant)
          {
            referenceTrouve = true;
          }
      }
    return referenceTrouve;
  }


  /**
   * \brief Ajoute une référence à la bibliographie
   * \param[in] p_nouvelleReference : L'adresse d'une référence à enregistrer
   * \post La bibliographie n'est plus vide
   */
  void Bibliographie::ajouterReference (const Reference& p_nouvelleReference)
  {
    if (referenceEstDejaPresente(p_nouvelleReference.reqIdentifiant()))
      {
        throw ReferenceDejaPresenteException("La référence \"" + p_nouvelleReference.reqReferenceFormate() +
                                             "\" ne peut pas être ajoutée car une référence avec le même identifiant est déjà présente.");
      }
    else
      {
        m_vReferences.push_back(p_nouvelleReference.clone());
        POSTCONDITION(m_vReferences.size() != 0);

        INVARIANTS();
      }
  }


  /**
   * \brief Supprime une référence de la bibliographie
   * \param[in] p_identifiant : L'identifiant de la bibliographie à supprimer
   * \pre p_identifiant dans un format valide determiné par une des fonctions
   *      validerCodeIssn ou validerCodeIsbn
   */
  void Bibliographie::supprimerReference (const string& p_identifiant)
  {

    if (p_identifiant.substr(0, 4) == "ISSN")
      {
        PRECONDITION(validerCodeIssn(p_identifiant));
      }
    else
      {
        PRECONDITION(validerCodeIsbn(p_identifiant));
      }

    if (referenceEstDejaPresente(p_identifiant))
      {
        vector<Reference*>::const_iterator iter;
        for (iter = m_vReferences.begin(); iter < m_vReferences.end(); iter++)
          {
            if ((*iter)->reqIdentifiant() == p_identifiant)
              {
                delete *iter;
                iter = m_vReferences.erase (iter);
              }
          }
        INVARIANTS();
      }
    else
      {
        throw ReferenceAbsenteException("Aucune référence trouvée avec l'identifiant \"" + p_identifiant + "\".");
      }
  }


  Bibliographie& Bibliographie::operator= (const Bibliographie& p_bibliographie)
  {
    m_nomBiblio = p_bibliographie.m_nomBiblio;
    viderVecteur();
    copierVecteur(p_bibliographie);
    INVARIANTS();
    return *this;
  }


  /**
   * \brief Permet de copier le vecteur d'une bibliographie à la bibliographie courante
   * \param[in] p_bibliographie : La bibliographie qui contient le vecteur à copier
   * \pre Le vecteur de références doit être vide
   */
  void Bibliographie::copierVecteur (const Bibliographie& p_bibliographie)
  {
    PRECONDITION(m_vReferences.empty());

    vector<Reference*>::const_iterator iter;
    for (iter = p_bibliographie.m_vReferences.begin(); iter < p_bibliographie.m_vReferences.end(); iter++)
      {
        Reference& reference = *(*iter);
        ajouterReference(reference);
      }

    INVARIANTS();
  }


  /**
   * \brief Permet de vider le vecteur de références et de désallouer toutes les références
   */
  void Bibliographie::viderVecteur ()
  {
    vector<Reference*>::const_iterator iter;
    for (iter = m_vReferences.begin(); iter < m_vReferences.end(); iter++)
      {
        delete *iter;
      }
    m_vReferences.clear();
  }


  /**
   * \brief Vérifier les invariants de la classe
   */
  void Bibliographie::verifieInvariant () const
  {
    INVARIANT(!m_nomBiblio.empty());
    INVARIANT(m_vReferences.size() >= 0);
  }
} //namespace biblio
