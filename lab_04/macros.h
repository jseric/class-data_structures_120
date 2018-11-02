/*!
   \file macros.h
   \brief File containing all the macros used in this lab
   \author Josip Seric
   \date 24/10/2018
*/

#ifndef MACROS_H
    #define MACROS_H

    /** file name max length macro */
    #define FILE_NAME_LENGTH 50

    /** File line buffer length macro */
    #define FILE_LINE_BUFFER_LENGTH 256

    /** Read function return macros */
    #define READ_OK           0
    #define READ_FILE_WARNING 1

    /** Insert functions return macros */
    #define INSERT_OK            0
    #define INSERT_EMPTY_POLYS   1
    #define INSERT_ALLOC_FAILED -1

    /** Macro for functions that can be void as well */
    #define VOID_OK 0

    /** Main return macros */
    #define EXIT_SUCCESS      0
    #define EXIT_WITH_WARNING 0
    #define EXIT_WITH_ERROR   0

#endif
