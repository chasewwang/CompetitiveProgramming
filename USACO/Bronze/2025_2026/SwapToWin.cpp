#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    string target, cur;
    cin >> target >> cur;
    vector<string> strings(n);
    strings[0] = cur;
    for (int i = 1; i < n; i++){
        cin >> strings[i];
    }
    vector<tuple<int, int, int, int>> ans;
    for (int i = 0; i < m; i++){
        if (strings[0][i] == target[i]){
            continue;
        }
        bool found = false;
        for (int j = i + 1; j < m; j++){
            if (strings[0][j] == target[i]){
                ans.push_back({1, 1, i + 1, j + 1});
                swap(strings[0][i], strings[0][j]);
                found = true;
                break;
            }
        }
        if (found){
            continue;
        }
        for (int j = 1; j < n; j++){
            bool found2 = false;
            for (int k = 0; k < m; k++){
                if (strings[j][k] == target[i]){
                    if (i != k){
                        ans.push_back({1, j + 1, i + 1, k + 1});
                        swap(strings[j][k], strings[j][i]);
                    }
                    ans.push_back({2, 1, j + 1, i + 1});
                    swap(strings[0][i], strings[j][i]);
                    found2 = true;
                    break;
                }
            }
            if (found2){
                break;
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto [op, x, y, z] : ans){
        cout << op << ' ' << x << ' ' << y << ' ' << z << '\n';
    }
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
