#define ASCII_A 65
#define ASCII_Z 90
#define ASCII_a 97
#define ASCII_z 122
#define ASCII_ESC 27
#define ASCII_BKSP 8
#define ASCII_TAB 9

struct TriesTree;

struct TriesTree* TriesTreeConstructor(int letter);

void TriesTreeDestructor(struct TriesTree* root);

int AddWord(struct TriesTree* root,char word[], int counter);

int RemoveWord(char word[]);

int DisplayAll(struct TriesTree* node, char string[], int i);

char SearchWord(struct TriesTree* tree);

int FreeTrieTree(struct TriesTree* node);

//May not be needed
int getLetterFromTriesTree(struct TriesTree* tree);
