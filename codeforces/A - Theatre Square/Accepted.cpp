/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/08/2017 11:21                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/1/problem/A
****************************************************************************************/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long int n,m,a,b,c;
    while(cin>>n>>m>>a)
    {
        b=ceil((double)n/(double)a);
        c=ceil((double)m/(double)a);
        cout<<b*c<<endl;
    }
     return 0;
}