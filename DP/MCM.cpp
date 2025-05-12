#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
   if (i >= j)
      return 0;

   if (dp[i][j] != -1)
      return dp[i][j];

   int minCost = INT_MAX;
   for (int k = i; k < j; k++)
   {
      int cost = solve(i, k, arr, dp) +
                 solve(k + 1, j, arr, dp) +
                 arr[i - 1] * arr[k] * arr[j];
      minCost = min(minCost, cost);
   }

   return dp[i][j] = minCost;
}

int main()
{
   vector<int> arr = {40, 20, 30, 10, 30};
   int n = arr.size();
   vector<vector<int>> dp(n, vector<int>(n, -1));
   int i = 1, j = n - 1;
   int ans =  solve(i, j, arr, dp);
   cout << ans << endl;
   return 0;
}
