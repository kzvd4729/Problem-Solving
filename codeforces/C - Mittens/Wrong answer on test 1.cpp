/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/12/2018 13:08                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/370/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,cnt[102],x;
priority_queue<pair<long,long> >pq;
vector<pair<long,long> >ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
    for(long i=1; i<=n; i++)
    {
        cin>>x;
        cnt[x]+=2;
    }
    for(long i=1; i<=m; i++)
    {
        if(cnt[i]==0)continue;
        pq.push({cnt[i],i});
    }
    long sum=0;
    while(true)
    {
        pair<long,long>p1,p2;
        long l=pq.size();
        if(l==0)break;
        else if(l==1)
        {
            p1=pq.top();
            pq.pop();
            ans.push_back({p1.second,p1.second});
            p1.first-=2;
            if(p1.first)pq.push(p1);
        }
        else
        {
            p1=pq.top();
            pq.pop();
            p2=pq.top();
            pq.pop();
            p1.first--;
            p2.first--;
            sum++;
            ans.push_back({p1.second,p2.second});
            if(p1.first)pq.push(p1);
            if(p2.first)pq.push(p2);
        }
    }
    cout<<sum<<endl;
    for(auto xx:ans)
    {
        cout<<xx.first<<" "<<xx.second<<endl;
    }
    return 0;
}