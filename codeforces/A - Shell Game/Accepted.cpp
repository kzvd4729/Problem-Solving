/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/24/2017 17:01                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 30 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/777/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,x,z,a;
    while(cin>>n>>x)
    {
        z=n%6;
         if(z==0)z=6;
         if(z==1)
        {
            if(x==0)cout<<1<<endl;
            else if(x==1)cout<<0<<endl;
            else if(x==2)cout<<2<<endl;
        }
        else if(z==2)
        {
            if(x==0)cout<<1<<endl;
            else if(x==1)cout<<2<<endl;
            else if(x==2)cout<<0<<endl;
        }
        else if(z==3)
        {
            if(x==0)cout<<2<<endl;
            else if(x==1)cout<<1<<endl;
            else if(x==2)cout<<0<<endl;
        }
        else if(z==4)
        {
            if(x==0)cout<<2<<endl;
            else if(x==1)cout<<0<<endl;
            else if(x==2)cout<<1<<endl;
        }
        else if(z==5)
        {
            if(x==0)cout<<0<<endl;
            else if(x==1)cout<<2<<endl;
            else if(x==2)cout<<1<<endl;
        }
        else if(z==6)
        {
            if(x==0)cout<<0<<endl;
            else if(x==1)cout<<1<<endl;
            else if(x==2)cout<<2<<endl;
        }
        }
      return 0;
}