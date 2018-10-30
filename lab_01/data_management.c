/*!
   \file data_management.c
   \brief File containing memory management functions
   \author Josip Seric
   \date 30/10/2018
*/

#include "external_dependencies.h"
#include "internal_dependencies.h"

/*!
   \brief Allocate memory for array
   \param Integer containing size of array to be allocated
   \return Pointer to allocated array memory
*/
person* CreateArray(const int size)
{
    person* data = NULL;
    data = (person*) malloc(size * sizeof(person));

    // Data allocation check is not necessary here,
    // because it is being checked in main,
    // but this method can be called somewhere else,
    // and we don't know if the check will be performed there
    if (data == NULL)
    {
        return NULL;
    }

    return data;
}

/*!
   \brief Deallocate memory
   \param Pointer to memory to be deallocated
   \pre Memory must be allocated
*/
int DeleteData(person* data)
{
    free(data);

    return VOID_OK;
}
