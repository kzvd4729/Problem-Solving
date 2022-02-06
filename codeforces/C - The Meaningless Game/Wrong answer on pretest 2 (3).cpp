/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/30/2017 22:14                        
*  solution_verdict: Wrong answer on pretest 2               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/834/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,a,b,z,x,q,i,l;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     cin>>n;
    while(n--)
    {
        cin>>a>>b;
        z=a*b;
         int f=0;
         for(i=2;i<=1000;i++)
        {
            q=i*i*i;
            while(z%q==0)
            {
                z=z/q;
            }
            if(z==1)
            {
                f=1;
                cout<<"YES"<<endl;
                break;
            }
        }
        if(f==0)cout<<"NO"<<endl;
    }
    return 0;
}