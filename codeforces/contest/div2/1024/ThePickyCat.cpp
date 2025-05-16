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
int a[200005];
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
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            a[i]=abs(a[i]);
        }
        int b=0,s=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[0]) b++;
            else s++;
        }
        if((n%2==1&&s>(n+1)/2-1)||(n%2==0&&s>n/2)) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }
}