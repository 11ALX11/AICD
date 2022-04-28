#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

/**     Variant 15
  *     Sort by count
  *
  *  SortByCount:
  *      for i = 0 to k
  *          C[i] = 0;
  *      for i = 0 to n - 1
  *          C[A[i]] = C[A[i]] + 1;
  *      b = 0;
  *      for j = 0 to k
  *          for i = 0 to C[j] - 1
  *              A[b] = j;
  *              b = b + 1;
  */

void sortByCount(int *A, int n, int k);

int main()
{
    int n;
    cin >> n;

    int *ArrayOfRandomInts = new int[n];

    // pceudo random ints
    for (int i=0; i<n; i++) {
        ArrayOfRandomInts[i] = rand() * (rand() % 3 + 1);
    }

    unsigned int time = clock();

    sortByCount(ArrayOfRandomInts, n, 100000);

    time = clock() - time;

    cout << "Time for sort: " << time/1000. << "s" << endl;

    delete ArrayOfRandomInts;
    return 0;
}

void sortByCount(int *A, int n, int k) {
    int C[k];
    for (int i=0; i<k; i++) C[i] = 0;

    for (int i=0; i<n; i++) C[A[i]]++;

    int b=0;
    for (int j=0; j<k; j++) {
        for (int i=0; i<C[j]; i++) {
            A[b] = j;
            b++;
        }
    }
}
