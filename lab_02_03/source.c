/*!
\file source.c
\brief File containing main() function
\author Josip Seric
\date 25/10/2018
*/

#include "external_dependencies.h"
#include "internal_dependencies.h"

int main(int argc, char** argv)
{
    int userInput = 0;
    int isRunning = 1;
    int returnValue = 0;

    person head;
    head.next = NULL;

    do
    {
        userInput = MenuIO();

        switch (userInput)
        {
        case USER_INSERT_BEGINNING:
            // Insert to beginning of list
            returnValue = InsertToBeginning(&head);
            if (returnValue == INSERT_OK)
            {
                printf("SUCCESS!!! Node inserted!!!\n");
            }
            else if (returnValue == INSERT_ALLOC_FAILED)
            {
                printf("Exiting program...\n");
                isRunning = 0;
            }
            break;

        case USER_INSERT_END:
            // Insert to end of list
            returnValue = InsertToEnd(&head);
            if (returnValue == INSERT_OK)
            {
                printf("SUCCESS!!! Node inserted!!!\n");
            }
            else if (returnValue == INSERT_ALLOC_FAILED)
            {
                printf("Exiting program...\n");
                isRunning = 0;
            }
            break;

        case USER_INSERT_BEFORE:
            // Insert node before the specified node
            returnValue = InsertBefore(&head);
            if (returnValue == INSERT_OK)
            {
                printf("SUCCESS!!! Node inserted!!!\n");
            }
            else if (returnValue == INSERT_ALLOC_FAILED)
            {
                printf("Exiting program...\n");
                isRunning = 0;
            }
            else if (returnValue == INSERT_NOT_FOUND)
            {
                printf("WARNING!!! Program will continue but be careful next time!\n");
            }
            break;

        case USER_INSERT_AFTER:
            // Insert node after the specified node
            returnValue = InsertAfter(&head);
            if (returnValue == INSERT_OK)
            {
                printf("SUCCESS!!! Node inserted!!!\n");
            }
            else if (returnValue == INSERT_ALLOC_FAILED)
            {
                printf("Exiting program...\n");
                isRunning = 0;
            }
            else if (returnValue == INSERT_NOT_FOUND)
            {
                printf("WARNING!!! Program will continue but be careful next time!\n");
            }
            break;

        case USER_DELETE:
            // Delete specified node
            returnValue = DeleteNode(&head);
            if (returnValue == DELETE_OK)
            {
                printf("SUCCESS!!! Node deleted!!!\n");
            }
            else if (returnValue == DELETE_NOT_FOUND)
            {
                printf("WARNING!!! Program will continue but be careful next time!\n");
            }
            break;

        case USER_PRINT:
            // Print the contents of the list
            PrintListToConsole(head.next);
            break;

        case USER_FIND:
            // Find the specified node
            returnValue = Find(&head);
            if (returnValue == FIND_OK)
            {
                printf("SUCCESS!!!\n");
            }
            else if (returnValue == FIND_NOT_FOUND)
            {
                printf("WARNING!!! Program will continue but be careful next time!\n");
            }
            break;

        case USER_FILE_READ:
            // Insert data from a file to the list
            returnValue = ReadDataFromFile(&head);
            if (returnValue == INSERT_OK)
            {
                printf("SUCCESS!!! All the nodes are inserted!!!\n");
            }
            else if (returnValue == INSERT_ALLOC_FAILED)
            {
                printf("Exiting program...\n");
                isRunning = 0;
            }
            break;

        case USER_FILE_PRINT:
            // Print the contents of the list to a file
            returnValue = PrintListToFile(head.next);
            if (returnValue == PRINT_OK)
            {
                printf("SUCCESS!!! Data printed to file!!!\n");
            }
            else if (returnValue == PRINT_FILE_WARNING)
            {
                printf("WARNING!!! Program will continue but be careful next time!\n");
            }
            else if (returnValue == PRINT_EMPTY_LIST_WARNING)
            {
                printf("WARNING!!! Program will continue but be careful next time!\n");
            }
            break;

        case USER_SORT:
            // Sort the list in ascending order by last name
            returnValue = Sort(&head);
            if (returnValue == SORT_OK)
            {
                printf("SUCCESS!!! Data sorted successfully!\n");
            }
            else if (returnValue == SORT_EMPTY_LIST)
            {
                printf("WARNING!!! Program will continue but be careful next time!\n");
            }
            else if (returnValue == SORT_SINGLE_ELEMENT)
            {
                printf("WARNING!!! Program will continue but be careful next time!\n");
            }
            break;

        case USER_EXIT:
            // Close the application
            printf("Closing the application...\n");
            isRunning = 0;
            break;

        default:
            printf("WARNING!!! Unknown input! Please try again\n");
        }
    } while(isRunning == 1);

    printf("Please wait until the program clears its data...\n");

    // Delete all nodes
    DeleteAll(&head);

    printf("Bye bye...\n");

    return EXIT_SUCCESS;
}
