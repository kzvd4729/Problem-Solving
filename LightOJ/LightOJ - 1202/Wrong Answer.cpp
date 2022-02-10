/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-18 19:55:09                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1202
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
long t,r1,c1,r2,c2,p1,p2,x1,x2,tc;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>r1>>c1>>r2>>c2;
        p1=0,p2=0;
        if((r1+c1)%2==0)p1=1;
        if((r2+c2)%2==0)p2=1;
        if(p1==p2)
        {
            x1=abs(r1-c1);
            x2=abs(r2-c2);
            if(x1==x2)cout<<"Case "<<++tc<<": "<<1<<endl;
            else cout<<"Case "<<++tc<<": "<<2<<endl;
        }
        else cout<<"Case "<<++tc<<": "<<"impossible"<<endl;
        
    }
    return 0;
}