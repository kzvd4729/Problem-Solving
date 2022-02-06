/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/31/2018 19:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/919/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int x,ans,r,sum,k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>k;
    for(int i=1;i<=10800100;i++)
    {
        x=i;
        sum=0;
        while(x)
        {
            r=x%10;
            sum+=r;
            x/=10;
            if(sum>10)break;
        }
        if(sum==10)ans++;
        if(ans==k)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}