/*
9/3/2026

Values with different remainders mod |K| will never be equal. So, we solve independently for each possible remainder.

After dividing out the common remainder and |K|, increments are now all 1 or -1, depending on if K was positive or negative.
This set of integers must be made distinct through increments of 1 or -1.

We greedily assign each value to the closest next avaiable value in that direction.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n, k;
    cin >> n >> k;
    int m = abs(k);
    int dir = k > 0 ? 1 : -1;
    vector<vector<pair<ll, int>>> groups(m);
    map<int, int> freq;
    for (int i = 0; i < n; i++){
        int c;
        cin >> c;
        freq[c]++;
    }
    for (auto [val, vcnt] : freq){
        int r = val % m;
        int v = (val - r) / m;
        groups[r].push_back({v, vcnt});
    }
    ll ans = 0;
    for (int i = 0; i < m; i++){
        if (groups[i].empty()){
            continue;
        }
        if (dir == 1){
            sort(groups[i].begin(), groups[i].end());
        }
        else{
            sort(groups[i].rbegin(), groups[i].rend());
        }
        ll nxt = groups[i][0].first;
        ll cost = 0;
        for (auto [v, vcnt] : groups[i]){
            if (dir == 1){
                nxt = max(nxt, v);
                while (vcnt--){
                    cost += nxt - v;
                    nxt++;
                }
            }
            else{
                nxt = min(nxt, v);
                while (vcnt--){
                    cost += v - nxt;
                    nxt--;
                }
            }
        }
        ans += cost;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--){
        solve();
    }
}
