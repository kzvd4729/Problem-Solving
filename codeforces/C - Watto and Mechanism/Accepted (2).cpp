/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2018 18:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 670 ms                                          memory_used: 44800 KB                             
*  problem: https://codeforces.com/contest/514/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long mod1=1000000007;
const long mod2=1000000009;
long n,q,tmp[600005],hs1,hs2,ths1,ths2,bll1,bll2,pw1[600005],pw2[600005];
string s;
map<pair<long,long>,long>mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     pw1[0]=1;
    for(long i=1;i<=600000;i++)pw1[i]=(pw1[i-1]*31)%mod1;
    pw2[0]=1;
    for(long i=1;i<=600000;i++)pw2[i]=(pw2[i-1]*37)%mod2;
     cin>>n>>q;
    for(long i=1;i<=n;i++)
    {
        cin>>s;
        hs1=0;
        for(long j=1;j<=s.size();j++)hs1=(hs1+(pw1[j-1]*s[j-1]))%mod1;
        hs2=0;
        for(long j=1;j<=s.size();j++)hs2=(hs2+(pw2[j-1]*s[j-1]))%mod2;
        for(long j=1;j<=s.size();j++)
        {
            ths1=(hs1-pw1[j-1]*s[j-1]+mod1)%mod1;
            ths2=(hs2-pw2[j-1]*s[j-1]+mod2)%mod2;
            bll1=(ths1+pw1[j-1]*('a'*1LL))%mod1;
            bll2=(ths2+pw2[j-1]*('a'*1LL))%mod2;
            if(bll1!=hs1&&bll2!=hs2)mp[{bll1,bll2}]=1;
            bll1=(ths1+pw1[j-1]*('b'*1LL))%mod1;
            bll2=(ths2+pw2[j-1]*('b'*1LL))%mod2;
            if(bll1!=hs1&&bll2!=hs2)mp[{bll1,bll2}]=1;
            bll1=(ths1+pw1[j-1]*('c'*1LL))%mod1;
            bll2=(ths2+pw2[j-1]*('c'*1LL))%mod2;
            if(bll1!=hs1&&bll2!=hs2)mp[{bll1,bll2}]=1;
        }
    }
    while(q--)
    {
        cin>>s;
        hs1=0;
        for(long j=1;j<=s.size();j++)hs1=(hs1+(pw1[j-1]*s[j-1]))%mod1;
        hs2=0;
        for(long j=1;j<=s.size();j++)hs2=(hs2+(pw2[j-1]*s[j-1]))%mod2;
        if(mp[{hs1,hs2}])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}