#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long MOD = 1e9+7;

long long dfs(int n, int x, vector<int>& a, vector<long long>& dp){
    if(x == 0){
        return 1;
    }else if(x < 0){
        return 0;
    }

    long long sum = 0;
    for(int i = 0; i < n; i++){
        if (x-a[i] < 0){
            continue;
        }
        if(dp[x-a[i]] == -1){
            dp[x-a[i]] = dfs(n, x-a[i], a, dp) % MOD;
        }
        sum += dp[x-a[i]];
        sum %= MOD;
    }
    return sum;
}

long long solve(int n, int x, vector<int>& a){
    vector<long long> dp(x+1, -1); // -2 indicates not visited
    return dfs(n, x, a, dp);
}

int main(int argc, char* argv[]){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if(argc > 1){
        if(*argv[1] == '1'){
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        }
    }

    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << solve(n, x, a) << endl;
    return 0;
}