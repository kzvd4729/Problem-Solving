/****************************************************************************************
*  @author: kzvd4729#                                        created: Aug/22/2017 19:50                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 6200 KB                              
*  problem: https://codeforces.com/contest/845/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 100005
using namespace std;
priority_queue<pair<long,long> >pq;
long n,u,v,a,b,c,d;
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    while(n--)
    {
        cin>>u>>v;
        pq.push({-u,-v});
    }
    a=pq.top().first;
    b=pq.top().second;
    pq.pop();
    while(!pq.empty())
    {
        c=pq.top().first;
        d=pq.top().second;
        pq.pop();
        if(c>b)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        a=c;
        b=d;
    }
    cout<<"YES"<<endl;
     return 0;
}
 