#include <bits/stdc++.h>
using namespace std;
int n, t;
int main(){
    cin >> t;
    while (t--){
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++){
            for (int j = i + 1; j < n; j++){
                if (a[i] > a[j]) ans++;
            }
        }
        cout << "Optimal train swapping takes " << ans << " swaps.\n";
    }
}
