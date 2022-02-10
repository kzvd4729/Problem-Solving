/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-16 09:17:09                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1225
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
long t,tc,x1,x2,x,r;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>x1;
        x=x1;
        x2=0;
        while(x)
        {
            r=x%10;
            x2=(x2*10)+r;
            x=x/10;
        }
        if(x1==x2)cout<<"Case "<<++tc<<": "<<"Yes"<<endl;
        else cout<<"Case "<<++tc<<": "<<"No"<<endl;
    }

    return 0;
}