/*!
   \file polynomial_management.c
   \brief File containing polynomial (list) management functions
   \author Josip Seric
   \date 01/11/2018
*/

#include "external_dependencies.h"
#include "internal_dependecies.h"

// Function declarations
position CreateNew(const element);
int InsertNode(position, const position);
int DeleteNext(position);


/*!
   \brief Calculate the sum of 2 polynomials
   \param Pointer to head of sum,
          Pointer to first element of polynomial 1,
          Pointer to first element of poylnomial 2
   \return Integer describing how the function performed
*/
int Sum(position sum,
        position current1,
        position current2)
{
    int returnValue = 0;

    element buffer = { 0, 0 };

    if (current1 == NULL &&
        current2 == NULL)
    {
        printf("WARING!!! Both polynomials are empty!\n");
        return INSERT_EMPTY_POLYS;
    }

    while (current1 != NULL &&
           current2 != NULL)
    {
        if (current1->data.exponent == current2->data.exponent)
        {
            buffer.coefficient =
                current1->data.coefficient +
                current2->data.coefficient;

            buffer.exponent = current1->data.exponent;

            current1 = current1->next;
            current2 = current2->next;
        }
        else if (current1->data.exponent > current2->data.exponent)
        {
            buffer.coefficient =
                current1->data.coefficient;

            buffer.exponent = current1->data.exponent;

            current1 = current1->next;
        }
        else    // current1->data.exponent < current2->data.exponent
        {
            buffer.coefficient =
                current2->data.coefficient;

            buffer.exponent = current2->data.exponent;

            current2 = current2->next;
        }

        returnValue = Insert(sum, buffer);
        if (returnValue == INSERT_OK)
        {
            // Everything went ok
        }
        else if (returnValue == INSERT_ALLOC_FAILED)
        {
            return INSERT_ALLOC_FAILED;
        }
    }

    if (current1 == NULL)
    {
        // Add the remainder from poly2
        while (current2 != NULL)
        {
            returnValue = Insert(sum, current2->data);
            if (returnValue == INSERT_OK)
            {
                // Everything went ok
            }
            else if (returnValue == INSERT_ALLOC_FAILED)
            {
                return INSERT_ALLOC_FAILED;
            }

            current2 = current2->next;
        }
    }
    else if (current2 == NULL)
    {
        // Add the remainder from poly1
        while (current1 != NULL)
        {
            returnValue = Insert(sum, current1->data);
            if (returnValue == INSERT_OK)
            {
                // Everything went ok
            }
            else if (returnValue == INSERT_ALLOC_FAILED)
            {
                return INSERT_ALLOC_FAILED;
            }

            current1 = current1->next;
        }
    }

    return INSERT_OK;
}

/*!
   \brief Calculate the multiplication product of 2 polynomials
   \param Pointer to head of multiplication product,
          Pointer to first element of polynomial 1,
          Pointer to first element of poylnomial 2
   \return Integer describing how the function performed
*/
int Multiplicate(position mul,
                 position current1,
                 position first2)
{
    position current2 = NULL;
    int returnValue = 0;

    element buffer = { 0, 0 };

    if (current1 == NULL &&
        current2 == NULL)
    {
        printf("WARING!!! Both polynomials are empty!\n");
        return INSERT_EMPTY_POLYS;
    }

    while (current1 != NULL)
    {
        current2 = first2;

        while (current2 != NULL)
        {
            buffer.coefficient =
                current1->data.coefficient *
                current2->data.coefficient;

            buffer.exponent =
                current1->data.exponent +
                current2->data.exponent;

            returnValue = Insert(mul, buffer);
            if (returnValue == INSERT_OK)
            {
                // Everything went ok
            }
            else if (returnValue == INSERT_ALLOC_FAILED)
            {
                return INSERT_ALLOC_FAILED;
            }

            current2 = current2->next;
        }

        current1 = current1->next;
    }

    return INSERT_OK;
}

/*!
   \brief Insert data in polynomial
   \param Pointer to head of polynomial,
          Target data
   \pre Data to be inserted must exist
   \return Integer describing how the function performed
*/
int Insert(position head, const element targetData)
{
    position previous = head;
    position target = NULL;

    while (previous->next != NULL &&
           previous->next->data.exponent > targetData.exponent)
    {
        previous = previous->next;
    }

    if (previous->next != NULL &&
        previous->next->data.exponent == targetData.exponent)
    {
        // Exponents are equal
        // No need to create new element

        if (previous->next->data.coefficient + targetData.coefficient == 0)
        {
            // New coefficient is 0, so delete the element
            DeleteNext(previous);
            return INSERT_OK;
        }

        previous->next->data.coefficient += targetData.coefficient;
        return INSERT_OK;
    }

    target = CreateNew(targetData);
    if (target == NULL)
    {
        printf("ERROR!!! Allocation failed!\n");
        return INSERT_ALLOC_FAILED;
    }

    return InsertNode(previous, target);
}

/*!
   \brief Delete entire polynomial
   \param Pointer to polynomial head
*/
int DeleteAll(position head)
{
    while (head->next != NULL)
    {
        DeleteNext(head);
    }

    return VOID_OK;
}


// ### PRIVATE FUNCTIONS ###

/*!
   \brief Insert node in polynomial
   \param Pointer to previous node,
   \pre Target node
   \return Integer describing how the function performed
*/
int InsertNode(position previous, const position target)
{
    target->next = previous->next;
    previous->next = target;

    return INSERT_OK;
}

/*!
   \brief Allocate memory for new node and fill it with data
   \param Target data
   \return Address of allocated memory
*/
position CreateNew(const element targetData)
{
    position target = NULL;
    target = (position) malloc(sizeof(targetData));
    if (target == NULL)
    {
        // Allocation failed;
        return NULL;
    }

    target->data = targetData;
    target->next = NULL;

    return target;
}

/*!
   \brief Delete next element after the specified
   \param Pointer to element which is previous of the element
          to be deleted
*/
int DeleteNext(position previous)
{
    position target = previous->next;
    previous->next = target->next;

    free(target);

    return VOID_OK;
}
