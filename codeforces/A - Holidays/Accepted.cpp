/****************************************************************************************
*  @author: kzvd4729#                                        created: May/13/2017 10:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/670/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,y;
    cin>>n;
    x=(n/7)*2;
    if(n%7==6)x++;
    y=(n/7)*2;
    if(n%7==1)y++;
    else if(n%7>=2)y=y+2;
    cout<<x<<" "<<y<<endl;
    return 0;
}