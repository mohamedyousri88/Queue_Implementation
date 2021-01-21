#ifdef ARRAY_BASED_QUEUE
//#include<iostream>
const int max_length=1000;
 struct Queue
{
    int elements[max_length];
    int Front;
    int Rear;
    int Size;
};

void CreateQueue(Queue *PointerQueue);

bool QueueEmpty(Queue* PointerQueue);

bool QueueFull(Queue* PointerQueue);

int  Enqueue(Queue* PointerQueue, int value);


int Dequeue(Queue* PointerQueue, int &ReturnValue);


int QueueSize(Queue* PointerQueue);

void ClearQueue(Queue* PointerQueue);


void TraverseQueue(Queue* PointerQueue, void(*PointerFuncation)(int));




#else

//#include<iostream>

struct QueueNode
{
	int data;
	struct QueueNode* next;
};

struct Queue{
    QueueNode* Front;
    QueueNode* Rear;
    int Size;
};

void CreateQueue(Queue *PointerQueue);

bool QueueEmpty(Queue* PointerQueue);

bool QueueFull(Queue* PointerQueue);

int Enqueue(int data, Queue* PointerQueue);

int Dequeue(Queue* PointerQueue, int & value );

int QueueSize(Queue* PointerQueue);

void ClearQueue(Queue* PointerQueue);

void TraverseQueue(Queue* PointerQueue, void(*PointerFuncation)(int));



#endif // ARRAY_BASED_QUEUE
