#include <bits/stdc++.h>
using namespace std;


int SubsetSum(vector<int>&arr, int sum ,int n, vector<vector<int>>&dp){
   for (int i = 0; i <= n; i++) {
      dp[i][0] = 1; 
   }
   for (int j = 1; j <= sum; j++) {
      dp[0][j] = 0; 
   }

   for (int i = 1; i <= n; i++){
      for (int j = 1; j <= sum; j++){
         if(arr[i-1] <= j){
            dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
         }else{
            dp[i][j] = dp[i - 1][j];
         }
      }
   }
   return dp[n][sum];
}

int main(){
   vector<int> arr = {12, 13, 7, 8, 10};
   int sum = 11;
   int n = 5;

   vector<vector<int>> dp(n + 1, (vector<int>(sum + 1, 0)));

   int ans = SubsetSum(arr, sum, n , dp);

   if(ans)
      cout << "YES" << endl;
   else
      cout << "NO" << endl;

   return 0;
}