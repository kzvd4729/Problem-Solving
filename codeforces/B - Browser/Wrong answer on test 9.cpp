/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/13/2018 19:34                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/915/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,pos,l,r;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>pos>>l>>r;
    if(l==1&&r==n)cout<<0<<endl;
    else if(l==1)
    {
        if(pos==r)cout<<1<<endl;
        else if(pos>r)cout<<2<<endl;
        else cout<<r-pos+1<<endl;
    }
    else if(r==n)
    {
        if(pos==l)cout<<1<<endl;
        else if(pos<l)cout<<2<<endl;
        else cout<<pos-l+1<<endl;
    }
    else
    {
        if(pos<l)
        {
            cout<<2+r-l+1<<endl;
        }
        else if(pos>r)
        {
            cout<<2+r-l+1<<endl;
        }
        else
        {
            cout<<min(pos-l+1+r-l+1,r-pos+1+r-l+1)<<endl;
        }
    }
     return 0;
}