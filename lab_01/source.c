/*!
\file source.c
\brief File containing main() function
\author Josip Seric
\date 29/10/2018
*/

#include "external_dependencies.h"
#include "internal_dependencies.h"

int main(int argc, char** argv)
{
    person* data = NULL;
    int dataSize = 0;

    char fileName[FILE_NAME_LENGTH] = "\0";

    double maxAbsoluteGrade = 0.0;

    dataSize = CountRowsInFile(fileName);
    if (dataSize > 0)
    {
        printf("Rows counted!\n");
        printf("There are %d rows\n", dataSize);
    }
    else if (dataSize == FILE_ROWS_EMPTY)
    {
        printf("WARNING!!! There is no data in file!\n");
        printf("Exiting application...\n");
        return EXIT_EMPTY_FILE;
    }
    else if (dataSize == FILE_NOT_FOUND)
    {
        printf("WARNING!!! File not found!\n");
        printf("Exiting application...\n");
        return EXIT_FILE_NOT_FOUND;
    }
    else
    {
        printf("ERROR!!! Unknown error occured!\n");
        printf("Exiting application...\n");
        return EXIT_ERROR;
    }

    data = CreateArray(dataSize);
    if (data == NULL)
    {
        printf("ERROR!!! Allocation failed\n");
        printf("Exiting application...\n");
        return EXIT_ALLOC_FAILED;
    }
    else
    {
        printf("Memory reserved successfully!\n");
    }

    maxAbsoluteGrade = ReadDataFromFile(data, fileName);
    if (maxAbsoluteGrade > 0)
    {
        printf("Data read successfully!\n");
        printf("Max absolute grade is %lf\n", maxAbsoluteGrade);
    }
    else if (maxAbsoluteGrade == (double) FILE_NOT_FOUND)
    {
        printf("WARNING!!! File not found!\n");
        printf("Exiting application...\n");
        return EXIT_FILE_NOT_FOUND;
    }

    CalculateRelativeGrade(data, dataSize, maxAbsoluteGrade);

    PrintDataToConsole(data, dataSize);

    DeleteData(data);

    return EXIT_SUCCESS;
}
