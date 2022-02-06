/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/27/2018 21:25                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 119500 KB                            
*  problem: https://codeforces.com/contest/7/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s;
const long mod=1000009;
long ans,hs[5000006],sh[5000006],b,two[5000006],nxt,now;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>s;
    for(long i=0;s[i]; i++)
    {
        if(!i)b=1;
        else b=(b*11)%mod;
        hs[i]=(hs[i-1]+s[i]*b)%mod;
    }
    for(long i=0;s[i]; i++)
    {
        sh[i]=(sh[i-1]*11+s[i])%mod;
        if(sh[i]==hs[i])
        {
            two[i]=two[(i+1)/2-1]+1;
            ans+=two[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}