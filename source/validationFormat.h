/**
 * \file validationFormat.h
 * \brief Fichier qui contient l'interface du module de validation de format.
 * \author Antoine BUQUET
 * \date 11 Octobre 2022
 */
#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H

#include <string>

namespace util
{
  bool validerFormatNom(const std::string& p_nom);
  bool validerCodeIssn(const std::string& p_issn);
  bool validerCodeIsbn(const std::string& p_isbn);
} //namespace util

#endif /* VALIDATIONFORMAT_H */