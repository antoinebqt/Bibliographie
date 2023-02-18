/**
 * \file ReferenceException.cpp
 * \brief Implementation des classes d'erreur concernant les réferences
 * \author Antoine BUQUET
 * \date 2 Décembre 2022
 */
#include "ReferenceException.h"

using namespace std;


/**
 * \brief Constructeur de la classe de base ReferenceException
 * \param[in] p_raison : La raison de l'erreur
 */
ReferenceException::ReferenceException (const string& p_raison)
: runtime_error (p_raison) { }


/**
 * \brief Constructeur de la classe dérivé ReferenceDejaPresenteException
 * \param[in] p_raison : La raison de l'erreur
 */
ReferenceDejaPresenteException::ReferenceDejaPresenteException (const string& p_raison)
: ReferenceException (p_raison) { }


/**
 * \brief Constructeur de la classe dérivé ReferenceAbsenteException
 * \param[in] p_raison : La raison de l'erreur
 */
ReferenceAbsenteException::ReferenceAbsenteException (const string& p_raison)
: ReferenceException (p_raison) { }