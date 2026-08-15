#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<bool>> vis;
void init(int N, int M){
    n = N;
    m = M;
    vis.assign(N, vector<bool>(M));
}
pair<int, int> receive_block(int TL, int TR, int BL, int BR){
    int dx, dy;
    if (TL == 0) dx = dy = -1;
    else if (TR == 0) dx = -1, dy = 1;
    else if (BR == 0) dx = dy = 1;
    else dx = 1, dy = -1;
    int x = dx == 1 ? 0 : n - 1;
    int y = dy == 1 ? 0 : m - 1;
    while (vis[x][y]){
        y += dy;
        if (y < 0 || y >= m){
            y = dy == 1 ? 0 : m - 1;
            x += dx;
        }
    }
    vis[x][y] = true;
    return {2 * x, 2 * y};
}
