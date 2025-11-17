#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 1e9);

    dp[0] = 0;   
    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    if (dp[amount] == 1e9) 
        return -1;
    return dp[amount];
}
int main() {
    int n;
    cout << "Enter number of coin types: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int amount;
    cout << "Enter amount: ";
    cin >> amount;

    int ans = solve(coins, amount);
    cout << "coins required = " << ans << endl;

    return 0;
}