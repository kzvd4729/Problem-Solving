/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/10/2018 00:27                        
*  solution_verdict: Wrong answer on test 42                 language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/922/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int cpy,org;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>cpy>>org;
    if(cpy==1&&org==2)
    {
        cout<<"No"<<endl;
        return 0;
    }
    int now=org-1;
     if(org<1)
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