#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int n, Array[50000000];
int arrEvens[50000000];
int arrOdds[50000000];

int main()
{
    int lengthEvens=0, lengthOdds=0;

    cin >> n;

    for (int i=0; i<n; i++) {
        Array[i]= rand();
    }

    unsigned int timer_start = clock();

    for (int i=0; i<n; i++) {
        if (Array[i]%2) {
            arrEvens[lengthEvens++]= Array[i];
        } else {
            arrOdds[lengthOdds++]= Array[i];
        }
    }

    unsigned int timer_stop = clock();

    //for (int i=0; i<lengthEvens; i++) cout << arrEvens[i] << " "; cout << endl;
    //for (int i=0; i<lengthOdds; i++) cout << arrOdds[i] << " "; cout << endl;
    cout << "Time - " << timer_stop-timer_start << "ms" << endl;

    return 0;
}
