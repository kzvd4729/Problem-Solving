/****************************************************************************************
*  @author: kzvd4729                                         created: 01-02-2018 21:56:07                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.98 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/problems/CHAPD
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,a,b,f;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        f=0;
        long bb=b;
        for(int i=2;i<=sqrt(bb);i++)
        {
            if(b%i==0)
            {
                while(b%i==0)b=b/i;
                if(a%i!=0)f=1;
            }
        }
        if(a%b!=0)f=1;
        if(f==1)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}