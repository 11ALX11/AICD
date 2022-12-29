#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    fstream infile;
    infile.open("backpack.txt", ios::in);

    int n, w;
    int items_cost[n];
    int items_weight[n];
    bool used[n];

    float items_cost_per_weight[n];

    infile >> n >> w;
    for (int i = 0; i < n; i++) {
        int tmp;
        used[i] = false;

        infile >> tmp;
        items_cost[i] = tmp;

        infile >> tmp;
        items_weight[i] = tmp;

        items_cost_per_weight[i] = items_cost[i] / items_weight[i];
    }

    //Жадный алгоритм

    int f_weight = 0;
    int f_cost = 0;
    for (int i = 0; i < n; i++) {
        int weight = 0;
        int cost = 0;
        float cost_per_weight = 0;
        int k = -1;

        for (int j = 0; j < n; j++) {
            if (!used[j]) {
                if (cost_per_weight < items_cost_per_weight[j]) {
                    weight = items_weight[j];
                    cost = items_cost[j];
                    cost_per_weight = items_cost_per_weight[j];
                    used[j] = true;
                    k = j;
                }
            }
        }

        if (w - f_weight >= weight && k >= 0) {
            f_weight += weight;
            f_cost += cost;
            used[k] = true;
        }
    }

    cout << "Greedy: " << f_cost << " best cost" << endl;

    //ДП

    int dp[n][w];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0) {
                if (j-items_weight[i]+1 >= 0) {
                    dp[i][j] = items_cost[i];
                }
                else {
                    dp[i][j] = 0;
                }
            }
            else {
                if (j-items_weight[i]+1 >= 0) {
                    if (j-items_weight[i]+1 > 0) dp[i][j] = max(items_cost[i] + dp[i-1][j-items_weight[i]], dp[i-1][j]);
                    if (j-items_weight[i]+1 == 0) dp[i][j] = max(items_cost[i], dp[i-1][j]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }

    cout << "DP: " << dp[n-1][w-1] << " best cost" << endl;

    return 0;
}
