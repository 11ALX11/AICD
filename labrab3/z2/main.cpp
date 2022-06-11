#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    //We have 2 queues with elements (we shall define elements as int)
    struct node* queue1 = nullptr;
    struct node* queue2 = nullptr;
    struct node* queueOut = nullptr;

    for (int i=0; i<20; i++) {
        if (i<10) {
            //0 1 2 3...
            push(&queue1, i);
        }
        else {
            //10 11 12 13...
            push(&queue2, i);
        }
    }

    for (int i=0; i<20; i++) {
        if (!(i%2)) {
            push(&queueOut, front(queue1));
            pop(&queue1);
        }
        else {
            push(&queueOut, front(queue2));
            pop(&queue2);
        }
    }

    for (int i=0; i<20; i++) {
        cout << front(queueOut) << " ";
        pop(&queueOut);
    }
    cout << endl;

    return 0;
}
