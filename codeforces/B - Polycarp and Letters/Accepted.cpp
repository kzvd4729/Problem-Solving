/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/25/2017 17:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/864/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string ss,s;
long fre[303],n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    cin>>s;
    ss.push_back('Z');
    for(long i=0;i<s.size();i++)
    {
        ss.push_back(s[i]);
    }
    ss.push_back('Z');
    long l=1,r=1;
    long ans=0;
    for(long i=0;i<=n+1;i++)
    {
        if(ss[i]>='a'&&ss[i]<='z')continue;
        r=i-1;
        memset(fre,0,sizeof(fre));
        long cnt=0;
        for(long k=l;k<=r;k++)
        {
            if(fre[ss[k]]==0)cnt++;
            fre[ss[k]]=1;
        }
        ans=max(ans,cnt);
        l=i+1;
    }
    cout<<ans<<endl;
     return 0;
}