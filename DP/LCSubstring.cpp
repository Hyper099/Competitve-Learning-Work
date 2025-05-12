#include <bits/stdc++.h>
using namespace std;


//! Bottom-Up Approach for longest common substring.
int LCSBU(string X,string Y,int m,int n,vector<vector<int>>&dp){
   int result = INT_MIN;
   for (int i = 1; i <= m; i++)
   {
      for (int j = 1; j <= n;j++){
         if(X[i-1] == Y[j-1]){
            dp[i][j] = 1 + dp[i - 1][j - 1];
            result = max(dp[i][j], result);
         }
         else
            dp[i][j] = 0;
      }
   }
   return result;
}

int main()
{
   string X = "AGGTABa";
   string Y = "GXTXABaa";
   int m = X.length();
   int n = Y.length();

   vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

   cout << "Length of LCS: " << LCSBU(X, Y, m, n, dp) << endl;

   return 0;
}