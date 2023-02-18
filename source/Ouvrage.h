/**
 * \file Ouvrage.h
 * \brief Fichier qui contient l'interface de la classe Ouvrage qui permet de
 * modeliser et manipuler des ouvrages.
 * \author Antoine BUQUET
 * \date 1 Novembre 2022
 */
#ifndef OUVRAGE_H
#define OUVRAGE_H

#include "Reference.h"

namespace biblio
{

  /**
   * \class Ouvrage
   * \brief Cette classe permet de modeliser et modeliser un ouvrage. Classe dérivé de la classe Reference.
   */
  class Ouvrage : public Reference
  {
  public:
    Ouvrage(const std::string& p_auteurs, const std::string& p_titre,
            int p_annee, const std::string& p_identifiant, const std::string& p_editeur, const std::string& p_ville);

    const std::string& reqEditeur() const;
    const std::string& reqVille() const;

    virtual const std::string reqReferenceFormate() const;

    virtual Reference* clone() const;

  private:
    std::string m_editeur;
    std::string m_ville;
    void verifieInvariant() const;
  };

} //namespace biblio

#endif /* OUVRAGE_H */

