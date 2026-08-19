#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll INF = 0x3f3f3f3f3f3f3f3fLL;
int n, m, l;
vector<vector<pair<int, int>>> g;
vector<int> treeid;
vector<ll> dist;
void dfsid(int u, int id){
    treeid[u] = id;
    for (auto [v, w] : g[u]){
        if (treeid[v] == -1){
            dfsid(v, id);
        }
    }
}
void dfsdist(int u, int p){
    for (auto [v, w] : g[u]){
        if (v != p){
            dist[v] = dist[u] + w;
            dfsdist(v, u);
        }
    }
}
pair<int, ll> endtree(int s, vector<int> &treeidv){
    for (int &u : treeidv){
        dist[u] = -1;
    }
    dist[s] = 0;
    dfsdist(s, -1);
    int c = s;
    for (int u : treeidv){
        if (dist[u] > dist[c]){
            c = u;
        }
    }
    return {c, dist[c]};
}
int travelTime(int N, int M, int L, int A[], int B[], int T[]){
    n = N;
    m = M;
    l = L;
    g.assign(n, {});
    treeid.assign(n, -1);
    dist.assign(n, -1);
    for (int i = 0; i < m; i++){
        int a = A[i], b = B[i], t = T[i];
        g[a].push_back({b, t});
        g[b].push_back({a, t});
    }
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (treeid[i] == -1){
            dfsid(i, cnt);
            cnt++;
        }
    }
    vector<ll> r(cnt);
    ll ans = 0;
    vector<int> start(cnt, -1);
    vector<vector<int>> treeidv(cnt);
    for (int i = 0; i < n; i++){
        if (start[treeid[i]] == -1){
            start[treeid[i]] = i;
        }
        treeidv[treeid[i]].push_back(i);
    }
    for (int i = 0; i < cnt; i++){
        auto [a, _] = endtree(start[i], treeidv[i]);
        auto [b, d] = endtree(a, treeidv[i]);
        vector<ll> tmp;
        for (int u : treeidv[i]){
            tmp.push_back(dist[u]);
        }
        for (int &u : treeidv[i]){
            dist[u] = -1;
        }
        dist[b] = 0;
        dfsdist(b, -1);
        r[i] = INF;
        for (int j = 0; j < (int)treeidv[i].size(); j++){
            int u = treeidv[i][j];
            r[i] = min(r[i], max(tmp[j], dist[u]));
        }
        ans = max(ans, d);
    }
    sort(r.rbegin(), r.rend());
    if (cnt >= 2) ans = max(ans, r[0] + r[1] + l);
    if (cnt >= 3) ans = max(ans, r[1] + r[2] + 2LL * l);
    return ans;
}
