/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-08 17:53:15                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1010
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,m,n,tc=0;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&m,&n);
        cout<<"Case "<<++tc<<": "<<((m*n)+1)/2<<endl;
        
    }
    return 0;
}