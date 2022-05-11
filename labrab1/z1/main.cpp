#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int *Array = new int[50000000];
    int *arrEvens = new int[50000000];
    int *arrOdds = new int[50000000];

    int n, lengthEvens=0, lengthOdds=0;
    cin >> n;

    for (int i=0; i<n; i++) {
        Array[i]= rand();
    }

    unsigned int timer_start = clock();

    for (int i=0; i<n; i++) {
        if (!(Array[i]%2)) {
            arrEvens[lengthEvens++]= Array[i];
        } else {
            arrOdds[lengthOdds++]= Array[i];
        }
    }

    unsigned int timer_stop = clock();

    cout << "Time - " << timer_stop-timer_start << "ms" << endl;

    return 0;
}
