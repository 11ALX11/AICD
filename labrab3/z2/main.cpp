#include <iostream>
#include <queue>

using namespace std;

int main()
{
    //We have 2 queues with elements (we shall define elements as int)
    queue<int> queue1;
    queue<int> queue2;
    queue<int> queueOut;

    for (int i=0; i<20; i++) {
        if (i<10) {
            //0 1 2 3...
            queue1.push(i);
        }
        else {
            //10 11 12 13...
            queue2.push(i);
        }
    }

    for (int i=0; i<20; i++) {
        if (!(i%2)) {
            queueOut.push(queue1.front());
            queue1.pop();
        }
        else {
            queueOut.push(queue2.front());
            queue2.pop();
        }
    }

    for (int i=0; i<20; i++) {
        cout << queueOut.front() << " ";
        queueOut.pop();
    }
    cout << endl;

    return 0;
}
