#include <bits/stdc++.h>
using namespace std;


int SubsetSum(vector<int>&arr,int sum,int n,vector<vector<int>>&dp ){
   for (int i = 0; i <= n; i++){
      dp[i][0] = 1;
   }

   for (int j = 0; j <= sum;j++){
      dp[0][j] = 0;
   }

   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= sum; j++)
      {
         if(arr[i-1] <= j){
            dp[i][j] = (dp[i-1][j - arr[i-1]] || dp[i-1][j]);
         }else{
            dp[i][j] = dp[i - 1][j];
         }
      }
   }
   return dp[n][sum];
}

int main(){
   vector<int> arr = {1, 5, 11, 5};
   int n = 4;

   int sum = 0;
   for (int i = 0; i < n;i++){
      sum += arr[i];
   }
   if(sum % 2 == 0){
      vector<vector<int>> dp(n + 1, (vector<int>(sum/2 + 1, 0)));

      int ans = SubsetSum(arr, sum/2, n , dp);

      if(ans)
         cout << "YES" << endl;
      else
         cout << "NO" << endl;
   }else{
      cout << "Sum is odd cannot happen.";
   }

      return 0;
}