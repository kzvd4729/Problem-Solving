/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/09/2018 20:41                        
*  solution_verdict: Wrong answer on test 21                 language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/922/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long cpy,org;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>cpy>>org;
     long now=org-1;
     if(org<=1)
    {
        cout<<"No"<<endl;
        return 0;
    }
    if(cpy<now)
    {
        cout<<"No"<<endl;
        return 0;
    }
    if((cpy-now)%2==0)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
     return 0;
}