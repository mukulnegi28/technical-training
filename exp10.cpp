#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(vector<int>& set, int sum) {
 int n = set.size();
 vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
 for (int i = 0; i <= n; i++)
 dp[i][0] = true;
 for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
        if (set[i - 1] > j)
        dp[i][j] = dp[i - 1][j];
        else
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
        }
        }
 return dp[n][sum];
}
int main() {
 vector<int> set = {3, 34, 4, 12, 5, 2};
 int sum1 = 9;
 int sum2 = 30;
 // Check if there is a subset with sum = 9
 if (isSubsetSum(set, sum1))
 cout << "Subset with sum " << sum1 << " exists.\n";
 else
 cout << "Subset with sum " << sum1 << " does not exist.\n";
 // Check if there is a subset with sum = 30
 if (isSubsetSum(set, sum2))
 cout << "Subset with sum " << sum2 << " exists.\n";
 else
 cout << "Subset with sum " << sum2 << " does not exist.\n";
 return 0;
}