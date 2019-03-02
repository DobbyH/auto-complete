#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "ArrayList.h"
#include "ArrayQueue.h"

#define TOTALCHARACTERS 62
#define MAXWORDLENGTH 20
#define TRUE 1
#define FALSE 0
#define ASCII_A 65
#define ASCII_Z 90
#define ASCII_a 97
#define ASCII_z 122
#define ASCII_ESC 27
#define ASCII_BKSP 8
#define ASCII_TAB 9
#define ARRAYSIZE 62

int main(void)
{
 //   char wordOut[MAXWORDLENGTH];

    struct ArrayList* Dictionary;
    Dictionary = ArrayListConstructor(TOTALCHARACTERS);
    Dictionary = InitialiseDataStructure(Dictionary);

    //InitialiseDictionary(Dictionary);

    int input = 0;
    while(1)
    {
        input = getch();
        while(input != FALSE)
        {
            if(input == ASCII_TAB)
            {
                printf("TAB\n");
            }
            else if(input == ASCII_BKSP)
            {
                printf("BKSP");
            }
            else if((input >= ASCII_A && input <= ASCII_Z) || (input >= ASCII_a && input <= ASCII_z))
            {
                printf("%c", input);
            }
            else if(input == ASCII_ESC)
            {
                printf("\nProgram Closing.\n");
                return 0;
            }
            input = FALSE;
        }
    }
    return 0;
}
