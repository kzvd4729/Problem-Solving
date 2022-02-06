/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/23/2017 21:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/893/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
vector<long>v,dv;
long n,p,num,ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;  ;i++)
    {
        v.clear();
        for(long j=1;j<=i;j++)
        {
            v.push_back(1);
        }
        for(long j=1;j<i;j++)
        {
            v.push_back(0);
        }
        p=1;
        num=0;
        for(long j=v.size()-1;j>=0;j--)
        {
            num=num+v[j]*p;
            p*=2;
        }
        dv.push_back(num);
        if(num>n)break;
    }
    for(long i=0;i<dv.size();i++)
    {
        if(n%dv[i]==0)ans=dv[i];
    }
    cout<<ans<<endl;
     return 0;
}