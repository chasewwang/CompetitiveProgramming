#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<bool>> ans(26, vector<bool>(26));
    bool out[26] = {};
    vector<vector<int>> contains(26);
    for (int i = 0; i < n; i++){
        char a, b;
        string _;
        cin >> a >> _ >> b;
        out[a - 'A'] = true;
        if (islower(b)){
            ans[a - 'A'][b - 'a'] = true;
        }
        else{
            contains[a - 'A'].push_back(b - 'A');
            out[b - 'A'] = true;
        }
    }
    bool changed = true;
    while (changed){
        changed = false;
        for (int i = 0; i < 26; i++){
            for (int j : contains[i]){
                for (int k = 0; k < 26; k++){
                    if (ans[j][k] && !ans[i][k]){
                        changed = true;
                    }
                    if (ans[j][k]) ans[i][k] = 1;
                }
            }
        }
    }
    char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alphl[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 26; i++){
        if (!out[i]) continue;
        cout << alph[i];
        cout << " = {";
        int j = 0;
        while (j < 26 && ans[i][j] == 0) j++;
        if (j == 26){
            cout << "}\n";
            continue;
        }
        cout << alphl[j];
        j++;
        while (j < 26){
            if (ans[i][j]){
                cout << ',' << alphl[j];
            }
            j++;
        }
        cout << "}\n";
    }
}
