/****************************************************************************************
*  @author: kzvd4729                                         created: 27-01-2018 19:41:25                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 15.7M                                
*  problem: https://www.codechef.com/LTIME56/problems/L56GAME
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,x;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        long one=0,zero=0;
        for(long i=1;i<=n;i++)
        {
            cin>>x;
            if(x%2==0)zero++;
            else one++;
        }
        if(one%2==1)cout<<2<<endl;
        else cout<<1<<endl;
    }
    return 0;
}