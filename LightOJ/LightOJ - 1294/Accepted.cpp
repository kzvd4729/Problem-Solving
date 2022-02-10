/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-13 17:41:42                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 344                                        memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1294
****************************************************************************************/
#include<iostream>
using namespace std;
#define ll long long int
int main()
{
    ll t,n,m,x,tc=0;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n>>m;

            x=(n/m)/2;

            cout<<"Case "<<++tc<<": "<<x*m*m<<endl;


        }

    }

    return 0;
}