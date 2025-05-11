#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int m, int n, vector<vector<int>> &dp)
{
   // Base Case
   if (m == 0 || n == 0)
   {
      return 0;
   }

   // If already solved
   if (dp[m][n] != -1)
   {
      return dp[m][n];
   }

   // If characters match
   if (X[m - 1] == Y[n - 1])
   {
      dp[m][n] = 1 + LCS(X, Y, m - 1, n - 1, dp);
   }
   else
   {
      dp[m][n] = max(LCS(X, Y, m - 1, n, dp), LCS(X, Y, m, n - 1, dp));
   }

   return dp[m][n];
}

int main()
{
   string X = "AGGTAB";
   string Y = "GXTXAYB";
   int m = X.length();
   int n = Y.length();

   // Initialize dp with -1
   vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

   cout << "Length of LCS: " << LCS(X, Y, m, n, dp) << endl;

   return 0;
}