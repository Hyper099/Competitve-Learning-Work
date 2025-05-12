#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define INF INT_MAX //* A big number for impossible cases

//! COIN CHANGE USING RECURSION.
ll CoinProblemRec(ll target, vector<ll> &coins)
{
   if(target == 0)
      return 0;
   
   if(target < 0)
      return INF;
   
   ll ans = INF;
   for (auto c : coins)
   {
      ll subCoin = CoinProblemRec((target - c), coins);
      if(subCoin!=INF){
         ans = min(ans, subCoin + 1);
      }
   }

   return ans;
}

//! COIN CHANGE using DP-> Recursion + Memoization.
ll CoinChangeDp(ll target, vector <ll>&coins , map<ll,ll>&dp){
   if(target == 0){
      return 0;
   }
   if(target < 0)
      return INF;
   
   if(dp.count(target))
      return dp[target];

   ll ans = INF;
   for(auto c : coins)
   {
      ll subProb = CoinChangeDp(target - c, coins, dp);
      if(subProb!=INF){
         ans = min(ans, subProb + 1);
      }
   }
   dp[target] = ans;
   return ans;
}

//! COIN CHANGE using DP -> Tabulation.
ll CoinChangeBottomUp(ll target,vector<ll>&coins){
   vector<ll> dp(target + 1, INF);
   dp[0] = 0;

   for (ll i = 1; i <= target;i++){
      for(auto c : coins){
         if(i-c>=0)
            dp[i] = min(dp[i], 1+ dp[i - c]);
      }
   }
   return dp[target];
}

//! COIN CHANGE PROBLEM, HOW MANY WAYS TO MAKE THE TARGET SUM.
//? Here any order is considered to be a unique way.
ll CoinChangeWays(ll targetSum, vector<ll>&coins){
   vector<ll> dp(targetSum + 1, 0);
   dp[0] = 1;
   for (auto c : coins){
      for(ll i = 1; i <= targetSum;i++){
         if( i - c >= 0){
            dp[i] += dp[i - c];
            // cout << "coin : " << c << " , " << i << " " << dp[i] << endl;
         }
      }
      // cout << dp[i] << endl;
   }
   return dp[targetSum];
}

int main()
{
   auto start = high_resolution_clock::now();
   ll target = 150;
   ll targetSum = 5;
   vector<ll> coins = {1, 4, 5};
   map<ll, ll> dp;
   // ll ans = CoinProblemRec(target, coins);
   // ll ans = CoinChangeDp(target, coins , dp);
   // ll ans = CoinChangeBottomUp(target, coins);
   ll ans = CoinChangeWays(targetSum, coins);
   cout << "No of ways : " << ans << endl;
   // if (ans == INT_MAX)
   //    cout << "Not possible to make target " << target << endl;
   // else
   //    cout << "MIN coins required: " << ans << endl;

   auto stop = high_resolution_clock::now();

   auto duration = duration_cast<milliseconds>(stop - start);
   cout << "Time taken: " << duration.count() << " ms" << endl;

   return 0;
}
