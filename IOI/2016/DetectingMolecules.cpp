#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int find_subset(int l, int u, int w[], int n, int result[]){
    vector<int> a(n + 1), b(n + 1);
    multiset<pair<int, int>> unused;
    for (int i = 1; i <= n; i++){
        a[i] = w[i - 1];
        b[i] = a[i];
        unused.insert({a[i], i});
    }
    sort(b.begin(), b.end());
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++){
        pref[i + 1] = b[i + 1] + pref[i];
    }
    int i = 1;
    multiset<int> v;
    for (int j = 1; j <= n; j++){
        while (pref[j] - pref[i - 1] > u) i++;
        if (pref[j] - pref[i - 1] >= l){
            for (int k = i; k <= j; k++){
                v.insert(b[k]);
            }
            break;
        }
    }
    if (!v.size()){
        return 0;
    }
    int idx = 0;
    for (auto it = v.begin(); it != v.end(); it++){
        auto c = unused.lower_bound({*it, 0});
        result[idx] = c->second - 1;
        idx++;
        unused.erase(c);
    }
    return v.size();
}
