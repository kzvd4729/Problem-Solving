/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-09-11 21:16:36                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 96                                         memory_used (MB): 4.2                             
*  problem: https://vjudge.net/problem/LightOJ-1059
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,x,t,tc,rt[10004],vis[10004];
struct data
{
    long u;
    long v;
    long c;
}arr[100004];
bool cmp(data A,data B)
{
    return A.c<B.c;
}
long root(long x)
{
    while(x!=rt[x])
    {
        rt[x]=rt[rt[x]];
        x=rt[x];
    }
    return x;
}
void mem(void)
{
    for(long i=1;i<=10000;i++)
    {
        vis[i]=0;
        rt[i]=i;
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
        mem();
        cin>>n>>m>>x;
        long id=0;
        for(long i=1;i<=m;i++)
        {
            long d1,d2,d3;
            cin>>d1>>d2>>d3;
            if(d3>=x)continue;
            ++id;
            arr[id].u=d1;
            arr[id].v=d2;
            arr[id].c=d3;
        }
        sort(arr+1,arr+id+1,cmp);
        long mst=0;
        for(long i=1;i<=id;i++)
        {
            long uu=root(arr[i].u);
            long vv=root(arr[i].v);
            if(uu!=vv)
            {
                mst+=arr[i].c;
                rt[uu]=rt[vv];
            }
        }
        for(long i=1;i<=n;i++)
        {
            long xx=root(i);
            rt[i]=xx;
        }
        long cnt=0;
        for(long i=1;i<=n;i++)
        {
            if(vis[rt[i]]==0)cnt++;
            vis[rt[i]]=1;
        }
        cout<<"Case "<<++tc<<": "<<mst+x*cnt<<" "<<cnt<<endl;
    }

    return 0;
}