#include <bits/stdc++.h>
using namespace std;
int g[101][101], n, m;
int main(){
    cin >> m >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    for (int a = 0; a < 10; a++){
        for (int b = a; b < 10; b++){
            for (int c = b; c < 10; c++){
                queue<pair<int, int>> q;
                vector<vector<int>> vis(101, vector<int>(101));
                for (int j = 0; j < m; j++){
                    q.push({0, j});
                    vis[0][j] = true;
                }
                bool f = false;
                while (!q.empty()){
                    auto [x, y] = q.front();
                    if (x == n - 1){
                        f = true;
                        break;
                    }
                    q.pop();
                    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
                    for (auto [dx, dy] : dir){
                        int nx = x + dx, ny = y + dy;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]
                            && (a == g[nx][ny] || b == g[nx][ny] || c == g[nx][ny])){
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
                if (f){
                    cout << a << ' ' << b << ' ' << c << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "-1 -1 -1\n";
}
