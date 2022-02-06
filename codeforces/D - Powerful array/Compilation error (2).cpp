/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/22/2018 09:51                        
*  solution_verdict: Compilation error                       language: GNU C++17 Diagnostics                   
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/86/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,arr[200002],sq,q,i,k,pl,pr,nl,nr;
long long vis[1000006],sum,ans[200005];
struct data
{
    int l,r,sg,id;
} qr[200004];
bool cmp(data A,data B)
{
    if(A.sg!=B.sg)
        return A.sg<B.sg;
    else
        return A.r<B.r;
}
int main()
{
    scanf("%ld",&n);
    scanf("%ld",&q);
    for(i=1; i<=n; i++)scanf("%ld",&arr[i]);
    sq=sqrt(n);
    for(i=1; i<=q; i++)
    {
        scanf("%ld%ld",&qr[i].l,&qr[i].r);
        qr[i].sg=qr[i].l/sq;
        qr[i].id=i;
    }
    sort(qr+1,qr+q+1,cmp);
    sum=0;
    pl=qr[1].l;
    pr=qr[1].r;
    for(i=pl; i<=pr; i++)
    {
        sum-=vis[arr[i]]*vis[arr[i]]*arr[i];
        vis[arr[i]]++;
        sum+=vis[arr[i]]*vis[arr[i]]*arr[i];
    }
    ans[qr[1].id]=sum;
    for(k=2; k<=q; k++)
    {
        nl=qr[k].l;
        nr=qr[k].r;
        for(i=nl; i<pl; i++)
        {
            sum-=vis[arr[i]]*vis[arr[i]]*arr[i];
            vis[arr[i]]++;
            sum+=vis[arr[i]]*vis[arr[i]]*arr[i];
        }
        for(i=pl; i<nl; i++)
        {
            sum-=vis[arr[i]]*vis[arr[i]]*arr[i];
            vis[arr[i]]--;
            sum+=vis[arr[i]]*vis[arr[i]]*arr[i];
        }
        for(i=pr+1; i<=nr; i++)
        {
            sum-=vis[arr[i]]*vis[arr[i]]*arr[i];
            vis[arr[i]]++;
            sum+=vis[arr[i]]*vis[arr[i]]*arr[i];
        }
        for(i=nr+1; i<=pr; i++)
        {
            sum-=vis[arr[i]]*vis[arr[i]]*arr[i];
            vis[arr[i]]--;
            sum+=vis[arr[i]]*vis[arr[i]]*arr[i];
        }
        ans[qr[k].id]=sum;
        pl=nl;
        pr=nr;
    }
    for(i=1; i<=q; i++)
    {
        printf("%lld\n",ans[i]);
    }
    printf("\n");
    return 0;
}