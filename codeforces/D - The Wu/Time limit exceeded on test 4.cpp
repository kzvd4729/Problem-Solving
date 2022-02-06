/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/09/2018 15:58                        
*  solution_verdict: Time limit exceeded on test 4           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 4600 KB                              
*  problem: https://codeforces.com/contest/1017/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define ll long long
#define pb(x) push_back(x)
#define N 500005
using namespace std;
string str,str2[5005];
ll w[20],k,k2,n;
vector<char> ex;
ll vis[5005][105];
ll hm[5005];
ll mask(string str)
{
    ll x=0;
    for(ll i=str.size()-1;i>=0;i--)
    {
        x*=2;
        x+=str[i]-'0';
    }
    return x;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     ll m,q,i;
    cin>>n>>m>>q;
     for(i=0;i<n;i++)cin>>w[i];
    for(i=0;i<m;i++)
    {
        cin>>str;
        ll x=mask(str);
         hm[x]++;
    }
    for(i=0;i<k;i++)
    {
        ll pos=mask(str2[i]);
    }
    for(i=0;i<(1<<n);i++)
    {
      for(int j=0;j<(1<<n);j++)
      {
        int x=0;
        for(int k=0;k<n;k++)
        {
          if((i&(1<<k))==(j&(1<<k)))
          {
            x+=w[k];
          }
        }
        if(x<=100)vis[i][x]+=hm[j];
      }
    }
    for(i=0;i<q;i++)
    {
        string s;
        ll c;ll ans=0;
        cin>>s>>c;
        ll pos=mask(s);
        for(int j=0;j<=c;j++)
          ans+=(vis[pos][j])*1LL;
        cout<<ans<<"\n"<<endl;
    }
    return 0;
}