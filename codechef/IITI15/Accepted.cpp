/****************************************************************************************
*  @author: kzvd4729                                         created: 22-01-2018 14:43:24                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 1.97 sec                                        memory_used: 20.8M                                
*  problem: https://www.codechef.com/problems/IITI15
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,q,arr[20002],tmp[20002],sm[100000],bg[100000],ans[20002],cnt;
map<long,long>inc,dcc;
struct data
{
    long l,r,sg,id;
} qr[20002];
bool cmp(data A,data B)
{
    if(A.sg!=B.sg)return A.sg<B.sg;
    else return A.r<B.r;
}
void upd_sm(long id,long vl)
{
    for( ;id<=n;id+=id&-id)sm[id]+=vl;
}
void upd_bg(long id,long vl)
{
    for( ;id<=n;id+=id&-id)bg[id]+=vl;
}
long smaller(long id)
{
    long sum=0;
    for( ;id>0;id-=id&-id)sum+=sm[id];
    return sum;
}
long bigger(long id)
{
    long sum=0;
    for( ;id>0;id-=id&-id)sum+=bg[id];
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long i=1; i<=n; i++)
    {
        cin>>arr[i];
        tmp[i]=arr[i];
    }
    sort(tmp+1,tmp+n+1);
    cnt=0;
    for(long i=1; i<=n; i++)if(inc[tmp[i]]==0)inc[tmp[i]]=++cnt;
    cnt=0;
    for(long i=n; i>=1; i--)if(dcc[tmp[i]]==0)dcc[tmp[i]]=++cnt;
    long sq=sqrt(n);
    cin>>q;
    for(long i=1; i<=q; i++)
    {
        cin>>qr[i].l>>qr[i].r;
        qr[i].sg=qr[i].l/sq;
        qr[i].id=i;
    }
    sort(qr+1,qr+q+1,cmp);
    long pl,pr,nl,nr;
    pl=qr[1].l;
    pr=qr[1].r;
    cnt=0;
    for(long i=pl; i<=pr; i++)
    {
        cnt+=bigger(dcc[arr[i]]-1);
        upd_bg(dcc[arr[i]],1);
        upd_sm(inc[arr[i]],1);
    }
    ans[qr[1].id]=cnt;
    for(long k=2; k<=q; k++)
    {
        nl=qr[k].l;
        nr=qr[k].r;
        for(long i=pl-1; i>=nl; i--)
        {
            cnt+=smaller(inc[arr[i]]-1);
            upd_bg(dcc[arr[i]],1);
            upd_sm(inc[arr[i]],1);
        }
        for(long i=pl; i<nl; i++)
        {
            cnt-=smaller(inc[arr[i]]-1);
            upd_bg(dcc[arr[i]],-1);
            upd_sm(inc[arr[i]],-1);
        }
        for(long i=pr+1; i<=nr; i++)
        {
            cnt+=bigger(dcc[arr[i]]-1);
            upd_bg(dcc[arr[i]],1);
            upd_sm(inc[arr[i]],1);
        }
        for(long i=pr;i>nr;i--)
        {
            cnt-=bigger(dcc[arr[i]]-1);
            upd_bg(dcc[arr[i]],-1);
            upd_sm(inc[arr[i]],-1);
        }
        ans[qr[k].id]=cnt;
        pl=nl;
        pr=nr;
    }
//    cout<<endl<<endl;
//    for(long i=1;i<=q;i++)
//    {
//        cout<<qr[i].l<<" "<<qr[i].r<<" "<<ans[qr[i].id]<<endl;
//    }
//    cout<<endl<<endl;
    for(long i=1;i<=q;i++)cout<<ans[i]<<endl;
    return 0;
}