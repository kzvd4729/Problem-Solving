/****************************************************************************************
*  @author: kzvd4729#                                        created: May/03/2017 15:33                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/750/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,i;
    cin>>n>>t;
    t=240-t;
    int cnt=0;
    int sum=0;
    for(i=5;  ;i=i+5)
    {
        sum=sum+i;
        if(sum>t)break;
        cnt++;
    }
    if(cnt>n)cnt=n;
    cout<<cnt<<endl;
    return 0;
}