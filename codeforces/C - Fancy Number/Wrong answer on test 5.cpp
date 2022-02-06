/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/16/2018 15:40                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/118/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,z=9999999999999999;
string s,tmp,zz="z";
priority_queue<pair<long,long> >pq;
map<long,string>mp;
int main()
{
    cin>>n>>k;
    cin>>s;
     for(long i=0;i<=9;i++)
    {
        for(long j=0;j<s.size();j++)
        {
            long x=s[j]-'0';
            pq.push({-abs(x-i),j});
        }
        long ans=0;
        tmp=s;
        for(long j=1;j<=k;j++)
        {
            long x=pq.top().first;
            long y=pq.top().second;
            pq.pop();
            ans-=x;
            tmp[y]=i+'0';
        }
        while(pq.size())pq.pop();
        if(ans<z)
        {
            z=ans;
            zz=tmp;
        }
        if(ans==z)zz=min(zz,tmp);
     }
    cout<<z<<endl;
    cout<<zz<<endl;
    return 0;
}