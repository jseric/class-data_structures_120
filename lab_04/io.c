/*!
   \file io.c
   \brief File containing IO (Input-Output) functions
   \author Josip Seric
   \date 01/11/2018
*/

#include "external_dependencies.h"
#include "internal_dependecies.h"

// Function declarations
int GetFileNameFromUser(char*);

/*!
   \brief Read polynomial from file
   \param Pointer to head of polynomial
   \return Integer describing how the function performed
*/
int ReadFromFile(position head)
{
    element buffer = { 0, 0 };
    char bufferLine[FILE_LINE_BUFFER_LENGTH] = "\0";

    FILE* file = NULL;
    char fileName[FILE_NAME_LENGTH] = "\0";

    int returnValue = 0;

    // Get file name and open file
    GetFileNameFromUser(fileName);
    file = fopen(fileName, "r");
    if (file == NULL)
    {
        // File failed to open
        printf("WARNING!!! File doesn't exist!\n");
        return READ_FILE_WARNING;
    }

    // Read data
    while (!feof(file))
    {
        // Clear the buffer line
        strcpy(bufferLine, "\0");

        // Read a line
        fgets(bufferLine, FILE_LINE_BUFFER_LENGTH - 1, file);
        if (strlen(bufferLine) > 0)
        {
            // There is data in the read line

            sscanf(bufferLine, " %d %d", &buffer.coefficient,
                                         &buffer.exponent);

            returnValue = Insert(head, buffer);
            if (returnValue == INSERT_OK)
            {
                // Everything went ok
            }
            else if (returnValue == INSERT_ALLOC_FAILED)
            {
                return INSERT_ALLOC_FAILED;
            }
        }
    }

    fclose(file);
    return READ_OK;
}

/*!
   \brief Print polynomial to console
   \param Pointer to first element of polynomial
*/
int PrintDataToConsole(position current)
{
    if (current == NULL)
    {
        printf("WARNING!!! Polynomial is empty!\n");
        return VOID_OK;
    }

    while (current != NULL)
    {
        if (current->data.coefficient != 0)
        {
            // Dont print if coefficient is 0

            printf("%d * X^%d ", current->data.coefficient,
                                  current->data.exponent);
        }

        current = current->next;

        if (current != NULL &&
            current->data.coefficient > 0)
        {
            // Add + sign if there is the next element
            // and if that element's coefficient is > 0
            printf("+");
        }
    }
    printf("\n");

    return VOID_OK;
}


// ### PRIVATE FUNCTIONS ###

/*!
   \brief Get file name from user
   \param Array to contain file name
*/
int GetFileNameFromUser(char* fileName)
{
    printf("Please enter the file name:\n");
    printf("Format: [filename.txt]\n");
    scanf(" %s", fileName);

    return VOID_OK;
}
