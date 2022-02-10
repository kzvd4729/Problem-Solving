/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-28 16:45:19                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 962                                        memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-4682
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,n,x,xx,ans,now,sz,sum;
int trie[31*100000][3];
void insrt(int x)
{
    now=0;
    for(int i=31;i>=0;i--)
    {
        bool z=x&(1<<i);
        if(!trie[now][z])trie[now][z]=++sz;
        now=trie[now][z];
    }
}
void query(int x)
{
    now=0,sum=0;
    for(int i=31;i>=0;i--)
    {
        bool z=x&(1<<i);
        if(trie[now][!z])
        {
            sum+=(1<<i);
            now=trie[now][!z];
        }
        else now=trie[now][z];
    }
}
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        memset(trie,0,sizeof(trie));
        xx=0,ans=0,sz=0;
        insrt(xx);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            xx=xx^x;
            query(xx);
            ans=max(ans,sum);
            insrt(xx);
        }
        cout<<ans<<endl;
    }
    return 0;
}