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
int a[505][505];
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
            for(int j=0;j<n;j++) a[i][j]=-1;
        }
        a[0][0]=0;
        int dx=1,dy=0,x=0,y=0;
        for(int i=0;i<n*n-1;i++)
        {
            if(x+dx>=n||x+dx<0||y+dy>=n||y+dy<0||a[x+dx][y+dy]!=-1)
            {
                if(dx==1&&dy==0)
                {
                    dx=0;
                    dy=1;
                }
                else if(dx==0&&dy==1)
                {
                    dx=-1;
                    dy=0;
                }
                else if(dx==-1&&dy==0)
                {
                    dx=0;
                    dy=-1;
                }
                else
                {
                    dx=1;
                    dy=0;
                }
            }
            x+=dx;
            y+=dy;
            a[x][y]=i+1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<n*n-1-a[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
}