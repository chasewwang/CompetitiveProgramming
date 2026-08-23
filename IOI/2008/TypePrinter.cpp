#include <bits/stdc++.h>
using namespace std;
const int MM = 500005;
int t[MM][26];
int ml[MM];
bool isend[MM];
int ncnt = 1;
void ins(const string &s){
    int cur = 0;
    ml[cur] = max(ml[cur], (int)s.length());
    for (char c : s){
        if (t[cur][c - 'a'] == 0){
            t[cur][c - 'a'] = ncnt;
            ncnt++;
        }
        cur = t[cur][c - 'a'];
        ml[cur] = max(ml[cur], (int)s.length());
    }
    isend[cur] = true;
}
vector<char> ans;
void dfs(int cur){
    if (isend[cur]){
        ans.push_back('P');
    }
    vector<pair<int, int>> ch;
    for (int i = 0; i < 26; i++){
        if (t[cur][i] != 0){
            ch.push_back({ml[t[cur][i]], i});
        }
    }
    sort(ch.begin(), ch.end());
    for (auto p : ch){
        ans.push_back(p.second + 'a');
        dfs(t[cur][p.second]);
        ans.push_back('-');
    }
}
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        ins(s);
    }
    dfs(0);
    while (ans.back() == '-') ans.pop_back();
    cout << ans.size() << '\n';
    for (char &c : ans){
        cout << c << '\n';
    }
}
