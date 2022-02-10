/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-09-11 01:22:06                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 12                                         memory_used (MB): 4                               
*  problem: https://vjudge.net/problem/LightOJ-1040
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define inf 999999999999
using namespace std;
long t,mat[52][52],tc,x,id,a[52],s,d,c,zz,zzz,n,ans;
struct data
{
    long u;
    long v;
    long w;
} arr[100000];
bool cmp(data A,data B)
{
    return A.w<B.w;
}
void mem(void)
{
    for(long i=1; i<52; i++)
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
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        cin>>n;
        id=0;
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
            }
        }
        sort(arr+1,arr+id+1,cmp);
        mem();
        ans=0;
        for(long i=1; i<=id; i++)
        {
            s=arr[i].u;
            d=arr[i].v;
            c=arr[i].w;
            zz=root(s);
            zzz=root(d);
            if(zz==zzz)ans+=c;
            else a[zz]=a[zzz];
        }
        for(long i=1;i<=n;i++)
        {
            long ss=root(i);
            a[i]=ss;
        }
        long ss=a[1];
        long f=0;
        for(long i=2;i<=n;i++)
        {
            if(a[i]!=ss)
            {
                f=1;
            }
        }
        if(f==1)cout<<"Case "<<++tc<<": -1"<<endl;
        else cout<<"Case "<<++tc<<": "<<ans<<endl;

    }
    return 0;
}