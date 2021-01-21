#ifdef ARRAY_BASED_QUEUE


#include "../include/queue.h"
void CreateQueue(Queue *PointerQueue)
{
    PointerQueue->Front = 0;
    PointerQueue->Rear = -1;
    PointerQueue->Size = 0;
}

bool QueueEmpty(Queue* PointerQueue)
{
    return PointerQueue->Size==0;

}
bool QueueFull(Queue* PointerQueue)
{
    return PointerQueue->Size==max_length;

}

int  Enqueue(Queue* PointerQueue, int value)
{
    if(!QueueFull(PointerQueue))
    {
        PointerQueue->Rear= (PointerQueue->Rear+1)%max_length;
        PointerQueue->Size++;
        PointerQueue->elements[PointerQueue->Rear]=value;
    }
    else{
     return 0;
    }

}

int Dequeue(Queue* PointerQueue, int &ReturnValue)
{
    if(!QueueEmpty(PointerQueue))
       {
         ReturnValue= PointerQueue->Front;
         PointerQueue->Size--;
         PointerQueue->Front=(PointerQueue->Front+1)%max_length;
       }
    else{
      return 0;
    }
}

int QueueSize(Queue* PointerQueue)
{
    return PointerQueue->Size;
}

void ClearQueue(Queue* PointerQueue)
{
    PointerQueue->Front = 0;
    PointerQueue->Rear = -1;
    PointerQueue->Size = 0;
}


void TraverseQueue(Queue* PointerQueue, void(*PointerFuncation)(int)){

  for(int position=PointerQueue->Front,counter=0;counter<PointerQueue->Size;counter++,position++){
    (*PointerFuncation)(PointerQueue->elements[position]);
    position%=max_length;

  }
}






#else

#include "../include/queue.h"

void CreateQueue(Queue *PointerQueue) {
    PointerQueue->Front = NULL;
    PointerQueue->Rear = NULL;
    PointerQueue->Size = 0;
}
bool QueueEmpty(Queue* PointerQueue)
{
    return PointerQueue->Size==0;

}
bool QueueFull(Queue* PointerQueue)
{
    return false;

}

int Enqueue(int data, Queue* PointerQueue)
{

    QueueNode* TempPointer= new (nothrow) QueueNode();
    if(TempPointer){
	TempPointer->data = data;
	TempPointer->next = NULL;
	if(PointerQueue->Size==0) PointerQueue->Front=TempPointer;
	else PointerQueue->Rear->next = TempPointer;
	PointerQueue->Rear= TempPointer;
	PointerQueue->Size++;
    }
    else{
      return 0;
    }
}
int Dequeue(Queue* PointerQueue, int & value )
{
    if(!QueueEmpty(PointerQueue)){
        QueueNode* TempPointer = PointerQueue->Front;
        value=PointerQueue->Front->data;
        PointerQueue->Front= PointerQueue->Front->next;
        delete TempPointer;
        if(!PointerQueue->Front) PointerQueue->Rear=NULL;
        PointerQueue->Size--;
    }
	 else{
        return 0;
	 }
}
int QueueSize(Queue* PointerQueue)
{
    return PointerQueue->Size;
}

void ClearQueue(Queue* PointerQueue)
{
     QueueNode* TempPointer;
   for(TempPointer=PointerQueue->Front;TempPointer!=NULL;TempPointer=TempPointer->next)
    delete TempPointer;
   PointerQueue->Front=NULL;
   PointerQueue->Rear=NULL;
   PointerQueue->Size=0;
}


void TraverseQueue(Queue* PointerQueue, void(*PointerFuncation)(int)){

   for( QueueNode* TempPointer=PointerQueue->Front;TempPointer!=NULL;TempPointer=TempPointer->next)
    (*PointerFuncation)(TempPointer->data);
}


#endif // ARRAY_BASED_QUEUE
