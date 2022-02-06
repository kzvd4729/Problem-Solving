/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/05/2017 21:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/877/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long aa[5005],bb[5005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     string s;
     cin>>s;
    long l=s.size();
     long a=0,b=0;
    for(long i=0;i<l;i++)
    {
        if(s[i]=='a')a++;
        else b++;
        aa[i]=a;
        bb[i]=b;
    }
    long ans=aa[l-1];
    long x;
    for(long i=0;i<l;i++)
    {
        for(long j=i;j<l;j++)
        {
            if(i==0)
            {
                x=aa[l-1]-aa[j]+bb[j];
            }
            else x=aa[i-1]+aa[l-1]-aa[j]+bb[j]-bb[i-1];
            ans=max(ans,x);
        }
    }
    cout<<ans<<endl;
     return 0;
}