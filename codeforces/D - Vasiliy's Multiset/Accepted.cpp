/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/26/2017 17:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 436 ms                                          memory_used: 156900 KB                            
*  problem: https://codeforces.com/contest/706/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long q,x,idx;
string s;
struct data
{
    long arr[3];
    long cnt[3];
}trie[100005*33];
void insrt(long z)
{
    long now=0;
    for(long i=31;i>=0;i--)
    {
        bool x=(z&(1<<i));
        if(trie[now].arr[x]==0)
        {
            trie[now].arr[x]=++idx;
        }
        trie[now].cnt[x]++;
        now=trie[now].arr[x];
    }
}
void del(long z)
{
    long now=0;
    for(long i=31;i>=0;i--)
    {
        bool x=(z&(1<<i));
        trie[now].cnt[x]--;
        now=trie[now].arr[x];
    }
}
long qry(long z)
{
    long now=0,ans=0;
    for(long i=31;i>=0;i--)
    {
        bool x=(z&(1<<i));
        if(trie[now].arr[x^1]!=0&&trie[now].cnt[x^1]>=1)
        {
            ans|=(1<<i);
            ///cout<<(1<<i)<<endl;
            now=trie[now].arr[x^1];
        }
        else now=trie[now].arr[x];
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     insrt(0);
     cin>>q;
    while(q--)
    {
        cin>>s>>x;
        if(s=="+")insrt(x);
        else if(s=="-")del(x);
        else cout<<qry(x)<<endl;
    }
    return 0;
}