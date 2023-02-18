/**
 * \file validationFormat.cpp
 * \brief Implementation du module validerFormat
 * \author Antoine BUQUET
 * \date 11 Octobre 2022
 */
#include "validationFormat.h"
#include <iostream>

using namespace std;

namespace util
{


  /**
   * \brief Valider le format d'un nom
   * \param[in] p_nom le nom a valider
   * \return Un boolean indiquant sur le format du nom est valide
   */
  bool validerFormatNom (const string& p_nom)
  {
    bool estValide = true;

    if (p_nom.empty())
      {
        estValide = false;
      }

    if (!isalpha(p_nom[0]))
      {
        estValide = false;
      }

    for (unsigned int i = 1; i < p_nom.size(); i++)
      {
        if (!isalpha(p_nom[i]))
          {
            if (p_nom[i] == '-' || p_nom[i] == ' ')
              {
                if (!isalpha(p_nom[i + 1]) || i == p_nom.size() - 1)
                  {
                    estValide = false;
                  }
              }
            else
              {
                estValide = false;
              }
          }
      }

    return estValide;
  }


  /**
   * \brief Valider le format d'un code ISSN
   * \param[in] p_issn le code ISSN a valider
   * \return Un boolean indiquant sur le format du code ISSN est valide
   */
  bool validerCodeIssn (const string & p_issn)
  {
    bool estValide = true;

    if (p_issn.size() != 14)
      {
        return false;
      }
    else if (p_issn.substr(0, 5) != "ISSN " || p_issn[9] != '-')
      {
        estValide = false;
      }

    string codeIssn = p_issn.substr(5, 4) + p_issn.substr(10);

    int somme = 0;

    for (unsigned int i = 0; i < codeIssn.size() - 1; i++)
      {
        if (!isdigit(codeIssn[i]))
          {
            estValide = false;
          }
        else
          {
            somme += (codeIssn[i] - '0')*(8 - i);
          }
      }

    int cleAttendue = p_issn[p_issn.size() - 1] - '0';
    int cleCalculee = (11 - (somme % 11)) % 11;

    if (cleAttendue != cleCalculee)
      {
        estValide = false;
      }

    return estValide;
  }


  /**
   * \brief Valider le format d'un code ISBN
   * \param[in] p_issn le code ISBN a valider
   * \return Un boolean indiquant sur le format du code ISBN est valide
   */
  bool validerCodeIsbn (const string & p_isbn)
  {
    bool estValide = true;

    if (p_isbn.size() != 22)
      {
        return false;
      }
    else if (!(p_isbn.substr(0, 9) == "ISBN 978-" || p_isbn.substr(0, 9) == "ISBN 979-")
             || p_isbn[p_isbn.size() - 2] != '-')
      {
        estValide = false;
      }

    string codeIsbn = p_isbn.substr(5);
    int compteurTiret = 0;
    int j = 0;
    int somme = 0;

    for (unsigned int i = 0; i < codeIsbn.size() - 1; i++)
      {
        if (codeIsbn[i] == '-')
          {
            compteurTiret++;
          }
        else if (!isdigit(codeIsbn[i]))
          {
            estValide = false;
          }
        else
          {
            somme += (codeIsbn[i] - '0') * (j % 2 == 0 ? 1 : 3);
            j++;
          }
      }

    if (compteurTiret != 4)
      {
        estValide = false;
      }

    string finCodeIsbn = p_isbn.substr(9);

    int k = 0;
    int domaine = 0;

    while (finCodeIsbn[k] != '-')
      {
        domaine = domaine * 10 + (finCodeIsbn[k] - '0');
        k++;
      }

    k++;
    int editeur = 0;

    while (finCodeIsbn[k] != '-')
      {
        editeur = editeur * 10 + (finCodeIsbn[k] - '0');
        k++;
      }

    if (domaine == 6 || (domaine >  7 && domaine < 80) || (domaine > 94 && domaine < 600)
        || (domaine > 649 && domaine < 950) || (domaine > 989 && domaine < 9900)
        || (domaine > 9989 && domaine < 99900) || domaine > 99999)
      {
        estValide = false;
      }

    if ((editeur >  19 && editeur < 200) || (editeur > 699 && editeur < 7000)
        || (editeur > 8499 && editeur < 85000) || (editeur > 89999 && editeur < 900000)
        || (editeur > 949999 && editeur < 9500000) || editeur > 9999999)
      {
        estValide = false;
      }

    int cleAttendue = p_isbn[p_isbn.size() - 1] - '0';
    int cleCalculee = (10 - (somme % 10)) % 10;

    if (cleAttendue != cleCalculee)
      {
        estValide = false;
      }

    return estValide;
  }
} //namespace util