#include <bits/stdc++.h>
using namespace std;

//! Recursive Approach.
int LCS(string X, string Y, int m, int n, vector<vector<int>> &dp)
{
   // Base Case
   if (m == 0 || n == 0)
      return 0;

   // If already solved
   if (dp[m][n] != -1)
      return dp[m][n];

   // If characters match
   if (X[m - 1] == Y[n - 1])
      dp[m][n] = 1 + LCS(X, Y, m - 1, n - 1, dp);
   else
      dp[m][n] = max(LCS(X, Y, m - 1, n, dp), LCS(X, Y, m, n - 1, dp));

   return dp[m][n];
}

//! Bottom-Up Approach
int LCSBU(string X,string Y,int m,int n,vector<vector<int>>&dp){
   // agar koi ek bhi zero hua toh answer toh zero hoga.
   for (int i = 0; i <= m;i++){
      dp[i][0] = 0;
   }

   for (int i = 0; i <= n;i++){
      dp[0][i] = 0;
   }

   // Conditions :
   // 1. agar dono same hai toh count + 1 
   // 2. agar dono alag hai toh voh check karo kiska ek minus karke maximum tha.

   for (int i = 1; i <= m;i++){
      for (int j = 1; j <= n;j++){
         if(X[i-1] == Y[j-1]){
            dp[i][j] = 1 + dp[i - 1][j - 1];
         }else{
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
         }
      }
   }
   return dp[m][n];
}

//! Printing the Sequence;
string LCSPBU(string X, string Y, int m, int n,vector<vector<int>>&dp){

   int i = m,j = n;
   string ans = "";
   while (i > 0 && j > 0)
   {
      if(X[i-1] == Y[j-1]){
         ans.push_back(X[i-1]);
         i--;
         j--;
      }else{
         if(dp[i-1][j] > dp[i][j-1]){
            i--;
         }else{
            j--;
         }
      }
   }
   reverse(ans.begin(),ans.end());
   return ans;
}

int main()
{
   string X = "AGGTABaa";
   string Y = "GXTXAYBaa";
   int m = X.length();
   int n = Y.length();

   vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

   cout << "Length of LCS : " << LCSBU(X, Y, m, n, dp) << endl;
   cout << "Sequence of LCS : " << LCSPBU(X, Y, m, n, dp) << endl;

   return 0;
}