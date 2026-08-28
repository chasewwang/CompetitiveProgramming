#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<pair<pair<int, int>, int>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            int p = a[i].second;
            int dx = abs(a[i].first.first - a[j].first.first);
            int dy = abs(a[i].first.second - a[j].first.second);
            if (p * p >= dx * dx + dy * dy){
                g[i].push_back(j);
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < n; i++){
        queue<int> q;
        q.push(i);
        vector<bool> vis(n);
        vis[i] = true;
        while (!q.empty()){
            int u = q.front();
            q.pop();
            for (int v : g[u]){
                if (!vis[v]){
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        int sm = 0;
        for (int j = 0; j < n; j++){
            sm += vis[j];
        }
        ans = max(ans, sm);
    }
    cout << ans << '\n';
}
