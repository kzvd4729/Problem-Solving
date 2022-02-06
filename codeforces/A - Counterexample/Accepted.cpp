/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/28/2017 13:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/483/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int l,r,f,i;
    while(cin>>l>>r)
    {
        f=0;
        for(i=l; i<=r-2; i++)
        {
            if(__gcd(i,i+2)!=1)
            {
                f=1;
                cout<<i<<" "<<i+1<<" "<<i+2<<endl;
                break;
            }
         }
        if(f==0)cout<<"-1"<<endl;
       }
      return 0;
}