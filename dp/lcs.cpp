// https://atcoder.jp/contests/dp/tasks/dp_f
#include<iostream>
#include<vector>

using namespace std;

#define ll long long

const int INF = 1e9+5;

int dp[3005][3005];

int main(){
    //freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    // diagram from techiedelight
    string s, t;
    cin >> s >> t;

    for(int i = 1; i <= s.size(); ++i){
        for(int j = 1; j <= t.size(); ++j){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                //cout << i << " " << j << " " << dp[i][j] << endl;
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                //cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
    }
    // lcs size
    //cout << dp[s.size()][t.size()]  << endl; 

    int i = s.size(), j = t.size();
    string ans;
    // iterating in reverse
    while(i && j){ // i >= 0 && j >= 0
        if(s[i-1] == t[j-1]){
            ans = s[i-1]+ans; // concatinating previous element into last string
            --i;
            --j;
            continue;
        }
        if(dp[i-1][j] > dp[i][j-1])
            --i;
        else
            --j;
    }

    cout << ans << endl;
}

