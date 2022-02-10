/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-24 18:05:01                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-6133
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m=10000007;
vector<ll>adj[10000007];
ll nul[10000007];
void make_tree(ll has,char ch)
{
    ll temp=has*31+ch-'a'+1;
    temp%=m;
    ll f=0;
    for(int i=0;i<adj[has].size();i++)
    {
        if(adj[has][i]==temp)f=1;
    }
    if(f==0)
    {
        adj[has].push_back(temp);
    }
}
ll fn(ll has,char ch)
{
    if(has==0)return 1;
    if(adj[has].size()>1)return 1;
    if(nul[has]==1)return 1;
    return 0;
}
int main()
{
    ll n,i,has,j;
    string str[100005];
    while(cin>>n)
    {
        for(i=0;i<10000007;i++)
        {
            adj[i].clear();
            nul[i]=0;
        }

        for(i=0;i<n;i++)
        {
            cin>>str[i];
            has=0;
            for(j=0;j<str[i].size();j++)
            {
                make_tree(has,str[i][j]);
                has*=31;
                has+=str[i][j]-'a'+1;
                has%=m;
            }
            nul[has]=1;
        }

        ll sum=0;
        for(i=0;i<n;i++)
        {
            has=0;
            for(j=0;j<str[i].size();j++)
            {
                sum+=fn(has,str[i][j]);
                has*=31;
                has+=str[i][j]-'a'+1;
                has%=m;
            }
        }
        double rslt=(sum*1.00/n);
        cout<<setprecision(2)<<fixed<<rslt<<endl;
    }
    return 0;
}