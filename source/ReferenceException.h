/**
 * \file ReferenceException.h
 * \brief Fichier qui contient l'interface des classes d'erreur relatif aux réferences
 * \author Antoine BUQUET
 * \date 2 Décembre 2022
 */

#ifndef REFERENCEEXCEPTION_H
#define REFERENCEEXCEPTION_H

#include <stdexcept>

/**
 * \class ReferenceException
 * \brief Classe de base des exceptions de réference
 */
class ReferenceException : public std::runtime_error
{
public:
  ReferenceException(const std::string& p_raison);
};

/**
 * \class ReferenceDejaPresenteException
 * \brief Classe pour la gestion des erreurs d'ajout de réference
 */
class ReferenceDejaPresenteException : public ReferenceException
{
public:
  ReferenceDejaPresenteException(const std::string& p_raison);
};

/**
 * \class ReferenceAbsenteException
 * \brief Classe pour la gestion des erreurs de suppression de réference
 */
class ReferenceAbsenteException : public ReferenceException
{
public:
  ReferenceAbsenteException(const std::string& p_raison);
};

#endif /* REFERENCEEXCEPTION_H */

