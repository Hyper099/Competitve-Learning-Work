#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long


//! Fibonnaci using normal recursion.
int fib(int n)
{
   if (n <= 1)
      return n;
   return fib(n - 1) + fib(n - 2);
}

//! Fibonacci using DP -> Recursion + Memoizaion. (TOP-DOWN)
ll fibDp(ll n, map<ll,ll>&dp){
   
   if(dp.count(n))
   { // this will return if the n exists in the map for not, its same as dp.find(n)!=dp.end();
      return dp[n];
   }

   ll result;
   if(n<=2){
      result = 1;
   }else{
      result = fibDp(n - 1,dp) + fibDp(n - 2,dp);
   }
   dp[n] = result;
   return result;
}

//! FIbonacci using DP->(BOTTOM-UP)
ll fibBottomUp(ll n){
   if(n==0)
      return 0;

   if(n==1)
      return 1;

   vector<ll> dp(n + 1);
   dp[0] = 0;
   dp[1] = 1;
   for (ll i = 2; i <= n; i++)
   {
      dp[i] = dp[i - 1] + dp[i - 2];
   }
   return dp[n];
}

int main()
{
   auto start = high_resolution_clock::now();
   map<ll, ll> dp;
   ll n = 100;
   // ll ans = fibDp(n,dp);
   ll ans = fibBottomUp(n);
   cout << "Fibonacci" << "(" << n << ") = " << ans << endl;

   auto stop = high_resolution_clock::now();

   auto duration = duration_cast<milliseconds>(stop - start);
   cout << "Time taken: " << duration.count() << " ms" << endl;

   return 0;
}
