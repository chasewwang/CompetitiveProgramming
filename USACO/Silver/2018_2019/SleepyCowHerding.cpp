#include <bits/stdc++.h>
using namespace std;
const int MM = 100005, INF = 0x3f3f3f3f;
int a[MM], n;
int main(){
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    bool consecutive = 1;
    for (int i = 0; i < n - 1; i++){
        if (a[i] + 1 != a[i + 1]){
            consecutive = 0;
        }
    }
    if (consecutive){
        cout << "0\n0\n";
        return 0;
    }
    int ansmin = INF, ansmax = max(a[n - 2] - a[0], a[n - 1] - a[1]) - (n - 2);
    int l = 0;
    for (int r = 0; r < n; r++){
        if (r == 0 && a[1] - a[0] == 1){
            r++;
            l++;
        }
        while (l + 1 < n && a[r] - a[l] >= n) l++;
        int cur = n - (r - l + 1);
        if (r == n - 1 && a[n - 1] - a[n - 2] == 1) cur++;
        ansmin = min(ansmin, cur);
    }
    cout << ansmin << '\n' << ansmax << '\n';
}
