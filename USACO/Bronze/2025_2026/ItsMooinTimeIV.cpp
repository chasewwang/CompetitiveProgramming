#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, k;
    cin >> t >> k;
    while (t--){
        int n;
        string s;
        cin >> n >> s;
        bool flip = 0;
        vector<char> ans;
        for (int i = n - 1; i >= 0; i--){
            if (!flip){
                ans.push_back(s[i]);
                if (s[i] == 'O'){
                    flip = 1 - flip;
                }
            }
            else{
                if (s[i] == 'M'){
                    ans.push_back('O');
                    flip = 1 - flip;
                }
                else {
                    ans.push_back('M');
                }
            }
        }
        cout << "YES\n";
        if (k){
            for (int i = n - 1; i >= 0; i--){
                cout << ans[i];
            }
            cout << '\n';
        }
    }
}
