/**
 * \file Reference.h
 * \brief Fichier qui contient l'interface de la classe Reference qui permet de
 * modeliser et manipuler des reference d'ouvrage.
 * \author Antoine BUQUET
 * \date 11 Octobre 2022
 */
#ifndef REFERENCE_H
#define REFERENCE_H

#include "ContratException.h"
#include "validationFormat.h"

namespace biblio
{

  /**
   * \class Reference
   * \brief Cette classe permet de modeliser et manipuler des references.
   */
  class Reference
  {
  public:
    Reference(const std::string& p_auteurs, const std::string& p_titre,
              const unsigned int p_annee, const std::string& p_identifiant);

    virtual
    ~Reference(){ };

    const std::string& reqAuteurs() const;
    const std::string& reqTitre() const;
    int reqAnnee() const;
    const std::string& reqIdentifiant() const;

    void asgAnnee(const unsigned int p_annee);

    virtual const std::string reqReferenceFormate() const = 0;

    virtual Reference* clone() const = 0;

    bool operator==(const Reference& p_reference) const;

  private:
    std::string m_auteurs;
    std::string m_titre;
    int m_annee;
    std::string m_identifiant;
    void verifieInvariant() const;
  };

} //namespace biblio

#endif /* REFERENCE_H */