/*!
   \file function_declarations.h
   \brief File containing the declarations of all the public function_declarations
   \author Josip Seric
   \date 24/10/2018
*/
#ifndef FUNCTION_DECLARATIONS_H
    #define FUNCTION_DECLARATIONS_H

    #include "internal_dependecies.h"

    int ReadFromFile(position);
    int PrintDataToConsole(position);

    int Sum(position, position, position);
    int Multiplicate(position, position, position);

    int Insert(position, const element);

    int DeleteAll(position);

    // TODO

#endif
