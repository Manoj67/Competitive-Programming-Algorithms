// this program also can be used to calculate max no. of coins to get in change
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 1e5+7;
int dp[MAX];

int solve(vector<int> coins, int amount){
    int n = coins.size(); // total coins
    dp[0]=0;
    for(int i = 1; i <= amount; ++i){
        dp[i] = MAX;
        for(int j = 0; j < n; ++j){
            int val = i-coins[j];
            if(val >= 0)
                dp[i] = min(dp[i], dp[val]+1); // minimizing coins from unlimited supply of coins
        }
    }
    return dp[amount];
}

int main(){
    int n, amount; // amount to be changed
    cin >> n >> amount;
    vector<int> coins(n); // change
    for(int i = 0; i < coins.size(); ++i){
        cin >> coins[i];
    }
    cout << solve(coins, amount) << endl;
}   