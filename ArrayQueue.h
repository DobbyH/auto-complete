struct Queue;

struct Queue* constructor(int size);

int destructor(struct Queue* myQueue);

int isEmpty(struct Queue* myQueue);

int enqueue(struct Queue* myQueue, int value);

int dequeue(struct Queue* myQueue);

