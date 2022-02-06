/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2018 21:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 233 ms                                          memory_used: 14200 KB                             
*  problem: https://codeforces.com/contest/932/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,a,b,x,y,now,tmp;
vector<long>v;
void euclid(void)
{
    for(long i=1;i<=n;i++)
    {
        if((n-(a*i))%b==0)
        {
            x=i;
            y=(n-(a*i))/b;
            return ;
        }
    }
}
void make_circle(long x)
{
    long st=now++;
    for(long i=2;i<=x;i++)v.push_back(now++);
    v.push_back(st);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>n>>a>>b;
     now=1;
     if(n%a==0)
    {
        tmp=n/a;
        while(tmp--)make_circle(a);
        for(auto x:v)cout<<x<<" ";
        cout<<endl;
        return 0;
    }
    if(n%b==0)
    {
        tmp=n/b;
        while(tmp--)make_circle(b);
        for(auto x:v)cout<<x<<" ";
        cout<<endl;
        return 0;
    }
    euclid();
    if(x<=0||y<=0)
    {
        cout<<-1<<endl;
        return 0;
    }
    while(x--)make_circle(a);
    while(y--)make_circle(b);
     for(auto x:v)cout<<x<<" ";
    cout<<endl;
     return 0;
}