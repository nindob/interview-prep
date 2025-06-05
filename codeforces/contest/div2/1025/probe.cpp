#include<bits/stdc++.h>
#include<iostream>
//#include <unistd.h>
//#include<cstdio>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long
typedef long long ll;
#define F first
#define S second
#define pb push_back

const int MOD = 998244353;


ll dp[505][505][2];

signed main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n, k_ops;
        cin>>n>>k_ops;
        string s;
        cin>>s;

        if (k_ops == 0) {
            cout << 1 << '\n';
            continue;
        }

        for(int i=0; i<=n; ++i) {
            for(int j=0; j<=k_ops; ++j) {
                dp[i][j][0] = dp[i][j][1] = 0;
            }
        }

        dp[n][0][0] = 1;

        for (int i = n - 1; i >= 0; --i) {
            int s_val_i = s[i] - '0';
            for (int j = 0; j <= k_ops; ++j) { 
                dp[i][j][j % 2] = (dp[i][j][j % 2] + dp[i+1][j][j % 2]) % MOD;
                dp[i][j][0] = (dp[i][j][0] + dp[i+1][j][0]) % MOD;
                dp[i][j][1] = (dp[i][j][1] + dp[i+1][j][1]) % MOD;


                if (j > 0) {
                    for (int p_suffix = 0; p_suffix <= 1; ++p_suffix) {
                        if (dp[i+1][j-1][p_suffix] == 0) continue;

                        if ((s_val_i ^ p_suffix) == 0) {
                            int current_ops_parity = (1 + p_suffix) % 2;
                            
                            ll ways_to_pick_j_minus_1_ops = dp[i+1][j-1][p_suffix];
                            ll term = (j * ways_to_pick_j_minus_1_ops) % MOD;
                            dp[i][j][current_ops_parity] = (dp[i][j][current_ops_parity] + term) % MOD;
                        }
                    }
                }
            }
        }
        
        ll ans = (dp[0][k_ops][0] + dp[0][k_ops][1]) % MOD;
        cout << ans << '\n';
    }
    return 0;
}