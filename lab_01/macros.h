/*!
   \file macros.h
   \brief File containing all the macros used in this lab
   \author Josip Seric
   \date 29/10/2018
*/

#ifndef MACROS_H
    #define MACROS_H

    /** struct person members macros */
    #define NAME_LENGTH    30
    #define SURNAME_LENGTH 30

    /** file name max length macro */
    #define FILE_NAME_LENGTH 50

    /** File line buffer length macro */
    #define FILE_LINE_BUFFER_LENGTH 256

    /** File reading functions macros */
    #define FILE_ROWS_EMPTY 0
    #define FILE_NOT_FOUND -1

    /** Macro for functions that can be void as well */
    #define VOID_OK 0

    /** Main return macros */
    #define EXIT_SUCCESS        0
    #define EXIT_EMPTY_FILE     0
    #define EXIT_FILE_NOT_FOUND 0
    #define EXIT_ERROR          0
    #define EXIT_ALLOC_FAILED   0

#endif
