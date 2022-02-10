/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-16 18:47:37                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 180                                        memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1387
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
long t,n,m,total,tc;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n;
        total=0;
        cout<<"Case "<<++tc<<":"<<endl;
        while(n--)
        {
            cin>>s;
            if(s=="donate")cin>>m,total=total+m;
            else cout<<total<<endl;
        }
        
    }
    return 0;
}