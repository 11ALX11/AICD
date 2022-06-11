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
        if (!(i%3)) {
            //0 3 6 9 12 15 18
            push(&queue1, i);
        }
        else {
            //1 2 4 5 7 8 10 11 13 14 16 17 19
            push(&queue2, i);
        }
    }

    int minimum;
    while (!empty(queue1) || !empty(queue2)) {
        if (front(queue1) < front(queue2)) {
            minimum = front(queue1);
            pop(&queue1);
        }
        else {
            minimum = front(queue2);
            pop(&queue2);
        }

        push(&queueOut, minimum);

        if (empty(queue1)) {
            while (!empty(queue2)) {
                push(&queueOut, front(queue2));
                pop(&queue2);
            }
        }
        if (empty(queue2)) {
            while (!empty(queue1)) {
                push(&queueOut, front(queue1));
                pop(&queue1);
            }
        }
    }

    //0 1 2 3 4 5...
    for (int i=0; i<20; i++) {
        cout << front(queueOut) << " ";
        pop(&queueOut);
    }
    cout << endl;

    return 0;
}
