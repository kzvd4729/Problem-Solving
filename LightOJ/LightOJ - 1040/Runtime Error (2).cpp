/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-09-10 22:37:40                      
*  solution_verdict: Runtime Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1040
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define inf 999999999
using namespace std;
long t,mat[52][52],tc,x,id,a[52],s,d,c,zz,zzz,n,ans,vis[52];
vector<long>adj[52];
struct data
{
    long u;
    long v;
    long w;
}arr[52];
bool cmp(data A,data B)
{
    return A.w<B.w;
}
void mem(void)
{
    for(long i=1;i<=n;i++)
    {
        a[i]=i;
    }
}
long root(long rt)
{
    while(true)
    {
        if(rt==a[rt])return rt;
        rt=a[rt];
        a[rt]=a[a[rt]];
    }
}
void dfs(long rt)
{
    vis[rt]=1;
    for(long i=0;i<adj[rt].size();i++)
    {
        if(vis[adj[rt][i]])continue;
        dfs(adj[rt][i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        cin>>n;
        id=0;
        for(long i=1;i<=n;i++)adj[i].clear();
        for(long i=1; i<=n; i++)
        {
            for(long j=1; j<=n; j++)
            {
                cin>>x;
                if(x==0)continue;
                id++;
                arr[id].u=i;
                arr[id].v=j;
                arr[id].w=x;
                adj[i].push_back(j);
            }
        }
        memset(vis,0,sizeof(vis));
        dfs(1);
        long f=0;
        for(long i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                cout<<"Case "<<++tc<<": "<<-1<<endl;
                f=1;
                break;
            }
        }
        if(f==1)continue;
        sort(arr+1,arr+id+1,cmp);
        mem();
        ans=0;
        for(long i=1;i<=id;i++)
        {
            s=arr[i].u;
            d=arr[i].v;
            c=arr[i].w;
            zz=root(s);
            zzz=root(d);
            if(zz==zzz)ans+=c;
            else a[zz]=zzz;
        }
        cout<<"Case "<<++tc<<": "<<ans<<endl;

    }
    return 0;
}