/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/26/2017 00:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/742/problem/A
****************************************************************************************/
#include<iostream>
using namespace std;
long long int bigmod(long long int b,long long int p,long long int m)
{
    long long int x;
     if(p==0)return 1;
     if(p%2==0)
    {
        x=bigmod(b,p/2,m);
        return ((x%m)*(x%m))%m;
    }
     else return ((b%m)*(bigmod(b,p-1,m)%m))%m;
 }
int main()
{
    long long int b,p,m,z;
    while(cin>>p)
    {
         z=bigmod(8,p,10);
         cout<<z<<endl;
     }
     return 0;
}