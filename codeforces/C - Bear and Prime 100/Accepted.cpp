/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/18/2018 20:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/680/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long cnt,zz;
string s;
vector<long>pr;
void seive()
{
    pr.push_back(2);
    pr.push_back(3);
    pr.push_back(5);
    pr.push_back(7);
    for(long i=2; i<=50; i++)
    {
        if(i%2==0||i%3==0||i%5==0||i%7==0)continue;
        pr.push_back(i);
    }
}
int main()
{
    seive();
    cout<<2<<endl;
    fflush(stdout);
    cin>>s;
    if(s=="yes")cnt++,zz=2;
    cout<<3<<endl;
    fflush(stdout);
    cin>>s;
    if(s=="yes")cnt++,zz=3;
    cout<<5<<endl;
    fflush(stdout);
    cin>>s;
    if(s=="yes")cnt++,zz=5;
    cout<<7<<endl;
    fflush(stdout);
    cin>>s;
    if(s=="yes")cnt++,zz=7;
    if(cnt==0)
    {
        cout<<"prime"<<endl;
        fflush(stdout);
        return 0;
    }
    if(cnt>1)
    {
        cout<<"composite"<<endl;
        fflush(stdout);
        return 0;
    }
    for(auto x:pr)
    {
        long xx=zz*x;
        if(xx>100)continue;
        cout<<xx<<endl;
        fflush(stdout);
        cin>>s;
        if(s=="yes")cnt++;
    }
    if(cnt!=1)
    {
        cout<<"composite"<<endl;
        fflush(stdout);
    }
    else
    {
        cout<<"prime"<<endl;
        fflush(stdout);
    }
    return 0;
}