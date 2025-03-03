#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int dfs(int n, int x, vector<int>& a, vector<int>& dp){
    if(x == 0){
        return 0;
    }
    if(x < 0){
        return -1;
    }

    if(dp[x] != -2){
        return dp[x];
    }

    int min_coin = INT_MAX;
    bool flag = false;
    for(int i = 0; i < n; i++){
        int res = dfs(n, x-a[i], a, dp);
        if(res != -1){
            min_coin = min(min_coin, res);
            flag = true;
        }
    }

    if(flag){
        dp[x] = min_coin+1;
        return dp[x];
    }
    dp[x] = -1;
    return dp[x];
}

int solve(int n, int x, vector<int>& a){
    vector<int> dp(x+1, -2); // -2 indicates not visited

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