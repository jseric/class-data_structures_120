/*!
   \file function_declarations.h
   \brief File containing the declarations of all the public function_declarations
   \author Josip Seric
   \date 24/10/2018
*/
#ifndef FUNCTION_DECLARATIONS_H
    #define FUNCTION_DECLARATIONS_H

    int MenuIO(void);
    int GetNodeDataFromUser(char*, char*, int*);
    int GetLastName(char*, char const*);
    int PrintListToConsole(position);
    int PrintListToFile(position);
    int ReadDataFromFile(position);

    int InsertToBeginning(position);
    int InsertToEnd(position);
    int InsertBefore(position);
    int InsertAfter(position);
    int InsertSorted(position,
        char const*,
        char const*, const int);
    int Insert(position, char const*,
        char const*, const int);

    int DeleteAll(position);
    int DeleteNode(position);

    int Sort(position);

    position CreateNewElement(
        char const*,
        char const*,
        const int);

    int Find(position);
    position FindLast(position);
    position FindPrevious(position, char const*);
    position FindByLastName(position, char const*);
    position FindPreviousSorted(position, char const*);

#endif
