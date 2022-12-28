#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

bool maze[1000][1000];
int n_maze, m_maze;

void dfs(int x, int y);

int main()
{
    fstream infile; //a.k.a. input file
    infile.open("maze.txt", ios::in);

    int x_start, y_start;
    infile >> n_maze >> m_maze >> x_start >> y_start;
    x_start--; y_start--;

    for (int i = 0; i < n_maze; i++) {
        for (int j = 0; j < m_maze; j++) {
            int tmp;
            infile >> tmp;
            maze[i][j] = tmp;
        }
    }

    dfs(x_start, y_start);

    for (int i = 0; i < n_maze; i++) {
        for (int j = 0; j < m_maze; j++) {

            cout << maze[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

void dfs(int x, int y) {
    maze[x][y] = true;

    if (x > 0) {
        if (!maze[x-1][y]) {
            dfs(x-1, y);
        }
    }
    else {
        cout << "Reached exit1 at " << x+1 << " " << y+1 << endl;
    }
    if (y > 0) {
        if (!maze[x][y-1]) {
            dfs(x, y-1);
        }
    }
    else {
        cout << "Reached exit2 at " << x+1 << " " << y+1 << endl;
    }
    if (x < n_maze-1) {
        if (!maze[x+1][y]) {
            dfs(x+1, y);
        }
    }
    else {
        cout << "Reached exit3 at " << x+1 << " " << y+1 << endl;
    }
    if (y < m_maze-1) {
        if (!maze[x][y+1]) {
            dfs(x, y+1);
        }
    }
    else {
        cout << "Reached exit4 at " << x+1 << " " << y+1 << endl;
    }

    maze[x][y] = false;
}
