#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[100000];
vector<pair<int, pair<int, int>>> edges;
int INF;

void print_graf(int m);
void kruskal(int n, int m);
bool cmp(auto a, auto b);

int main() {

    //reading graph:
    fstream infile; //a.k.a. input file
    infile.open("graph.txt", ios::in); //visualization: http://graphonline.ru/?graph=viYjWJVEPlaQyuJc

    int n, m;
    infile >> n >> m;

    INF = 0;
    for (int i = 0; i < n; i++) {
        int u, v, w;
        infile >> u >> v >> w;
        u--, v--; //исправляем нумерацию с 1-ы

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});

        edges.push_back({w, {v, u}});

        INF+=w;
    }
    INF++;

    infile.close();
    //we done with reading graph

    kruskal(n, m);
    cout << "graph:\n";
    print_graf(m);
    cout << "Infinity is " << INF << endl;

    kruskal(n, m);

    return 0;
}

void print_graf(int m) {
    for (int i = 0; i < m; i++) {
        for (pair<int, int> v: graph[i]) {
            cout << i+1 << " " << v.first+1 << " " << v.second << endl;
        }
    }
}

void kruskal(int n, int m) {
    sort(edges.begin(), edges.end(), [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
        return a.first < b.first;
    });

    for (pair<int, pair<int, int>> edge: edges) {
        //...
    }
}
