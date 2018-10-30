/*!
   \file io.c
   \brief File containing IO (Input-Output) functions
   \author Josip Seric
   \date 24/10/2018
*/

#include "external_dependencies.h"
#include "internal_dependencies.h"

// Function declarations
int GetFileName(char*);

/*!
   \brief Count number of rows in file
   \param Array to store file name
   \return Number of rows containing data
*/
int CountRowsInFile(char* fileName)
{
    int numberOfRows = 0;

    char bufferLine[FILE_LINE_BUFFER_LENGTH] = "\0";
    FILE* file = NULL;

    GetFileName(fileName);

    // Open file
    file = fopen(fileName, "r");
    if (file == NULL)
    {
        // File could not be opened
        return FILE_NOT_FOUND;
    }

    // Count rows
    while (!feof(file))
    {
        strcpy(bufferLine, "\0");

        // Read a line
        fgets(bufferLine, FILE_LINE_BUFFER_LENGTH - 1, file);
        if (strlen(bufferLine) > 0)
        {
            // Row is not empty
            numberOfRows++;
        }
    }

    fclose(file);

    return numberOfRows;
}

/*!
   \brief Read data from file and get max absolute grade
   \param Array of person data,
   \pre Allocated memory
   \return Max absolute grade
*/
double ReadDataFromFile(person* data, char const* fileName)
{
    double maxAbsoluteGrade = 0.0;
    unsigned int i = 0;

    char bufferLine[FILE_LINE_BUFFER_LENGTH] = "\0";
    FILE* file = NULL;

    // Open file
    file = fopen(fileName, "r");
    if (file == NULL)
    {
        // File could not be opened
        return FILE_NOT_FOUND;
    }

    // Count rows
    while (!feof(file))
    {
        strcpy(bufferLine, "\0");

        // Read a line
        fgets(bufferLine, FILE_LINE_BUFFER_LENGTH - 1, file);
        if (strlen(bufferLine) > 0)
        {
            // Read data from line
            sscanf(bufferLine, " %s %s %lf",
                   data[i].name,
                   data[i].surname,
                   &data[i].absoluteGrade);

            if (data[i].absoluteGrade > maxAbsoluteGrade)
            {
                // Found new max absolute grade
                maxAbsoluteGrade = data[i].absoluteGrade;
            }

            i++;
        }
    }

    fclose(file);

    return maxAbsoluteGrade;
}

/*!
   \brief Print out data in console
   \param Array of person data,
          Integer containing size of data
   \pre Data must exist
*/
int PrintDataToConsole(person* data, const int dataSize)
{
    int i = 0;
    for (i = 0; i < dataSize; i++)
    {
        printf("%d) %s %s %lf %lf\n",
               i + 1,
               data[i].name,
               data[i].surname,
               data[i].absoluteGrade,
               data[i].relativeGrade);
    }

    return VOID_OK;
}

// ### PRIVATE METHODS ###

/*!
   \brief Get file name from user
   \param String to contain file name
*/
int GetFileName(char* fileName)
{
    printf("Please enter the file name:\n");
    printf("Format: [filename.txt]\n");
    scanf(" %s", fileName);

    return VOID_OK;
}
