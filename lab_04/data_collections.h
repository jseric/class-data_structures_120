/*!
   \file data_collections.h
   \brief File containing all the data types and collections used in this lab
   \author Josip Seric
   \date 31/10/2018
*/

#ifndef DATA_COLLECTIONS_H
    #define DATA_COLLECTIONS_H

    #include "internal_dependecies.h"

    struct _element;
    typedef struct _element element;
    struct _element
    {
        int coefficient;
        int exponent;
    };

    struct _polynomial;
    typedef struct _polynomial polynomial;
    typedef struct _polynomial* position;
    struct _polynomial
    {
        element data;
        position next;
    };

#endif
