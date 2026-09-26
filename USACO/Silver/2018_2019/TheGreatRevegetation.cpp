#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n + 1), d(n + 1);
    for (int i = 0; i < m; i++){
        char c;
        int u, v;
        cin >> c >> u >> v;
        if (c == 'S'){
            s[u].push_back(v);
            s[v].push_back(u);
        }
        else{
            d[u].push_back(v);
            d[v].push_back(u);
        }
    }
    vector<int> col(n + 1, -1);
    int cnt = 1;
    for (int i = 1; i <= n; i++){
        if (col[i] != -1) continue;
        queue<int> q;
        q.push(i);
        cnt++;
        col[i] = 0;
        while (!q.empty()){
            int u = q.front();
            q.pop();
            for (int v : s[u]){
                if (col[v] == -1){
                    col[v] = col[u];
                    q.push(v);
                }
                else if (col[u] != col[v]){
                    cout << "0\n";
                    return 0;
                }
            }
            for (int v : d[u]){
                if (col[v] == -1){
                    col[v] = col[u] ^ 1;
                    q.push(v);
                }
                else if (col[u] == col[v]){
                    cout << "0\n";
                    return 0;
                }
            }
        }
    }
    cout << "1" << string(cnt - 1, '0') << '\n';
}
