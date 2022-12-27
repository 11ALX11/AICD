#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[100000];
vector<pair<int, pair<int, int>>> edges;
int INF;

int p[100000];
int rk[100000];

void print_graf(int m);
void kruskal(int n, int m);
void prima();

bool kruskal_merge(int a, int b);
int kruskal_dsu_get_root(int v);

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

    cout << "graph:\n";
    print_graf(m);
    cout << "Infinity is " << INF << endl;

    kruskal(n, m);
    prima();

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

    int ost_weight = 0;

    for (int i = 0; i < 100000; i++) {
        p[i] = i;
        rk[i] = 1;
    }

    for (pair<int, pair<int, int>> edge: edges) {
        if (kruskal_merge(edge.second.first, edge.second.second)) {
            ost_weight += edge.first;
            cout << edge.second.first+1 << " - " << edge.second.second+1 << endl;
        }
    }

    cout << "Min ostov weight: " << ost_weight << endl;
}

bool kruskal_merge(int a, int b) {
    int ra = kruskal_dsu_get_root(a), rb = kruskal_dsu_get_root(b);

    if (ra == rb) {
        return false;
    } else {
        if (rk[ra] < rk[rb]) {
            p[ra] = rb;
        } else if (rk[rb] < rk[ra]) {
            p[rb] = ra;
        } else {
            p[ra] = rb;
            rk[rb]++;
        }

        return true;
    }
}

int kruskal_dsu_get_root(int v) {
    if (p[v] == v) {
        return v;
    }
    else {
        return p[v] = kruskal_dsu_get_root(p[v]);
    }
}

bool used[100000];

void prima() {

    int ost_weight = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, 0});

    while (!q.empty()) {
        pair<int, int> c = q.top();
        q.pop();

        int dst = c.first, v = c.second;

        if (used[v]) {
            continue;
        }

        used[v] = true;
        ost_weight += dst;

        for (pair<int, int> e: graph[v]) {
            int u = e.first, len_vu = e.second;

            if (!used[u]) {
                q.push({len_vu, u});
            }
        }
    }

    cout << "Min ostov weight: " << ost_weight << endl;
}
