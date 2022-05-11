#include <iostream>
#include <list>

using namespace std;

int main()
{
    //We have 2 lists with elements (we shall define elements as int)
    list<int> list1;
    list<int> list2;
    list<int> listOut;
    
    for (int i=0; i<20; i++) {
        if (i<10) {
            //0 1 2 3...
            list1.push_back(i);
        }
        else {
            //10 11 12 13...
            list2.push_back(i);
        }
    }
    
    for (int i=0; i<20; i++) {
        if (!(i%2)) {
            listOut.push_back(list1.front());
            list1.pop_front();
        }
        else {
            listOut.push_back(list2.front());
            list2.pop_front();
        }
    }
    
    for (auto elem : listOut) {
        cout << (elem) << " ";
    }
    cout << endl;
    
    return 0;
}
