/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/10/2017 12:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/879/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,x,y,mx=0,cnt;
deque<pair<long,long> >dq;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>k;
    while(n--)
    {
        cin>>x;
        mx=max(mx,x);
        dq.push_back({x,0});
    }
    long ans;
    pair<long,long>a,b;
    while(true)
    {
        a=dq.front();
        dq.pop_front();
        b=dq.front();
        dq.pop_front();
        if(a.first==mx)
        {
            ans=a.first;
            break;
        }
        else if(b.first==mx)
        {
            ans=b.first;
            break;
        }
        if(a.first>b.first)
        {
            a.second++;
            dq.push_front(a);
            dq.push_back(b);
            if(a.second==k)
            {
                ans=a.first;
                break;
            }
        }
        else
        {
            b.second++;
            dq.push_front(b);
            dq.push_back(a);
            if(b.second==k)
            {
                ans=b.first;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
 