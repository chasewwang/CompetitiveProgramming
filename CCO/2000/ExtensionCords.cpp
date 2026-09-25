#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    double x, y;
    int n, m;
    cin >> x >> y >> n >> m;
    vector<int> len(n);
    for (int &l : len) cin >> l;
    vector<vector<pair<double, pair<double, double>>>> v(100001);
    for (int i = 0; i < m; i++){
        double a, b;
        int c;
        cin >> a >> b >> c;
        pair<double, pair<double, double>> d;
        d.second.first = a;
        d.second.second = b;
        double dx = a - x, dy = b - y;
        d.first = dx * dx + dy * dy;
        v[c].push_back(d);
    }
    vector<pair<double, pair<double, double>>> cand;
    for (int i = 0; i <= 10000; i++){
        if ((int)v[i].size() == 0) continue;
        sort(v[i].begin(), v[i].end());
        cand.push_back(v[i][0]);
    }
    if ((int)cand.size() < 2){
        cout << "Harry is helpless.\n";
        return 0;
    }
    sort(cand.begin(), cand.end());
    double d1 = sqrt(cand[0].first), d2 = sqrt(cand[1].first);
    int tot = 0;
    for (int k : len) tot += k;
    vector<bool> dp(tot+1);
    dp[0] = 1;
    for (int k : len){
        for (int j = tot; j >= k; j--){
            if (dp[j - k]) dp[j] = 1;
        }
    }
    int mn = ceil(d1 - (1e-9));
    int mx = floor(tot - d2 + (1e-9));
    bool ok = false;
    for (int i = mn; i <= mx; i++){
        if (dp[i]) ok = true;
    }
    if (!ok){
        cout << "Harry is helpless.\n";
    }
    else{
        cout << fixed << setprecision(1);
        cout << "Harry can connect to outlets at (";
        cout << cand[0].second.first << ", ";
        cout << cand[0].second.second << ") and (";
        cout << cand[1].second.first << ", ";
        cout << cand[1].second.second << ").\n";
    }
}
