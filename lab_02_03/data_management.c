#include "external_dependencies.h"
#include "internal_dependencies.h"

/*!
   \brief Create new node and fill it with data
   \pre Find the place to insert the node and
        get data for filling
   \post Insert the node
   \return Allocated and filled node
          (if allocation failed, return NULL)
*/
position CreateNewElement(char const* name, char const* surname,
                          const int yearOfBirth)
{
  position target = NULL;

  // Allocate node
  target = (position) malloc(sizeof(person));
  if (target == NULL)
  {
    printf("ERROR!!! Allocation failed!!!\n");
    return NULL;
  }

  // Fill node with data
  strcpy(target->name, name);
  strcpy(target->surname, surname);
  target->yearOfBirth = yearOfBirth;

  target->next = NULL;

  return target;
}
