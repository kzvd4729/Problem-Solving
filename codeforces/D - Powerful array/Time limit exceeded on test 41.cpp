/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/18/2018 22:27                        
*  solution_verdict: Time limit exceeded on test 41          language: GNU C++14                               
*  run_time: 5000 ms                                         memory_used: 19100 KB                             
*  problem: https://codeforces.com/contest/86/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long n,q,arr[200002],fr[1000006],ans[200005];
struct data
{
    long long l,r,id,sg;
} qr[200002];
bool cmp(data A,data B)
{
    if(A.sg!=B.sg)
        return A.sg<B.sg;
    else
        return A.r<B.r;
}
int main()
{
    scanf("%I64d",&n);
    scanf("%I64d",&q);
    for(long long i=1; i<=n; i++)
        scanf("%I64d",&arr[i]);
    long long sq=sqrt(n);
    for(long long i=1; i<=q; i++)
    {
        scanf("%I64d",&qr[i].l);
        scanf("%I64d",&qr[i].r);
        qr[i].id=i;
        qr[i].sg=qr[i].l/sq;
    }
    sort(qr+1,qr+q+1,cmp);
    long long pl,pr,nl,nr;
    pl=qr[1].l;
    pr=qr[1].r;
    long long sum=0;
    for(long long k=pl; k<=pr; k++)
    {
        sum-=fr[arr[k]]*fr[arr[k]]*arr[k];
        fr[arr[k]]++;
        sum+=fr[arr[k]]*fr[arr[k]]*arr[k];
    }
    ans[qr[1].id]=sum;
    for(long long i=2; i<=q; i++)
    {
        nl=qr[i].l;
        nr=qr[i].r;
        for(long long k=nl; k<pl; k++)
        {
            sum-=fr[arr[k]]*fr[arr[k]]*arr[k];
            fr[arr[k]]++;
            sum+=fr[arr[k]]*fr[arr[k]]*arr[k];
        }
        for(long long k=pl; k<nl; k++)
        {
            sum-=fr[arr[k]]*fr[arr[k]]*arr[k];
            fr[arr[k]]--;
            sum+=fr[arr[k]]*fr[arr[k]]*arr[k];
        }
        for(long long k=pr+1; k<=nr; k++)
        {
            sum-=fr[arr[k]]*fr[arr[k]]*arr[k];
            fr[arr[k]]++;
            sum+=fr[arr[k]]*fr[arr[k]]*arr[k];
        }
        for(long long k=nr+1; k<=pr; k++)
        {
            sum-=fr[arr[k]]*fr[arr[k]]*arr[k];
            fr[arr[k]]--;
            sum+=fr[arr[k]]*fr[arr[k]]*arr[k];
        }
        ans[qr[i].id]=sum;
        pl=nl;
        pr=nr;
    }
    for(long long i=1; i<=q; i++)
        printf("%I64d\n",ans[i]);
    return 0;
}