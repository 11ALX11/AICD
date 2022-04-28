#include <iostream>
#include <ctime>

using namespace std;

/**     Variant 15
  *     Sort by inserts
  *
  *      for i = 2 to n do
  *          x = A[i]
  *          j = i
  *          while (int j > 1 and A[j-1] > x) do
  *              A[j] = A[j-1]
  *              j = j - 1
  *          end while
  *          A[j] = x
  *      end for
  */

void sortByInserts(int *A, int n);

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

    sortByInserts(ArrayOfRandomInts, n);

    time = clock() - time;

    cout << "Time for sort: " << time/1000. << "s" << endl;

    delete ArrayOfRandomInts;
    return 0;
}

void sortByInserts(int *A, int n) {
    for (int i=1; i<n; i++) {
        int x = A[i];
        int j = i;
        while (j > 0 && A[j-1] > x) {
            A[j] = A[j-1];
            j--;
        }
        A[j] = x;
    }
}
