/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2018 21:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/931/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,rn,n,pw,cnt,lo,hi,md;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>n>>a>>b;
     pw=1;
    for(long i=1;i<=20;i++)
    {
        pw*=2;
        if(pw==n)
        {
            rn=i;
            break;
        }
    }
    if(a>b)swap(a,b);
    lo=0;hi=n;
    cnt=0;
    while(n)
    {
        md=(lo+hi)/2;
        if(a<=md&&b>md)break;
        if(a>md)lo=md;
        else hi=md;
        cnt++;
    }
    if(cnt==0)cout<<"Final!"<<endl;
    else cout<<rn-cnt<<endl;
    return 0;
}