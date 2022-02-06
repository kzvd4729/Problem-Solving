/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/15/2017 23:28                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/872/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long q,n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>q;
    while(q--)
    {
        cin>>n;
        if(n==1||n==2||n==3||n==5||n==7||n==11)cout<<-1<<endl;
        else
        {
            if(n%4==0)cout<<n/4<<endl;
            else if(n%4==1)cout<<((n-9)/4)+1<<endl;
            else if(n%4==2)cout<<((n-6)/4)+1<<endl;
            else cout<<((n-15)/4)+1<<endl;
        }
    }
     return 0;
}