/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/05/2017 17:33                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/868/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long h,m,s,t1,t2,f;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>h>>m>>s>>t1>>t2;
    h++;
    if(h>12)h-=12;
    m=m/5;
    m++;
    if(m>12)m-=12;
    s=s/5;
    s++;
    if(s>12)s-=12;
    for(long i=t1+1;  ;i++)
    {
        long ii;
        if(i>12)ii=i-12;
        if(ii==h)f++;
        if(ii==m)f++;
        if(ii==s)f++;
        if(ii==t2)break;
    }
    if(f==0||f==3)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}