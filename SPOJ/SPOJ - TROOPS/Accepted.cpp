/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-03 14:19:14                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 400                                        memory_used (MB): 77.8                            
*  problem: https://vjudge.net/problem/SPOJ-TROOPS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long seg[4000006],lazy[4000006],t,n,x;
const long N=1000000;
struct data
{
    long c,t,s;
}arr[10004];
bool cmp(data A,data B)
{
    return A.s>B.s;
}
void upd(long node,long lo,long hi,long l,long r)
{
    if(lazy[node])
    {
        seg[node]=hi-lo+1;
        if(lo!=hi)
        {
            lazy[node*2]=1;
            lazy[node*2+1]=1;
        }
    }
    lazy[node]=0;
    if(lo>r||hi<l)return ;
    if(lo>=l&&hi<=r)
    {
        seg[node]=hi-lo+1;
        if(lo!=hi)
        {
            lazy[node*2]=1;
            lazy[node*2+1]=1;
        }
        return ;
    }
    long md=(lo+hi)/2;
    upd(node*2,lo,md,l,r);
    upd(node*2+1,md+1,hi,l,r);
    seg[node]=seg[node*2]+seg[node*2+1];
}
long query(long node,long lo,long hi,long l,long r)
{
    if(lazy[node])
    {
        seg[node]=hi-lo+1;
        if(lo!=hi)
        {
            lazy[node*2]=1;
            lazy[node*2+1]=1;
        }
    }
    lazy[node]=0;
    if(lo>r||hi<l)return 0;
    if(lo>=l&&hi<=r)return seg[node];
    long md=(lo+hi)/2;
    return query(node*2,lo,md,l,r)+query(node*2+1,md+1,hi,l,r);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        memset(seg,0,sizeof(seg));
        memset(lazy,0,sizeof(lazy));
        cin>>n;
        for(long i=1;i<=n;i++)cin>>arr[i].c>>arr[i].t>>arr[i].s,arr[i].t--;
        sort(arr+1,arr+n+1,cmp);
        long ans=0;
        for(long i=1;i<=n;i++)
        {
            long lo=0,hi=arr[i].t,md;
            while(hi-lo>3)
            {
                md=(lo+hi)/2;
                x=arr[i].t-md+1-query(1,0,N,md,arr[i].t);
                if(x>arr[i].c)lo=md;
                else hi=md;
            }
            for(long j=lo;j<=hi;j++)
            {
                x=arr[i].t-j+1-query(1,0,N,j,arr[i].t);
                if(x<=arr[i].c)
                {
                    ans+=x*arr[i].s;
                    upd(1,0,N,j,arr[i].t);
                    ///cout<<j<<" "<<arr[i].t<<endl;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}