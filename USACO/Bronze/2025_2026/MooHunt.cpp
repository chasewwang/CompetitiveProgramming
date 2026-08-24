#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int freq[21][21][21] = {0};
    for (int i = 0; i < k; i++){
        int x, y, z;
        cin >> x >> y >> z;
        if (y > z){
            swap(y, z);
        }
        freq[--x][--y][--z]++;
    }
    int cm = 0, cnt = 0;
    for (int mask = 0; mask < (1 << n); mask++){
        int cur = 0;
        vector<int> M, O;
        for (int i = 0; i < n; i++){
            if (mask & (1 << i)){
                M.push_back(i);
            }
            else {
                O.push_back(i);
            }
        }
        for (int i : M){
            for (int j : O){
                for (int k : O){
                    if (j != k){
                        cur += freq[i][j][k];
                    }
                }
            }
        }
        if (cur == cm){
            cnt++;
        }
        else if (cur > cm){
            cm = cur;
            cnt = 1;
        }
    }
    cout << cm << ' ' << cnt << '\n';
}
