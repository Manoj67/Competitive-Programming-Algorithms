// Problem :- https://atcoder.jp/contests/dp/tasks/dp_d
#include<iostream>
#include<vector>

using namespace std;

#define ll long long

int main(){
    int n, w;
    cin >> n >> w;
    vector<ll> dp(w+1);
    for(int i = 0; i < n; ++i){
        int weight, value;
        cin >> weight >> value;

        for(int weight_cal = w-weight; weight_cal >= 0; --weight_cal){
            dp[weight_cal+weight] = max(dp[weight_cal+weight], dp[weight_cal]+value);
        }
    }

    ll ans = 0;
    for(int i = 0; i <= w; ++i){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}
