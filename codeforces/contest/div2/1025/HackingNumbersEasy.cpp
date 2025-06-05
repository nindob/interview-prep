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

ll read_jury_response() {
    ll response;
    cin >> response;
    return response;
}

signed main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t; 
    cin >> t;
    while(t--)
    {
        ll n_target;
        cin >> n_target;

        ll jury_response_val;

        
        if (n_target == 1) {
            cout << "!" << endl; 
            jury_response_val = read_jury_response(); 
        } else {
            cout << "mul " << n_target << endl;
            jury_response_val = read_jury_response();
            
            cout << "!" << endl;
            jury_response_val = read_jury_response();
        }
    }
    return 0;
}