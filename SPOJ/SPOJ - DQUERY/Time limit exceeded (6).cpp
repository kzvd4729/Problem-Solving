/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-18 20:59:57                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-DQUERY
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int sq,n,arr[30004],q,fr[1000006],cnt;
struct mo
{
    int l,r,sg,id,ans;
} qu[200005];
bool cmp(mo A,mo B)
{
    if(A.sg==B.sg)return A.r<B.r;
    else return A.sg<B.sg;
}
bool cmp2(mo A,mo B)
{
    return A.id<B.id;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++)cin>>arr[i];
    cin>>q;
    sq=sqrt(n);
    for(int i=1; i<=q; i++)
    {
        cin>>qu[i].l>>qu[i].r;
        qu[i].id=i;
        qu[i].sg=i/sq;
    }
    sort(qu+1,qu+q+1,cmp);
    for(int i=qu[1].l; i<=qu[1].r; i++)
    {
        if(fr[arr[i]]==0)cnt++;
        fr[arr[i]]++;
    }
    qu[1].ans=cnt;
    int pl=qu[1].l;
    int pr=qu[1].r;
    for(int i=2; i<=q; i++)
    {
        int nl=qu[i].l;
        int nr=qu[i].r;

        for(int k=nl; k<pl; k++)
        {
            if(fr[arr[k]]==0)cnt++;
            fr[arr[k]]++;
        }
        for(int k=pl; k<nl; k++)
        {
            if(fr[arr[k]]==1)cnt--;
            fr[arr[k]]--;
        }
        for(int k=pr+1; k<=nr; k++)
        {
            if(fr[arr[k]]==0)cnt++;
            fr[arr[k]]++;
        }
        for(int k=nr+1; k<=pr; k++)
        {
            if(fr[arr[k]]==1)cnt--;
            fr[arr[k]]--;
        }
        pl=nl;
        pr=nr;
        qu[i].ans=cnt;
    }
    sort(qu+1,qu+q+1,cmp2);
    for(int i=1; i<=q; i++)cout<<qu[i].ans<<endl;
    return 0;
}