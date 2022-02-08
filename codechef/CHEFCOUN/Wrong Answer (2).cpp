/****************************************************************************************
*  @author: kzvd4729                                         created: 06-10-2017 16:19:51                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/OCT17/problems/CHEFCOUN
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(long i=1;i<=n;i++)
        {
            cout<<2000000000;
            if(i==n)cout<<endl;
            else cout<<" ";
        }
    }
    return 0;
}