/*!
   \file function_declarations.h
   \brief File containing the declarations of all the public function_declarations
   \author Josip Seric
   \date 29/10/2018
*/
#ifndef FUNCTION_DECLARATIONS_H
    #define FUNCTION_DECLARATIONS_H

    int CountRowsInFile(char*);
    double ReadDataFromFile(person*, char const*);
    int PrintDataToConsole(person*, const int);

    person* CreateArray(const int);
    int DeleteData(person*);

    int CalculateRelativeGrade(person*,
                               const int,
                               const double);
#endif
