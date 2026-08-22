#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    ll dx = a.second.first - b.second.first;
    ll dy = a.second.second - b.second.second;
    ll dt = a.first - b.first;
    return dx * dx + dy * dy <= dt * dt;
}
int main(){
    int g, n;
    cin >> g >> n;
    vector<pair<int, pair<int, int>>> p(g);
    for (int i = 0; i < g; i++){
        cin >> p[i].second.first >> p[i].second.second >> p[i].first;
    }
    sort(p.begin(), p.end());
    int ans = 0;
    for (int i = 0; i < n; i++){
        int x, y, t;
        cin >> x >> y >> t;
        pair<int, pair<int, int>> q = {t, {x, y}};
        auto idx = lower_bound(p.begin(), p.end(), q);
        bool yes = false;
        if (idx != p.begin()){
            if (!check(q, *(idx - 1))){
                yes = true;
            }
        }
        if (idx != p.end()){
            if (!check(q, *idx)){
                yes = true;
            }
        }
        if (yes){
            ans++;
        }
    }
    cout << ans << '\n';
}
