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
        if (!(i%3)) {
            //0 3 6 9 12 15 18
            queue1.push(i);
        }
        else {
            //1 2 4 5 7 8 10 11 13 14 16 17 19
            queue2.push(i);
        }
    }

    int minimum;
    while (!queue1.empty() || !queue2.empty()) {
        if (queue1.front() < queue2.front()) {
            minimum = queue1.front();
            queue1.pop();
        }
        else {
            minimum = queue2.front();
            queue2.pop();
        }

        queueOut.push(minimum);

        if (queue1.empty()) {
            while (!queue2.empty()) {
                queueOut.push(queue2.front());
                queue2.pop();
            }
        }
        if (queue2.empty()) {
            while (!queue1.empty()) {
                queueOut.push(queue1.front());
                queue1.pop();
            }
        }
    }

    //0 1 2 3 4 5...
    for (int i=0; i<20; i++) {
        cout << queueOut.front() << " ";
        queueOut.pop();
    }
    cout << endl;

    return 0;
}
