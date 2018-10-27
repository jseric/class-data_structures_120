#include <stdio.h>

#include "external_dependencies.h"
#include "internal_dependencies.h"

// Function declarations
int PrintUserMenu(void);
int ClearScreen(void);
int GetUserMenuSelection(void);
int GetFileInsertMode(void);
int GetFileName(char*);

/*!
   \brief Display choices to user and get his feedback
   \post User has to provide a choice
   \return User menu selection
*/
int MenuIO(void)
{
    int target = 0;

    PrintUserMenu();
    target = GetUserMenuSelection();
    ClearScreen();

    return target;
}

/*!
   \brief Get node data from user
   \param Array of name,
          Array of surname,
          Pointer to int containing year of birth
   \post Insert node to list
*/
int GetNodeDataFromUser(char* name, char* surname, int* yearOfBirth)
{
    printf("Please enter the node data:\n");
    printf("Format: [firstName, lastName, yearOfBirth]\n");
    scanf(" %s %s %d", name, surname, yearOfBirth);

    return VOID_OK;
}

/*!
   \brief Get last name from user
   \param String to contain last name,
          String containing additional info for the user
*/
int GetLastName(char* target, char const* info)
{
    printf("Please enter the %s\n", info);
    scanf(" %s", target);

    return VOID_OK;
}


/*!
   \brief Print the contents of the list to console
   \param pointer to first node
*/
int PrintListToConsole(position current)
{
    // Check if list is empty
    if (current == NULL)
    {
        printf("WARNING!!! Cannot print contents of empty list!\n");
    }

    // Print data
    while (current != NULL)
    {
        printf("%s %s %d\n", current->name, current->surname, current->yearOfBirth);
        current = current->next;
    }

    return VOID_OK;
}

/*!
   \brief Print the contents of the list to a file
   \param pointer to first node
*/
int PrintListToFile(position current)
{
    FILE* file = NULL;
    char fileName[FILE_NAME_LENGTH] = "\0";

    // Check if list is empty
    if (current == NULL)
    {
        printf("WARNING!!! Cannot print contents of empty list!\n");
        return PRINT_EMPTY_LIST_WARNING;
    }

    // Get file name and open file
    GetFileName(fileName);
    file = fopen(fileName, "w");
    if (file == NULL)
    {
        // File not opened
        printf("WARNING!!! File could not be opened!\n");
        return PRINT_FILE_WARNING;
    }

    // Check if list is empty
    if (current == NULL)
    {
        printf("WARNING!!! Cannot print contents of empty list!\n");
        return PRINT_EMPTY_LIST_WARNING;
    }


    // Print data to file
    while (current != NULL)
    {
        fprintf(file, "%s %s %d\n",
        current->name, current->surname, current->yearOfBirth);

        current = current->next;
    }

    fclose(file);

    return PRINT_OK;
}

/*!
   \brief Read data from file and insert it to list
   \param Pointer to head
   \return int value defining the result of function execution
*/
int ReadDataFromFile(position head)
{
    int returnValue = 0;

    int insertMode = 0;
    position previous = NULL;

    char bufferLine[FILE_LINE_BUFFER_LENGTH] = "\0";

    char bufferName[NAME_LENGTH] = "\0";
    char bufferSurname[SURNAME_LENGTH] = "\0";
    int bufferYearOfBirth = 0;

    FILE* file = NULL;
    char fileName[FILE_NAME_LENGTH] = "\0";
    GetFileName(fileName);

    file = fopen(fileName, "r");
    if (file == NULL)
    {
        // File not opened
        printf("WARNING!!! File could not be opened!!!\n");
        return READ_FILE_WARNING;
    }

    insertMode = GetFileInsertMode();
    if (insertMode == USER_FILE_IN_ORDER)
    {
        previous = head;
    }
    else if (insertMode == USER_FILE_REVERSE_ORDER)
    {
        previous = FindLast(head);
    }
    else if (insertMode == USER_FILE_SORTED)
    {
        // First sort list
        Sort(head);
        previous = head;
    }
    else
    {
        // Unspecified insert mode
        printf("WARNING!!! Unspecified insert mode!!!\n");
        return PRINT_MODE_WARNING;
    }

    while (!feof(file))
    {
        // Reset the buffer values
        strcpy(bufferLine, "\0");

        strcpy(bufferName, "\0");
        strcpy(bufferSurname, "\0");
        bufferYearOfBirth = 0;

        // Read a line from file
        fgets(bufferLine, FILE_LINE_BUFFER_LENGTH - 1, file);
        if (strlen(bufferLine) > 0)
        {
            // Line contains data
            sscanf(bufferLine, " %s %s %d",
            bufferName, bufferSurname, &bufferYearOfBirth);

            // Insert to list
            if (insertMode == USER_FILE_IN_ORDER ||
                insertMode == USER_FILE_REVERSE_ORDER)
            {
                returnValue = Insert(previous, bufferName,
                bufferSurname, bufferYearOfBirth);
            }
            else if (insertMode == USER_FILE_SORTED)
            {
                returnValue = InsertSorted(previous, bufferName,
                    bufferSurname,
                    bufferYearOfBirth);
            }

            // Check if data was inserted correctly
            if (returnValue == INSERT_OK)
            {
                printf("A node was inserted successfully\n");
            }
            else if (returnValue == INSERT_ALLOC_FAILED)
            {
                printf("ERROR!!! Allocation failed!\n");
                fclose(file);
                return INSERT_ALLOC_FAILED;
            }

            // Update previous node
            if (insertMode == USER_FILE_IN_ORDER)
            {
                previous = previous->next;
            }
        }
    }

    fclose(file);
    return INSERT_OK;
}

// ### Private functions ###

/*!
   \brief Display user menu in consol
*/
int PrintUserMenu(void)
{
    printf("####################################\n");
    printf("# Insert to beginning ---------- %d #\n", USER_INSERT_BEGINNING);
    printf("# Insert to end ---------------- %d #\n", USER_INSERT_END);
    printf("# Insert before element -------- %d #\n", USER_INSERT_BEFORE);
    printf("# Insert after element --------- %d #\n", USER_INSERT_AFTER);
    printf("# Delete element --------------- %d #\n", USER_DELETE);
    printf("# Print list ------------------- %d #\n", USER_PRINT);
    printf("# Find element ----------------- %d #\n", USER_FIND);
    printf("# Read from file --------------- %d #\n", USER_FILE_READ);
    printf("# Print to file ---------------- %d #\n", USER_FILE_PRINT);
    printf("# Sort list -------------------- %d #\n", USER_SORT);
    printf("# Exit application ------------- %d #\n", USER_EXIT);
    printf("####################################\n\n\n\n");

    printf("Please enter your choice:\t");

    return VOID_OK;
}

/*!
   \brief Clear the console screen
*/
int ClearScreen(void)
{
    system(CLEAR_SCREEN);
    return VOID_OK;
}

/*!
   \brief Get user's selection
   \pre Display the menu to the user
   \post Clear the screen
   \return User's selection
*/
int GetUserMenuSelection(void)
{
    int target = 0;
    scanf(" %d", &target);
    return target;
}

/*!
   \brief Get insert mode from user
   \return Mode in which the nodes will be inserted from file
           (in order, in reverse order, sorted)
*/
int GetFileInsertMode(void)
{
    int target = 0;

    printf("Please enter the order in which the elements will be inserted:\n\n");

    printf("##############################\n");
    printf("# In order --------------- %d #\n", USER_FILE_IN_ORDER);
    printf("# In reverse order ------- %d #\n", USER_FILE_REVERSE_ORDER);
    printf("# Sorted ----------------- %d #\n", USER_FILE_SORTED);
    printf("##############################\n\n");

    printf("Please enter your choice:\t");
    scanf(" %d", &target);

    return target;
}

/*!
   \brief Get file name from the user
   \param String to contain file name
*/
int GetFileName(char* target)
{
    printf("Please enter the name of the file:\n");
    printf("Format: [fileName.txt]\n");
    scanf(" %s", target);

    return VOID_OK;
}
