/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/18/2018 23:15                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 19100 KB                             
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
    for(int i=1; i<=n; i++)
        scanf("%I64d",&arr[i]);
    int sq=sqrt(n);
    for(int i=1; i<=q; i++)
    {
        scanf("%I64d",&qr[i].l);
        scanf("%I64d",&qr[i].r);
        qr[i].id=i;
        qr[i].sg=qr[i].l/sq;
    }
    sort(qr+1,qr+q+1,cmp);
    int pl,pr,nl,nr;
    pl=qr[1].l;
    pr=qr[1].r;
    long long sum=0;
    for(int k=pl; k<=pr; k++)
    {
        sum-=fr[arr[k]]*fr[arr[k]]*arr[k];
        fr[arr[k]]++;
        sum+=fr[arr[k]]*fr[arr[k]]*arr[k];
    }
    ans[qr[1].id]=sum;
    for(int i=2; i<=q; i++)
    {
        nl=qr[i].l;
        nr=qr[i].r;
        while(nl<pl)
        {
            sum-=fr[arr[nl]]*fr[arr[nl]]*arr[nl];
            fr[arr[nl]]++;
            sum+=fr[arr[nl]]*fr[arr[nl]]*arr[nl];
            nl++;
        }
        for(int k=pl; k<nl; k++)
        {
            sum-=fr[arr[k]]*fr[arr[k]]*arr[k];
            fr[arr[k]]--;
            sum+=fr[arr[k]]*fr[arr[k]]*arr[k];
        }
        for(int k=pr+1; k<=nr; k++)
        {
            sum-=fr[arr[k]]*fr[arr[k]]*arr[k];
            fr[arr[k]]++;
            sum+=fr[arr[k]]*fr[arr[k]]*arr[k];
        }
        for(int k=nr+1; k<=pr; k++)
        {
            sum-=fr[arr[k]]*fr[arr[k]]*arr[k];
            fr[arr[k]]--;
            sum+=fr[arr[k]]*fr[arr[k]]*arr[k];
        }
        ans[qr[i].id]=sum;
        pl=nl;
        pr=nr;
    }
    for(int i=1; i<=q; i++)
        printf("%I64d\n",ans[i]);
    return 0;
}