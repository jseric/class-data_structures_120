/*!
\file source.c
\brief File containing main() function
\author Josip Seric
\date 30/10/2018
*/

#include "external_dependencies.h"
#include "internal_dependecies.h"

int main(int argc, char** argv)
{
    int returnValue = 0;

    polynomial poly1;
    polynomial poly2;

    polynomial sum;
    polynomial mul;

    // Init empty polynomials
    poly1.next = NULL;
    poly2.next = NULL;
    sum.next  = NULL;
    mul.next  = NULL;

    // Load 1st polynomial
    returnValue = ReadFromFile(&poly1);
    if (returnValue == READ_OK)
    {
        printf("Data read from 1st file!\n");
    }
    else if (returnValue == READ_FILE_WARNING)
    {
        printf("Exiting program\n");
        return EXIT_WITH_WARNING;
    }
    else if (returnValue == INSERT_ALLOC_FAILED)
    {
        printf("Exiting program\n");
        return EXIT_WITH_ERROR;
    }

    // Load 2nd polynomial
    returnValue = ReadFromFile(&poly2);
    if (returnValue == READ_OK)
    {
        printf("Data read from 2nd file!\n");
    }
    else if (returnValue == READ_FILE_WARNING)
    {
        printf("Exiting program\n");
        DeleteAll(&poly1);

        return EXIT_WITH_WARNING;
    }
    else if (returnValue == INSERT_ALLOC_FAILED)
    {
        printf("Exiting program\n");
        DeleteAll(&poly1);

        return EXIT_WITH_ERROR;
    }

    PrintDataToConsole(poly1.next);
    PrintDataToConsole(poly2.next);

    returnValue = Sum(&sum,
                      poly1.next,
                      poly2.next);
    if (returnValue == INSERT_OK)
    {
      printf("Polynomial sum calculated successfully!\n");
    }
    else if (returnValue == INSERT_EMPTY_POLYS)
    {
      printf("Exiting program\n");
      return EXIT_WITH_WARNING;
    }
    else if (returnValue == INSERT_ALLOC_FAILED)
    {
      printf("Exiting program\n");
      DeleteAll(&poly1);
      DeleteAll(&poly2);

      return EXIT_WITH_ERROR;
    }

    PrintDataToConsole(sum.next);
    DeleteAll(&sum);

    returnValue = Multiplicate(&mul,
                               poly1.next,
                               poly2.next);
    if (returnValue == INSERT_OK)
    {
        printf("Polynomial multiplication product calculated successfully!\n");
    }
    else if (returnValue == INSERT_EMPTY_POLYS)
    {
        printf("Exiting program\n");
        return EXIT_WITH_WARNING;
    }
    else if (returnValue == INSERT_ALLOC_FAILED)
    {
        printf("Exiting program\n");
        DeleteAll(&poly1);
        DeleteAll(&poly2);

        return EXIT_WITH_ERROR;
    }

    PrintDataToConsole(mul.next);
    DeleteAll(&mul);

    DeleteAll(&poly1);
    DeleteAll(&poly2);

    return 0;
}
