/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/05/2017 19:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/gym/101375/problem/I
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,x,y,z,a,b;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        z=x+y;
        a=z/2;
        b=z-a;
        if(a==x||a==y)cout<<"Ok"<<endl;
        else cout<<a<<" "<<b<<endl;
    }
    return 0;
}