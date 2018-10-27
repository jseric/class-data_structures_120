/*!
   \file macros.h
   \brief File containing all the macros used in this lab
   \author Josip Seric
   \date 24/10/2018
*/

#ifndef MACROS_H
    #define MACROS_H

    /** Screen clear macro for Windows, Linux and Mac */
    #ifdef _WIN32
        #define CLEAR_SCREEN "cls"
    #else
        #define CLEAR_SCREEN "clear"
    #endif

    /** struct person members macros */
    #define NAME_LENGTH    30
    #define SURNAME_LENGTH 30

    /** file name max length macro */
    #define FILE_NAME_LENGTH 50

    /** File line buffer length macro */
    #define FILE_LINE_BUFFER_LENGTH 256

    /** User menu selection macros */
    #define USER_INSERT_BEGINNING 1
    #define USER_INSERT_END       2
    #define USER_INSERT_BEFORE    3
    #define USER_INSERT_AFTER     4
    #define USER_DELETE           5
    #define USER_PRINT            6
    #define USER_FIND             7
    #define USER_FILE_READ        8
    #define USER_FILE_PRINT       9
    #define USER_SORT             10
    #define USER_EXIT            -1

    /** File insert mode macros */
    #define USER_FILE_IN_ORDER      1
    #define USER_FILE_REVERSE_ORDER 2
    #define USER_FILE_SORTED        3

    /** Insert functions return macros */
    #define INSERT_OK            0
    #define INSERT_NOT_FOUND     1
    #define INSERT_ALLOC_FAILED -1

    /** Print functions return macros */
    #define PRINT_OK                   0
    #define PRINT_FILE_WARNING         1
    #define PRINT_MODE_WARNING         2
    #define PRINT_EMPTY_LIST_WARNING   3

    /** Delete functions return macros */
    #define DELETE_OK        0
    #define DELETE_NOT_FOUND 1

    /** Find functions return macros */
    #define FIND_OK        0
    #define FIND_NOT_FOUND 1

    /** Read function return macros */
    #define READ_OK           0
    #define READ_FILE_WARNING 1

    /** Sort function return macros */
    #define SORT_OK             0
    #define SORT_EMPTY_LIST     1
    #define SORT_SINGLE_ELEMENT 2

    /** Macro for functions that can be void as well */
    #define VOID_OK 0

    /** Main return macros */
    #define EXIT_SUCCESS 0

#endif
