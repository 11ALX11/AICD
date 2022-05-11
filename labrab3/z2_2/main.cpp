#include <iostream>
#include <list>

using namespace std;

int main()
{
    const int INFINITY = 30;
    
    //We have 2 lists with elements (we shall define elements as int)
    list<int> list1;
    list<int> list2;
    list<int> listOut;
    
    for (int i=0; i<20; i++) {
        if (!(i%3)) {
            //0 2 4 6...
            list1.push_back(i);
        }
        else {
            //1 3 5 7...
            list2.push_back(i);
        }
    }
    
    int minimum;
    auto list1_idx = list1.begin();
    auto list2_idx = list2.begin();
    int list1_elem = *list1_idx;
    int list2_elem = *list2_idx;

    while (list1_idx != list1.end() || list2_idx != list2.end()) {
        if (list1_elem < list2_elem) {
            minimum = list1_elem;
            list1_idx++;
            if (list1_idx == list1.end()) {
                list1_elem = INFINITY;
            }
            else {
                list1_elem = *list1_idx;
            }
        }
        else {
            minimum = list2_elem;
            list2_idx++;
            if (list2_idx == list2.end()) {
                list2_elem = INFINITY;
            }
            else {
                list2_elem = *list2_idx;
            }
        }
        
        listOut.push_back(minimum);
    }
    
    for (auto elem : listOut) {
        cout << (elem) << " ";
    }
    cout << endl;
    
    return 0;
}
