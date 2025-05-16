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
int a[400005],b[400005],c[400005];
signed main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        //int ans=0;
        int mn=a[n],mx=a[n];
        int pos=n;
        for(int i=n;i>=1;i--)
        {
            while(pos-1>0&&(a[pos-1]<mn||a[pos-1]>mx))
            {
                pos--;
                mx=max(mx,a[pos]);
                mn=min(mn,a[pos]);
            }
            b[i]=pos;
            if(mx==a[i])
            {
                mx=a[i-1];
            }
            else if(mn==a[i])
            {
                mn=a[i-1];
            }
        }
        mn=a[1];
        mx=a[1];
        for(int i=1;i<=n;i++)
        {
            while(pos+1<=n&&(a[pos+1]<mn||a[pos+1]>mx))
            {
                pos++;
                mx=max(mx,a[pos]);
                mn=min(mn,a[pos]);
            }
            c[i]=pos;
            if(mx==a[i])
            {
                mx=a[i+1];
            }
            else if(mn==a[i])
            {
                mn=a[i+1];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
           // cout<<b[i]<<' '<<c[i]<<'\n';
            ans+=(i-b[i]+1)*(c[i]-i+1)-(i-1-b[i]+1)*(c[i-1]-i+1);
        }
        cout<<ans<<'\n';
    }
}