/**
 * \file Bibliographie.h
 * \brief Fichier qui contient l'interface de la classe Bibliographie qui permet de
 * manipuler une liste de référence.
 * \author Antoine BUQUET
 * \date 1 Novembre 2022
 */
#ifndef BIBLIOGRAPHIE_H
#define BIBLIOGRAPHIE_H

#include <vector>
#include "Reference.h"

namespace biblio
{

  /**
   * \class Bibliographie
   * \brief Cette classe permet de manipuler une liste de references.
   */
  class Bibliographie
  {
  public:
    Bibliographie(const std::string& p_nomBiblio);
    Bibliographie(const Bibliographie& p_bibliographie);
    ~Bibliographie();

    const std::string& reqNomBiblio() const;
    const std::string reqBibliographieFormate() const;

    void ajouterReference(const Reference& p_nouvelleReference);
    void supprimerReference(const std::string& p_identifiant);

    Bibliographie& operator=(const Bibliographie& p_bibliographie);

  private:
    std::string m_nomBiblio;
    std::vector<Reference*> m_vReferences;

    bool referenceEstDejaPresente(const std::string& p_identifiant) const;
    void verifieInvariant() const;
    void copierVecteur(const Bibliographie& p_bibliographie);
    void viderVecteur();
  };

} //namespace biblio

#endif /* BIBLIOGRAPHIE_H */

