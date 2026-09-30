#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
struct edge{
    int u, v, r, p;
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<edge> a(m);
    vector<vector<int>> rev(n + 1);
    vector<int> odeg(n + 1);
    for (int i = 0; i < m; i++){
        cin >> a[i].u >> a[i].v >> a[i].r >> a[i].p;
        rev[a[i].v].push_back(i);
        odeg[a[i].u]++;
    }
    vector<int> ans(n+1, INF);
    vector<bool> f(n+1, 0);
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (odeg[i] == 0){
            ans[i] = -1;
            q.push(i);
            f[i] = true;
        }
    }
    while (!q.empty()){
        int u = q.front();
        q.pop();
        ans[u] = -1;
        for (int idx : rev[u]){
            int b = a[idx].u;
            odeg[b]--;
            if (odeg[b] == 0 && !f[b]){
                q.push(b);
                f[b] = 1;
            }
        }
    }
    vector<bool> vis(m);
    vector<int> o(m);
    for (int i = 0; i < m; i++){
        o[i] = i;
    }
    sort(o.begin(), o.end(), [&](int i, int j){
        return a[i].r > a[j].r;
    });
    for (int k = 0; k < m; k++){
        int i = o[k];
        if (vis[i]){
            continue;
        }
        vis[i] = true;
        int u = a[i].u;
        if (f[u] || f[a[i].v]){
            continue;
        }
        ans[u] = min(ans[u], a[i].r);
        odeg[u]--;
        if (odeg[u]){
            continue;
        }
        q.push(u);
        while (!q.empty()){
            int c = q.front();
            q.pop();
            for (int idx : rev[c]){
                if (vis[idx]){
                    continue;
                }
                vis[idx] = true;
                int b = a[idx].u;
                int pr = ans[c] - a[idx].p;
                if (ans[c] == INF){
                    pr = INF;
                }
                ans[b] = min(ans[b], max(a[idx].r, pr));
                odeg[b]--;
                if (odeg[b] == 0){
                    q.push(b);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (ans[i] >= INF){
            cout << "-1";
        }
        else cout << ans[i];
        cout << " \n"[i == n];
    }
}
