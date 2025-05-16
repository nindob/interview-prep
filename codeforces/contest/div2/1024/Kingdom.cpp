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
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            //a[i]=i;
        }
        if(n==1)
        {
            cout<<0<<'\n';
            continue;
        }
        int l=1,r=n/2;
        while(l<r)
        {
            set<int> s;
            int mid=(l+r+1)/2;
            for(int i=1;i<=mid;i++) s.insert(i);
            int pr=-1,pl=n+1;
            for(int i=n;i>=1;i--)
            {
                auto it=s.upper_bound(a[i]);
                if(it!=s.begin())
                {
                    it--;
                    s.erase(it);
                }
                if(s.empty())
                {
                    pr=i;
                    break;
                }
            }
            for(int i=1;i<=mid;i++) s.insert(i);
            for(int i=1;i<=n;i++)
            {
                auto it=s.upper_bound(a[i]);
                if(it!=s.begin())
                {
                    it--;
                    s.erase(it);
                }
                if(s.empty())
                {
                    pl=i;
                    break;
                }
            }
            if(pl<pr) l=mid;
            else r=mid-1;
        }
        int ans=0;
        set<int> s;
        for(int i=1;i<=l;i++) s.insert(i);
        for(int i=n;;i--)
        {
            auto it=s.upper_bound(a[i]);
            if(it!=s.begin())
            {
                it--;
                s.erase(it);
                ans+=i;
            }
            if(s.empty()) break;
        }
        for(int i=1;i<=l;i++) s.insert(i);
        for(int i=1;i<=n;i++)
        {
            auto it=s.upper_bound(a[i]);
            if(it!=s.begin())
            {
                it--;
                s.erase(it);
                ans-=i;
            }
            if(s.empty()) break;
        }
        cout<<ans<<'\n';
    }
}