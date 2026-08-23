#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (int i = 0; i < n; i++){
        ll c;
        cin >> c;
        if (i > 0 && 2 * v[i - 1] < c) c = 2 * v[i - 1];
        v[i] = c;
    }
    while (q--){
        ll x;
        cin >> x;
        ll ans = INF, cur = 0;
        for (int j = min(30, n - 1); j >= 0; j--){
            ll cnt = x / (1LL << j);
            x -= cnt * (1LL << j);
            cur += cnt * v[j];
            if (x == 0) ans = min(ans, cur);
            else ans = min(ans, cur + v[j]);
        }
        cout << ans << '\n';
    }
}
