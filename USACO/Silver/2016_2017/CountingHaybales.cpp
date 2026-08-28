#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a){
        cin >> x;
    }
    sort(a.begin(), a.end());
    while (q--){
        int l, r;
        cin >> l >> r;
        int i1 = upper_bound(a.begin(), a.end(), r) - a.begin();
        int i2 = upper_bound(a.begin(), a.end(), l - 1) - a.begin(); 
        cout << i1 - i2 << '\n';
    }
}
