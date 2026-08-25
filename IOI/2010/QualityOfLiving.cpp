#include "quality.h"
#include <bits/stdc++.h>
using namespace std;
int r, c, h, w;
vector<vector<int>> a, pref;
bool check(int k){
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            int add = (a[i - 1][j - 1] <= k) ? 1 : -1;
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + add;
        }
    }
    for (int i = h; i <= r; i++){
        for (int j = w; j <= c; j++){
            if (pref[i][j] - pref[i - h][j] - pref[i][j - w] + pref[i - h][j - w] > 0){
                return true;
            }
        }
    }
    return false;
}
int rectangle(int R, int C, int H, int W, int Q[3001][3001]){
    r = R;
    c = C;
    h = H;
    w = W;
    a.assign(r, vector<int>(c));
    pref.assign(r + 1, vector<int>(c + 1));
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            a[i][j] = Q[i][j];
        }
    }
    int lo = 1, hi = r * c;
    while (lo < hi){
        int mid = lo + (hi - lo) / 2;
        if (check(mid)){
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    return lo;
}
