/*!
   \file data_collections.h
   \brief File containing all the data types and collections used in this lab
   \author Josip Seric
   \date 24/10/2018
*/

#ifndef DATA_COLLECTIONS_H
    #define DATA_COLLECTIONS_H

    #include "internal_dependencies.h"

    struct _personData;
    typedef struct _personData personData;
    struct _personData
    {
        char name[NAME_LENGTH];
        char surname[SURNAME_LENGTH];
        int yearOfBirth;
    };

    struct _person;
    typedef struct _person person;
    typedef person* position;
    struct _person
    {
        personData data;
        position next;
    };

#endif
