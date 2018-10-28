/*!
   \file function_declarations.h
   \brief File containing the declarations of all the public function_declarations
   \author Josip Seric
   \date 24/10/2018
*/
#ifndef FUNCTION_DECLARATIONS_H
    #define FUNCTION_DECLARATIONS_H

    int MenuIO(void);
    int GetSurname(char*, char const*);
    int PrintListToConsole(position);
    int PrintListToFile(position);
    int ReadDataFromConsole(personData*);
    int ReadDataFromFile(position);

    int InsertToBeginning(position);
    int InsertToEnd(position);
    int InsertBefore(position);
    int InsertAfter(position);
    int InsertSorted(position, const personData);
    int Insert(position, const personData);

    int DeleteAll(position);
    int DeleteNode(position);

    int Sort(position);

    position CreateNewElement(const personData);

    int Find(position);
    position FindLast(position);
    position FindPrevious(position, char const*);
    position FindBySurname(position, char const*);
    position FindPreviousSorted(position, char const*);

#endif
