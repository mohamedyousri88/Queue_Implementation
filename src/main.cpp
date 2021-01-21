#include<iostream>
using namespace std;

#define ARRAY_BASED_QUEUE
#include "queue.cpp"


int main()
{
    Queue wow;
    CreateQueue(&wow);
    Enqueue(&wow,5);

    return 0;
}

