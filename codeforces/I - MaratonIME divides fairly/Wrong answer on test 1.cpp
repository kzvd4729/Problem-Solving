/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/05/2017 19:19                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 1900 KB                              
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
        if(a==x)cout<<"OK"<<endl;
        else cout<<a<<" "<<b<<endl;
    }
    return 0;
}