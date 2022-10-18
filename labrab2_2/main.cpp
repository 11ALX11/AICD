#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[100000];
int INF;

void print_graf(int m);
void djk(int n, int m, int x);
void fluo(int n, int m);

int main()
{
    fstream infile;
    infile.open("graf.txt", ios::in); // visualization: http://graphonline.ru/en/?graph=qYVefuJsamaeaGmD

    int n, m;
    infile >> n >> m;

    INF = 0;
    for (int i = 0; i < n; i++) {
        int u, v, w;
        infile >> u >> v >> w;
        u--, v--; //исправляем нумерацию с 1-ы

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});

        INF+=w;
    }
    INF++;

    infile.close();
    //we done with reading graph

    cout << "graph:\n";
    print_graf(m);

    cout << "Infinity is " << INF << endl;

    int x;
    cout << "Djk:\nEnter vertex:\n";
    cin >> x;
    x--; //исправляем нумерацию с 1-ы
    djk(n, m, x);

    cout << "Fluo:\n";
    fluo(n, m);

    return 0;
}

void print_graf(int m) {
    for (int i = 0; i < m; i++) {
        for (pair<int, int> v: graph[i]) {
            cout << i+1 << " " << v.first+1 << " " << v.second << endl;
        }
    }
}

//Дейкстра
void djk(int n, int m, int start) {
    int ans[100000];
    int pr[100000];

    for (int i = 0; i < n; i++) {
        ans[i] = INF;
        pr[i] = -1;
    }

    ans[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({start, 0});

    while (!q.empty()) {
        pair<int, int> c = q.top();
        q.pop();

        int v = c.first, dst = c.second;

        if (ans[v] < dst) {
            continue;
        }

        for (pair<int, int> e: graph[v]) {
            int u = e.first, len_vu = e.second;

            int n_dst = dst + len_vu;
            if (n_dst < ans[u]) {
                ans[u] = n_dst;
                pr[u] = v;
                q.push({u, n_dst});
            }
        }
    }

    vector<int> path;
    for (int i = 0; i < m; i++) {
        int cur = i;
        path.push_back(cur);

        while (pr[cur] != -1) {
            cur = pr[cur];
            path.push_back(cur);
        }

        reverse(path.begin(), path.end());

        cout << "Shortest path between vertices " << start + 1 << " and " << i + 1 << " is: " << endl;

        for (int v: path) {
            cout << v + 1 << ", ";
        }
        cout << "path has length " << ans[i] << endl;

        path.clear();
    }
}

void fluo(int n, int m) {
    int dp[1000][1000];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }

    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        for (pair<int, int> e: graph[i]) {
            int v, len;
            v = e.first; len = e.second;
            dp[i][v] = dp[v][i] = len;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (j > i) {
                //опустим повторные пути и из i в i
                cout << "Shortest path between vertices " << i + 1 << " and " << j + 1 << " is: " << dp[i][j] << endl;
            }
        }
    }
}
