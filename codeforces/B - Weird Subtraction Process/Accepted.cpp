/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/06/2018 22:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/946/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int a,b,d;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b;
    while(true)
    {
        if(a==0||b==0)break;
        if(a>=2*b)
        {
            b=2*b;
            d=a/b;
            a-=b*d;
            b/=2;
            continue;
        }
        else if(b>=2*a)
        {
            a=2*a;
            d=b/a;
            b-=a*d;
            a/=2;
        }
        else break;
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}