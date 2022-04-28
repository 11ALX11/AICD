#include <iostream>
#include <ctime>

using namespace std;

/**     Variant 15
  *     Sort Xoara
  *
  *  quicksort(A, low, high) is
  *      if low < high then
  *          p := pivot(A, low, high)
  *          left, right := partition(A, p, low, high)
  *          quicksort(A, low, left)
  *          quicksort(A, right, high)
  */

void XoarSort(int* a, int first, int last);

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

    XoarSort(ArrayOfRandomInts, 0, n-1);

    time = clock() - time;

    cout << "Time for sort: " << time/1000. << "s" << endl;

    delete ArrayOfRandomInts;
    return 0;
}

void XoarSort(int* a, int first, int last) {
    int i = first, j = last;
    int tmp, x = a[(first + last) / 2];

    do {
        while (a[i] < x) i++;
        while (a[j] > x) j--;

        if (i <= j) {
            if (i < j) {
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
            i++; j--;
        }
    } while (i <= j);

    if (i < last)
    XoarSort(a, i, last);
    if (first < j)
    XoarSort(a, first,j);
}
