/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-24 14:41:20                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-6138
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin>>n)
    {
        if(n%6==0)cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }

    return 0;
}