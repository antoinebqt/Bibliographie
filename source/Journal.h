/**
 * \file Journal.h
 * \brief Fichier qui contient l'interface de la classe Journal qui permet de
 * modeliser et manipuler des journaux.
 * \author Antoine BUQUET
 * \date 1 Novembre 2022
 */
#ifndef JOURNAL_H
#define JOURNAL_H

#include "Reference.h"

namespace biblio
{

  /**
   * \class Journal
   * \brief Cette classe permet de modeliser un journal. Classe dérivé de la classe Reference.
   */
  class Journal : public Reference
  {
  public:
    Journal(const std::string& p_auteurs, const std::string& p_titre,
            const unsigned int p_annee, const std::string& p_identifiant, const std::string& p_nom, const unsigned int p_volume, const unsigned int p_numero, const unsigned int p_page);

    const std::string& reqNom() const;
    int reqVolume() const;
    int reqNumero() const;
    int reqPage() const;

    virtual const std::string reqReferenceFormate() const;

    virtual Reference* clone() const;

  private:
    std::string m_nom;
    int m_volume;
    int m_numero;
    int m_page;

    void verifieInvariant() const;
  };

} //namespace biblio

#endif /* JOURNAL_H */

