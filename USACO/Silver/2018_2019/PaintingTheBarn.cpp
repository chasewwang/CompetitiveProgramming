#include <bits/stdc++.h>
using namespace std;
const int MM = 1005;
int a[MM][MM] = {}, n, k;
int main(){
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1]++;
        a[x1][y2]--;
        a[x2][y1]--;
        a[x2][y2]++;
    }
    int ans = 0;
    for (int i = 0; i < MM; i++){
        for (int j = 0; j < MM; j++){
            if (i > 0){
                a[i][j] += a[i - 1][j];
            }
            if (j > 0){
                a[i][j] += a[i][j - 1];
            }
            if (i > 0 && j > 0){
                a[i][j] -= a[i - 1][j - 1];
            }
            if (a[i][j] == k){
                ans++;
            }
        }
    }
    cout << ans << '\n';
}
