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
int a[200005],b[200005],c[200005];
pair<int,int> p[200005];
int bit[200005],pos[200005];
void modify(int x)
{
    for(int i=x;i<=200000;i+=i&(-i)) bit[i]++;
}
int q(int x)
{
    int ans=0;
    for(int i=x;i;i-=i&(-i)) ans+=bit[i];
    return ans;
}
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
        int bc=0,cc=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(i%2==1) b[bc++]=a[i];
            else c[cc++]=a[i];
        }
        int t1=0,t2=0;
        {
            for(int i=0;i<bc;i++) p[i]={b[i],i};
            sort(p,p+bc);
            for(int i=0;i<bc;i++)
            {
                pos[p[i].S]=i;
            }
            int sum=0;
            for(int i=0;i<=bc+1;i++) bit[i]=0;
            for(int i=0;i<bc;i++)
            {
                //cout<<pos[i]<<endl;
                sum+=q(bc+1)-q(pos[i]+1);
                modify(pos[i]+1);
            }
            t1=sum%2;
        }
        {
            for(int i=0;i<cc;i++) p[i]={c[i],i};
            sort(p,p+cc);
            for(int i=0;i<cc;i++)
            {
                pos[p[i].S]=i;
            }
            int sum=0;
            for(int i=0;i<=cc+1;i++) bit[i]=0;
            for(int i=0;i<cc;i++)
            {
                sum+=q(cc+1)-q(pos[i]+1);
                modify(pos[i]+1);
            }
            t2=sum%2;
        }
        sort(b,b+bc);
        sort(c,c+cc);
        if(t1==t2)
        {
            for(int i=0;i<bc;i++)
            {
                cout<<b[i]<<' ';
                if(i<cc) cout<<c[i]<<' ';
            }
            cout<<'\n';
        }
        else
        {
            if(n%2==0) swap(c[cc-1],c[cc-2]);
            else swap(b[bc-1],b[bc-2]);
            for(int i=0;i<bc;i++)
            {
                cout<<b[i]<<' ';
                if(i<cc) cout<<c[i]<<' ';
            }
            cout<<'\n';
        }
    }
}
 