/****************************************************************************************
*  @author: kzvd4729                                         created: 22-10-2017 22:00:50                      
*  solution_verdict: Time Limit Exceeded                     language: C++14                                   
*  run_time: 2.01 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/COOK87/problems/CK87QUER
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,y;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>y;
        long ans=0;
        for(long i=1;  ;i++)
        {
            long x=i*i;
            if(x>=y)break;
            ans+=min(700LL,y-x);
        }
        cout<<ans<<endl;
    }
    return 0;
}