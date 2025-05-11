#include <bits/stdc++.h>
using namespace std;

// int dp[102][1002];

// int knapSack(vector<int> &w, vector<int> &val, int W, int n)
// {
//    if (n == 0 || W == 0)
//       return 0;

//    if (dp[n][W]!=-1)
//       return dp[n][W];

//    if (w[n-1] > W)
//       return dp[n][W] = knapSack(w, val, W, n - 1);

//    // choice;
//    int mx = max(val[n-1] + knapSack(w, val, W - w[n-1], n - 1), knapSack(w, val, W, n - 1));
   
//    return dp[n][W]= mx;
// }

int knapsackBU(vector<int> &wt, vector<int> &val,vector<vector<int>> &dp,int n, int W){
   for (int i = 0; i <= n;i++){
      for (int w = 0; w <= W; w++){
         if(i ==0 || w == 0){
            dp[i][w] = 0;
         }else if(w >= wt[i-1]){
            dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i-1]], dp[i - 1][w]);
         }else{
            dp[i][w] = dp[i - 1][w];
         }
      }
   }

   // required.
   return dp[n][W];
}

int main()
{
   // memset(dp, -1, sizeof(dp));

   vector<int> wt = {1, 5, 4, 3};
   vector<int> val = {1, 7, 5, 4};
   int W = 7;
   int n = 4;
   // int ans = knapSack(w, val, W, n);

   vector<vector<int>> t(n + 1, vector<int>(W + 1, 0));

   int ans = knapsackBU(wt, val, t, n, W);

   cout << ans << endl;


   return 0 ;
}