#include "external_dependencies.h"
#include "internal_dependencies.h"

// Function declarations
int GetDataAndInsert(position);
int Delete(position);

/*!
   \brief Insert node to beginning of list
   \param Pointer to head
   \return int value defining the result of function execution
*/
int InsertToBeginning(position head)
{
    // Insert after head
    return GetDataAndInsert(head);
}

/*!
   \brief Insert node to end of list
   \param pointer to head
   \return int value defining the result of function execution
*/
int InsertToEnd(position head)
{
    position last = FindLast(head);
    return GetDataAndInsert(last);
}

/*!
   \brief Insert node before the specified node
   \param Pointer to head
   \pre List must not be empty
   \return int value defining the result of function execution
*/
int InsertBefore(position head)
{
    position previous = NULL;

    char afterSurname[SURNAME_LENGTH] = "\0";
    GetSurname(afterSurname, "Surname of node to be inserted before");

    previous = FindPrevious(head, afterSurname);
    if (previous == NULL)
    {
        // Node to be inserted before not found
        printf("WARNING!!! Node to be inserted before not found\n");
        return INSERT_NOT_FOUND;
    }

    return GetDataAndInsert(previous);
}

/*!
   \brief Insert node after the specified node
   \param Pointer to head
   \pre List must not be empty
   \return int value defining the result of function execution
*/
int InsertAfter(position head)
{
    position previous = NULL;

    char beforeSurname[SURNAME_LENGTH] = "\0";
    GetSurname(beforeSurname, "Surname of node to be inserted after");

    previous = FindBySurname(head, beforeSurname);
    if (previous == NULL)
    {
        // Node to be inserted after not found
        printf("WARNING!!! Node to be inserted after not found\n");
        return INSERT_NOT_FOUND;
    }

    return GetDataAndInsert(previous);
}

/*!
   \brief Insert node to list in sorted fashion
   \param Pointer to head,
          Constant personData object
   \pre Get user data
   \return int value defining the result of function execution
*/
int InsertSorted(position head, const personData data)
{
    position previous = FindPreviousSorted(head, data.surname);
    return Insert(head, data);
}

/*!
   \brief Insert new node with specified data to list after previous node
   \param Pointer to node after which the node will be inserted,
          Constant personData object
   \pre Find the previous element
   \return int value defining the result of function execution
*/
int Insert(position previous, const personData data)
{
    position target = CreateNewElement(data);
    if (target == NULL)
    {
        return INSERT_ALLOC_FAILED;
    }

    // Insert to list
    target->next   = previous->next;
    previous->next = target;

    return INSERT_OK;
}

/*!
   \brief Delete all nodes from list
   \param Pointer to head
*/
int DeleteAll(position head)
{
    while (head->next != NULL)
    {
        Delete(head);
    }

    return VOID_OK;
}

/*!
   \brief Delete node with the specified surname
   \param Pointer to head
   \return int value defining the result of function execution
*/
int DeleteNode(position head)
{
    position previous = NULL;
    char targetSurname[SURNAME_LENGTH] = "\0";
    GetSurname(targetSurname, "Surname of node you want to delete");

    previous = FindPrevious(head, targetSurname);
    if (previous == NULL)
    {
        // Target node not found
        printf("WARNING!!! Data not found!\n");
        return DELETE_NOT_FOUND;
    }

    Delete(previous);
    return DELETE_OK;
}

/*!
   \brief Sort the list by surname in ascending order
   \param Pointer to head
   \return int value defining the result of function execution
*/
int Sort(position head)
{
    position first = NULL;
    position second = NULL;
    position previousFirst = NULL;
    position last = NULL;

    if (head->next == NULL)
    {
        printf("WARNING!!! List is empty!\n");
        return SORT_EMPTY_LIST;
    }

    if (head->next->next == NULL)
    {
        printf("WARNING!!! List contains only 1 elemnt!\n");
        return SORT_SINGLE_ELEMENT;
    }

    // Mail loop
    while (head->next != last)
    {
        previousFirst = head;
        first = previousFirst->next;

        // Secondary loop
        while (first->next != last)
        {
            second = first->next;

            if (strcmp(first->data.surname,
                       second->data.surname) > 0)
            {
                // Replace the 2 nodes
                // Order after replacement:
                // previousFirst->second->first
                previousFirst->next = second;
                first->next         = second->next;
                second->next        = first;
            }
            else
            {
                first = first->next;
            }

            previousFirst = previousFirst->next;
        }

        // Move the last 1 step backwards,
        // because everything after last (including last) is already sorted
        last = previousFirst->next;
    }

    return SORT_OK;
}

// ### PRIVATE FUNCTIONS ###

/*!
   \brief Insert node to list
   \param pointer to node after which the node will be inserted
   \pre Find the previous element
   \return int value defining the result of function execution
*/
int GetDataAndInsert(position previous)
{
    personData data = { "\0", "\0", 0 };

    // Get node data
    ReadDataFromConsole(&data);

    return Insert(previous, data);
}

/*!
   \brief Delete the next node after previous
   \param Pointer to node previous of target
*/
int Delete(position previous)
{
    position target = previous->next;
    previous->next = target->next;

    free (target);

    return VOID_OK;
}
