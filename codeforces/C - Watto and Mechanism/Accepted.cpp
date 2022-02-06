/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2018 18:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 592 ms                                          memory_used: 35500 KB                             
*  problem: https://codeforces.com/contest/514/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod=1004006003999;
long n,q,tmp[600005],hs,ths,bll,pw[600005];
string s;
map<long,long>mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     pw[0]=1;
    for(long i=1;i<=600000;i++)pw[i]=(pw[i-1]*497)%mod;
     cin>>n>>q;
    for(long i=1;i<=n;i++)
    {
        cin>>s;
        hs=0;
        for(long j=1;j<=s.size();j++)hs=(hs+(pw[j-1]*s[j-1]))%mod;
        for(long j=1;j<=s.size();j++)
        {
            ths=(hs-pw[j-1]*s[j-1]+mod)%mod;
            bll=(ths+pw[j-1]*('a'*1LL))%mod;
            if(bll!=hs)mp[bll]=1;
            bll=(ths+pw[j-1]*('b'*1LL))%mod;
            if(bll!=hs)mp[bll]=1;
            bll=(ths+pw[j-1]*('c'*1LL))%mod;
            if(bll!=hs)mp[bll]=1;
        }
    }
    while(q--)
    {
        cin>>s;
        hs=0;
        for(long j=1;j<=s.size();j++)hs=(hs+(pw[j-1]*s[j-1]))%mod;
        if(mp[hs])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}