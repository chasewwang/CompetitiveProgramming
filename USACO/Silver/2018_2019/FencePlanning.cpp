#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct coord{
    int x, y;
};
int main(){
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<coord> coords(n);
    for (int i = 0; i < n; i++){
        cin >> coords[i].x >> coords[i].y;
    }
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    vector<int> group(n, -1);
    vector<bool> vis(n);
    int a = 0;
    for (int i = 0; i < n; i++){
        vis[i] = true;
        if (group[i] != -1){
            continue;
        }
        queue<int> q;
        q.push(i);
        while (!q.empty()){
            int u = q.front();
            q.pop();
            group[u] = a;
            for (int v : g[u]){
                if (!vis[v] && group[v] == -1){
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        a++;
    }
    vector<pair<coord, coord>> b(a);
    for (int i = 0; i < a; i++){
        b[i] = {{INF, INF}, {-1, -1}};
    }
    for (int i = 0; i < n; i++){
        b[group[i]].first.x = min(b[group[i]].first.x, coords[i].x);
        b[group[i]].first.y = min(b[group[i]].first.y, coords[i].y);
        b[group[i]].second.x = max(b[group[i]].second.x, coords[i].x);
        b[group[i]].second.y = max(b[group[i]].second.y, coords[i].y);
    }
    int ans = INF;
    for (int i = 0; i < a; i++){
        int h = b[i].second.x - b[i].first.x;
        int w = b[i].second.y - b[i].first.y;
        ans = min(ans, 2 * (h + w));
    }
    cout << ans << '\n';
}
