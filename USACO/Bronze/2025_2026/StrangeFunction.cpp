#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7, MM = 2e5+5;
int p[MM];
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> one;
    bool notbinary = false;
    for (int i = 0; i < n; i++){
        int num = s[i] - '0';
        if (num >= 2){
            notbinary = true;
        }
        if (num & 1){
            one.push_back(i);
        }
    }
    ll ans = notbinary;
    while (!one.empty()){
        int idx = one.back();
        one.pop_back();
        ans += p[n - idx];
        ans %= MOD;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    p[1] = 1;
    p[2] = 3;
    for (int i = 3; i < MM; i++){
        p[i] = p[i - 1] * 2;
        p[i] %= MOD;
    }
    int tc;
    cin >> tc;
    while (tc--){
        solve();
    }
}
