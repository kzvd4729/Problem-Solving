/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/07/2018 23:31                        
*  solution_verdict: Hacked                                  language: GNU C++14                               
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
    if(org==0&&cpy==0)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    if(org==1)
    {
        if(cpy==0)
        {
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
        return 0;
    }
    int now=org-1;
    if(cpy<now)
    {
        cout<<"No"<<endl;
        return 0;
    }
    if((cpy-now)%2==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}