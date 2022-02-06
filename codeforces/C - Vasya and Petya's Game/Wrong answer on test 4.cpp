/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/13/2018 01:40                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/577/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,fr[1002];
vector<long>v[1003],ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
     for(long i=2; i<=n; i++)
    {
        long x=i;
        for(long j=2; j<=x; j++)
        {
            while(x%j==0)
            {
                v[i].push_back(j);
                x/=j;
            }
            if(j>x)break;
        }
    }
     for(long i=2; i<=n; i++)
    {
        long f=0;
        for(auto x:v[i])
        {
            fr[x]--;
            if(fr[x]<0)f=1;
        }
        if(f==1)
        {
            ans.push_back(i);
            for(auto x:v[i])fr[x]+=2;
        }
        else for(auto x:v[i])fr[x]++;
    }
    cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x<<" ";
    return 0;
}