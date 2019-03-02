#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct TriesTree
{
    char letter;
    struct TriesTree* sibling;
    struct TriesTree* child;
};

//Local Prototypes

struct TriesTree* MakeSibling(struct TriesTree* current, int letter);
struct TriesTree* MakeChild(struct TriesTree* current, int letter);
int CheckForChild(struct TriesTree* node);
int CheckForSibling(struct TriesTree* node);
struct TriesTree* SiblingLoopAndCompair(struct TriesTree* node, int letter);
int CheckLetter(int A, int B);
int FinishWord(struct TriesTree* node, char word[], int i);
int AddWord(struct TriesTree* node, char word[], int counter);

struct TriesTree* TriesTreeConstructor(int letter)
{
    struct TriesTree* tree;

    tree = malloc(sizeof(struct TriesTree));
    tree->child = NULL;
    tree->sibling = NULL;
    tree->letter = letter;

    return tree;
};


void TriesTreeDestructor(struct TriesTree* node)
{
    free(node);
};

struct TriesTree* MakeSibling(struct TriesTree* node, int letter)
{
    struct TriesTree* newSib = TriesTreeConstructor(letter);
    node->sibling = newSib;
    return node->sibling;
};

struct TriesTree* MakeChild(struct TriesTree* node, int letter)
{
    struct TriesTree* newChild = TriesTreeConstructor(letter);
    node->child = newChild;
    return node->child;
};

int CheckForChild(struct TriesTree* node)
{
    if(node->child == NULL)
    {
        return 0;
    }
    return 1;
};

int CheckForSibling(struct TriesTree* node)
{
    if(node->sibling == NULL)
    {
        return 0;
    }
    return 1;
};

//Takes in struct and loops through siblings, returns sibling with same letter or the finial sibling in list.
struct TriesTree* SiblingLoopAndCompair(struct TriesTree* node, int letter)
{
    struct TriesTree* temp;
    temp = node;
    while(temp->letter != letter)
    {
        if(temp->sibling == NULL)
        {
            return temp;
        }
        temp = temp->sibling;
    }
    return temp;
};

int CheckLetter(int A, int B)
{
    if(A == B)
    {
        return 1;
    }
    return 0;
};

int FinishWord(struct TriesTree* node, char word[], int i)
{
    struct TriesTree* temp;
    temp = node;
    while(i < strlen(word))
    {
        temp = MakeChild(temp, word[i]);
        i++;
    }
    return i;
};

int AddWord(struct TriesTree* node, char word[], int counter)
{
    int i = counter;
    struct TriesTree* temp;
    temp = node;

    while(i< strlen(word))
        {
            if(CheckLetter(temp->letter, word[i]))
            {
                if(CheckForChild(temp))
                {
                    i++;
                    i = AddWord(temp->child, word, i);
                }
                else
                {
                    i++;
                    i = FinishWord(temp, word, i);
                }
            }
            else
            {
                temp = SiblingLoopAndCompair(temp, word[i]);
                if(CheckLetter(temp->letter, word[i]))
                {
                    i++;
                    i = AddWord(temp->child, word, i);
                }
                else if(temp->sibling == NULL)
                {
                    temp = MakeSibling(temp, word[i]);
                    i++;
                    i = FinishWord(temp, word, i);
                }
            }
        }
        return i;
};

int DisplayAll(struct TriesTree* node, char string[], int i)
{

    if(CheckForSibling(node))
    {
        int q = i;
        DisplayAll(node->sibling, string, q);
    }
    string[i] = node->letter;
    if(CheckForChild(node))
    {
        i++;
        int q = i;
        DisplayAll(node->child, string, q);
    }
    else
    {
        printString(string);
    }
    return i;
}

void printString(char string[])
{
    int i = 0;
    while(string[i] != '\n')
    {
        printf("%c", string[i]);
        i++;
    }
    printf("\n");
}


int deBug(struct TriesTree* root)
{

}

int FreeTrieTree(struct TriesTree* node)
{

};

int RemoveWord(char word[]);

char SearchWord(struct TriesTree* tree);
