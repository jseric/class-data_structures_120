/*!
   \file list_search.c
   \brief File containing list search methods
   \author Josip Seric
   \date 25/10/2018
*/
#include "external_dependencies.h"
#include "internal_dependencies.h"

/*!
   \brief Find the element containing the target last name
   \param Pointer to head
   \return int value defining the result of function execution
*/
int Find(position head)
{
    position target = NULL;
    char targetSurname[SURNAME_LENGTH] = "\0";
    GetLastName(targetSurname, "Last name of the element you want to find");

    target = FindByLastName(head, targetSurname);
    if (target == NULL)
    {
        printf("WARNING!!! Data not found!\n");
        return FIND_NOT_FOUND;
    }

    printf("Target data:\n");
    printf("%s %s %d\n", target->name, target->surname, target->yearOfBirth);

    return FIND_OK;
}

/*!
   \brief Find the last node in the list
   \param pointer to head
   \return pointer to last node in the list
           (head for an empty list)
*/
position FindLast(position head)
{
    position target = head;

    while (target->next != NULL)
        target = target->next;

    return target;
}

/*!
   \brief Find the previous element of the element containing
          the target last name
   \param Pointer to head,
          String containing last name of target node
   \return Pointer to previous of target node
*/
position FindPrevious(position head, char const* targetSurname)
{
    position previous = head;

    while (previous->next != NULL &&
           strcmp(previous->next->surname, targetSurname) != 0)
    {
        previous = previous->next;
    }

    if (previous->next == NULL)
    {
        // Target node not found
        return NULL;
    }

    return previous;
}

/*!
   \brief Find the element containing the target last name
   \param Pointer to head,
          String containing last name of target node
   \return Pointer to target node
*/
position FindByLastName(position head, char const* targetSurname)
{
    position previous = FindPrevious(head, targetSurname);
    if (previous == NULL)
    {
        // Previous node not found
        return NULL;
    }

    return previous->next;
}

/*!
   \brief Find the node with the surname which is
          alphabetically smaller than the target surname
   \param Pointer to head,
          Array of target surname
   \return Pointer to previous element
*/
position FindPreviousSorted(position head, char const* surname)
{
    position previous = head;

    while (previous->next != NULL &&
           strcmp(previous->next->surname, surname) < 0)
       previous = previous->next;

    return previous;
}
