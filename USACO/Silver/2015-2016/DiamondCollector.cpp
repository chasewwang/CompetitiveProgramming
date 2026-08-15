#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    vector<int> nxt(n + 1);
    int r = 1;
    for (int l = 1; l <= n; l++){
        while (r + 1 <= n && a[r + 1] - a[l] <= k){
            r++;
        }
        nxt[l] = r;
    }
    vector<int> ln(n + 1);
    for (int i = 1; i <= n; i++){
        ln[i] = nxt[i] - i + 1;
    }
    vector<int> suff(n + 1);
    suff[n] = ln[n];
    for (int i = n - 1; i >= 1; i--){
        suff[i] = max(suff[i + 1], ln[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        int idx = nxt[i];
        int cur = idx - i + 1;
        if (idx + 1 <= n){
            cur += suff[idx + 1];
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}
