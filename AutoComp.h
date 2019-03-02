struct ArrayList;

struct ArrayList* ArrayListConstructor();

void ArrayListDestructor(struct ArrayList* arrayList);

int ArrayListAdd(struct ArrayList* arrayList, int letter);

//may not be needed!
void ArrayListDisplay(struct ArrayList* arrayList);

//Sort
void FreeDataStructure(struct ArrayList* dictionary);

struct ArrayList* InitialiseDataStructure(struct ArrayList* Dictionary);

void InitialiseDictionary(struct ArrayList* myDictionary);
