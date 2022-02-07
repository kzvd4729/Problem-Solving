/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-02-15 17:04:40                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 90                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10104
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,mod,x,y,a1,a2,b1,b2,res;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>x>>y)
    {
        a=1,b=0;
        a1=0,b1=1;
        while(y!=0)
        {
            mod=x%y;
            res=x/y;
            a2=a-(a1*res);
            b2=b-(b1*res);
            x=y;
            y=mod;
            a=a1,b=b1,a1=a2,b1=b2;
        }
        cout<<a<<" "<<b<<" "<<x<<endl;
    }
    return 0;
}