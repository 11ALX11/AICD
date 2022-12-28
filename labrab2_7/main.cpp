#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream infile; //a.k.a. input file
    infile.open("ladder.txt", ios::in);

    int n;
    infile >> n;

    int ladder[n];

    for (int i = 0; i < n; i++) {
        int tmp;
        infile >> tmp;
        ladder[i] = tmp;
    }

    int dp[n];
    dp[0] = ladder[0];
    dp[1] = ladder[1];
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i-1], dp[i-2]) + ladder[i];
        cout << "dp[" << i << "] = " << dp[i] << endl;
    }

    cout << min(dp[n-1], dp[n-2]) << endl;

    return 0;
}
