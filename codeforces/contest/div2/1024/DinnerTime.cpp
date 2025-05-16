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
signed main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a%c==0&&d*(a/c)!=b) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }
}