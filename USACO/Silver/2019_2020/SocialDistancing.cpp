#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> a(m);
    for (auto &[l, r] : a){
        cin >> l >> r;
    }
    sort(a.begin(), a.end());
    ll lo = 1, hi = LLONG_MAX;
    while (lo < hi){
        ll mid = lo + (hi - lo + 1) / 2;
        ll prev = LLONG_MIN, cur = 0;
        for (ll i = 0; i < m; i++){
            ll mstart = prev + mid;
            if (mstart <= a[i].second){
                ll add = 1 + (a[i].second - max(a[i].first, mstart)) / mid;
                cur += add;
                prev = max(a[i].first, mstart) + (add - 1) * mid;
            }
        }
        if (cur < n){
            hi = mid - 1;
        }
        else {
            lo = mid;
        }
    }
    cout << lo << '\n';
}
