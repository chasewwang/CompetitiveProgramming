#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main(){
    freopen("art.in","r",stdin);
    freopen("art.out","w",stdout);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<bool> ingrid(10, false);
    vector<int> minr(10, INF), minc(10, INF);
    vector<int> maxr(10, -1), maxc(10, -1);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char c;
            cin >> c;
            int &x = a[i][j];
            x = c - '0';
            ingrid[x] = true;
            if (x != 0){
                minr[x] = min(minr[x], i);
                minc[x] = min(minc[x], j);
                maxr[x] = max(maxr[x], i);
                maxc[x] = max(maxc[x], j);
            }
        }
    }
    vector<bool> needed(10, false);
    for (int k = 1; k <= 9; k++){
        if (!ingrid[k]) continue;
        for (int i = minr[k]; i <= maxr[k]; i++){
            for (int j = minc[k]; j <= maxc[k]; j++){
                if (a[i][j] != 0 && a[i][j] != k){
                    needed[a[i][j]] = true;
                }
            }
        }
    }
    int ans = 0;
    for (int k = 1; k <= 9; k++){
        if (ingrid[k] && !needed[k]){
            ans++;
        }
    }
    cout << ans << '\n';
}
