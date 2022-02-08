/****************************************************************************************
*  @author: kzvd4729                                         created: 21-01-2018 23:39:56                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/COOK90/problems/SURVIVE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,s,t;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>s;
        long N=0,f=0,cnt=0;
        for(long i=1; i<=s; i++)
        {
            if((i%7)!=0)
            {
                N+=n;
                cnt++;
            }
            N-=k;
            if(N<0)
            {
                f=1;
            }
        }
        if(f==1)cout<<-1<<endl;
        else
        {
            cout<<cnt-(N/n)<<endl;
        }
    }
    return 0;
}