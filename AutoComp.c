#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "TriesTree.h"

#define ASCII_A 65
#define ASCII_Z 90
#define ASCII_a 97
#define ASCII_z 122
#define ASCII_ESC 27
#define ASCII_BKSP 8
#define ASCII_TAB 9
#define ARRAYSIZE 62
#define MAXWORDLENGTH 20
#define ALPHABETSIZE 26

struct ArrayList
{
    int size;
    int capacity;
    struct TriesTree* rootNodes[ARRAYSIZE];
};

struct ArrayList* ArrayListConstructor()
{
    int i;
    struct ArrayList* arrayList;

    arrayList = malloc(sizeof(struct ArrayList));
    arrayList->capacity = ARRAYSIZE;
    arrayList->size = 0;

    i = 0;
    while(i < ARRAYSIZE)
    {
        arrayList->rootNodes[i] = 0;
        i++;
    }

    return arrayList;
};

void ArrayListDestructor(struct ArrayList* arrayList)
{
    //Build free function for TriesTree
    //Loop list and free tries trees;
   // FreeTrieTree();
    //Free arrayList;
    free(arrayList);
};

int ArrayListAdd(struct ArrayList* arrayList, int letter)
{
    if(arrayList->size >= arrayList->capacity)
    {
        return 0;
    }
    else
    {
        struct TriesTree* temp;
        temp = TriesTreeConstructor(letter);
        arrayList->rootNodes[arrayList->size] = temp;
        arrayList->size += 1;
        return 1;
    }
}

struct ArrayList* InitialiseDataStructure(struct ArrayList* Dictionary)
{
    int i;
    int counterOne = ASCII_a;
    int counterTwo = ASCII_A;
    for(i = 0; i < ALPHABETSIZE; i++)
    {
        ArrayListAdd(Dictionary, counterOne);
        ArrayListAdd(Dictionary, counterTwo);
        counterOne++;
        counterTwo++;
    }
    return Dictionary;
};

void InitialiseDictionary(struct TriesTree* myDictionary)
{
    FILE* myFile;
    char currentWord[MAXWORDLENGTH];

    myFile = fopen("words.txt", "r");

    if(myFile == NULL)
    {
        printf("Error: File not found.\n");
    }

    while(fgets(currentWord, sizeof(currentWord), myFile))
    {
        AddWord(myDictionary, currentWord, 0);
    }
}
