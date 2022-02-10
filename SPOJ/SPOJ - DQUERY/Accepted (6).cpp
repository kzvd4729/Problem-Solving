/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-20 10:17:27                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 230                                        memory_used (MB): 23.6                            
*  problem: https://vjudge.net/problem/SPOJ-DQUERY
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,arr[30003],sq,q,vis[1000006],cnt,ans[200005];
struct data
{
    int l,r,sg,id;
}qr[200004];
bool cmp(data A,data B)
{
    if(A.sg!=B.sg)return A.sg<B.sg;
    else return A.r<B.r;
}
int main()
{
    scanf("%ld",&n);
    for(int i=1;i<=n;i++)scanf("%ld",&arr[i]);
    scanf("%ld",&q);
    sq=sqrt(n);
    for(int i=1;i<=q;i++)
    {
        scanf("%ld%ld",&qr[i].l,&qr[i].r);
        qr[i].sg=qr[i].l/sq;
        qr[i].id=i;
    }
    sort(qr+1,qr+q+1,cmp);
    int pl,pr,nl,nr;
    memset(vis,0,sizeof(vis));
    cnt=0;
    pl=qr[1].l;
    pr=qr[1].r;
    for(int i=pl;i<=pr;i++)
    {
        if(vis[arr[i]]==0)cnt++;
        vis[arr[i]]++;
    }
    ans[qr[1].id]=cnt;
    for(int k=2;k<=q;k++)
    {
        nl=qr[k].l;
        nr=qr[k].r;
        for(int i=nl;i<pl;i++)
        {
            if(vis[arr[i]]==0)cnt++;
            vis[arr[i]]++;
        }
        for(int i=pl;i<nl;i++)
        {
            if(vis[arr[i]]==1)cnt--;
            vis[arr[i]]--;
        }
        for(int i=pr+1;i<=nr;i++)
        {
            if(vis[arr[i]]==0)cnt++;
            vis[arr[i]]++;
        }
        for(int i=nr+1;i<=pr;i++)
        {
            if(vis[arr[i]]==1)cnt--;
            vis[arr[i]]--;
        }
        ans[qr[k].id]=cnt;
        pl=nl;
        pr=nr;
    }
    for(int i=1;i<=q;i++)
    {
        printf("%d\n",ans[i]);
    }
    printf("\n");
    return 0;
}