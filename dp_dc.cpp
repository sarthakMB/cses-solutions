#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

const long long MOD = 1e9 + 7;

long long dfs(int n, vector<long long>& dp);

long long solve(int n){
    vector<long long> dp(n+1,-1);

    return dfs(n,dp);
}

long long dfs(int n, vector<long long>& dp){
    if(n == 0){
        return 1;
    }else if(n < 0){
        return 0;
    }
    long long ans = 0;
    for(int i = 1; i <= 6 && n-i >= 0; i++){
        if(dp[n-i] == -1){
            dp[n-i] = dfs(n-i,dp);
        }
        ans += dp[n-i];
        ans %= MOD;
    }
    dp[n] = ans;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    // cout << n;
    cout << solve(n);
    
}