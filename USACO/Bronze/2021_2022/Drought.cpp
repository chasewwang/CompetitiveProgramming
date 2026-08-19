#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; i++){
        if (a[i] < a[i + 1]){
            if (i == n - 2){
                cout << "-1\n";
                return;
            }
            int d = a[i + 1] - a[i];
            ans += 2LL * d;
            a[i + 1] -= d;
            a[i + 2] -= d;
            if (a[i + 1] < 0 || a[i + 2] < 0){
                cout << "-1\n";
                return;
            }
        }
        else if (a[i] > a[i + 1]){
            if (i % 2 == 0){
                cout << "-1\n";
                return;
            }
            int d = a[i] - a[i + 1];
            ans += 1LL * (i + 1) * d;
            a[0] -= d;
            if (a[0] < 0){
                cout << "-1\n";
                return;
            }
        }
    }
    cout << ans << '\n';
}
int main(){
    int tc;
    cin >> tc;
    while (tc--) solve();
}
