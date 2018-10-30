/*!
   \file helper_methods.c
   \brief File containing various helper functions
   \author Josip Seric
   \date 30/10/2018
*/

#include "external_dependencies.h"
#include "internal_dependencies.h"

/*!
   \brief Calculate relative grade for every person
   \param Pointer to array of data,
          Integer containing size od array
          Double containing maximum absolute grade
   \pre "Pre-conditions"
   \post "Post-conditions"
   \return "Return of the function"
*/
int CalculateRelativeGrade(person* data,
                           const int dataSize,
                           const double maxAbsoluteGrade)
{
    unsigned i = 0;
    for (i = 0; i < dataSize; i++)
    {
        // Relative = (absolute / max) * 100
        data[i].relativeGrade =
            (data[i].absoluteGrade / maxAbsoluteGrade) *
            100.0;
    }

    return VOID_OK;
}
