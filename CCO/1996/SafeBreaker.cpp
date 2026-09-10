#include <bits/stdc++.h>
using namespace std;
void solve(){
    int g;
    cin >> g;
    vector<int> ans;
    vector<pair<int, pair<int, int>>> guess(g);
    for (int i = 0; i < g; i++){
        cin >> guess[i].first;
        string s;
        cin >> s;
        guess[i].second.first = s[0] - '0';
        guess[i].second.second = s[2] - '0';
    }
    for (int i = 0; i < 10000; i++){
        string istr = to_string(i);
        while (istr.length() < 4) istr = "0" + istr;
        bool works = true;
        for (int j = 0; j < g; j++){
            int num = guess[j].first;
            bool marked[4] = {};
            int correct = 0, misplaced = 0;
            string numstr = to_string(num);
            while (numstr.length() < 4) numstr = "0" + numstr;
            for (int k = 0; k < 4; k++){
                if (!marked[k] && (istr[k] == numstr[k])){
                    correct++;
                    marked[k] = true;
                }
                else{
                    for (int l = 0; l < 4; l++){
                        if (k == l) continue;
                        if (!marked[l] && (istr[k] == numstr[l]) && (istr[l] != numstr[l])){
                            marked[l] = true;
                            misplaced++;
                            break;
                        }
                    }
                }
            }
            if (correct != guess[j].second.first || misplaced != guess[j].second.second){
                works = false;
            }
        }
        if (works){
            ans.push_back(i);
        }
    }
    if (ans.size() == 0){
        cout << "impossible\n";
    }
    else if (ans.size() > 1){
        cout << "indeterminate\n";
    }
    else{
        string out = to_string(ans[0]);
        while (out.length() < 4) out = "0" + out;
        cout << out << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
