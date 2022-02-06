/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/15/2017 20:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/797/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>v;
int nod(int n)
{
    int i;
    for(i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            v.push_back(i);
            n=n/i;
            i=1;
        }
        if(n==1)break;
    }
}
int main()
{
    int i,x;
    cin>>n>>k;
    nod(n);
    if(v.size()<k)cout<<-1<<endl;
    else
    {
        x=1;
        for(i=0;i<k-1;i++)
        {
            cout<<v[i]<<" ";
        }
        for(i=k-1;i<v.size();i++)
        {
            x=x*v[i];
        }
        cout<<x<<endl;
    }
    v.clear();
    return 0;
}