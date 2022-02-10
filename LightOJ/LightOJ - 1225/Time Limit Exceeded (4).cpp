/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-16 09:00:28                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1225
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
string s1,s2;
long t,tc;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>s1;
        s2=s1;
        reverse(s2.begin(),s2.end());
        if(s1==s2)cout<<"Case "<<++tc<<": "<<"Yes"<<endl;
        else cout<<"Case "<<++tc<<": "<<"No"<<endl;
    }

    return 0;
}