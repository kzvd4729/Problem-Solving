/****************************************************************************************
*  @author: kzvd4729                                         created: 24-02-2018 21:01:57                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.30 sec                                        memory_used: 20.3M                                
*  problem: https://www.codechef.com/LTIME57/problems/GAMENUMB
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,k,lt,rt,l,r,b,lo,hi,mid,x,tmp;
struct data
{
    long a,d;
}arr[100005];
bool cmp(data A,data B)
{
    return A.a>B.a;
}
long seg[400005];
void upd(long node,long lo,long hi,long id,long vl)
{
    if(lo==hi)
    {
        seg[node]=vl;
        return ;
    }
    long mid=(lo+hi)/2;
    if(id<=mid)upd(node*2,lo,mid,id,vl);
    else upd(node*2+1,mid+1,hi,id,vl);
    seg[node]=seg[node*2]+seg[node*2+1];
}
long query(long node,long lo,long hi,long lt,long rt)
{
    if(lo>rt||hi<lt)return 0;
    if(lo>=lt&&hi<=rt)return seg[node];
    long mid=(lo+hi)/2;
    return query(node*2,lo,mid,lt,rt)+query(node*2+1,mid+1,hi,lt,rt);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(long i=1;i<=n;i++)cin>>arr[i].a;
        for(long i=1;i<=n;i++)cin>>arr[i].d;
        sort(arr+1,arr+n+1,cmp);
        for(long i=1;i<=n;i++)upd(1,1,n,i,arr[i].d);
        lt=1;
        rt=n;
        for(long i=1;i<=k;i++)
        {
            cin>>b;
            if(i%2)
            {
                lo=lt;
                hi=rt;
                while((hi-lo)>3)
                {
                    mid=(lo+hi)/2;
                    tmp=query(1,1,n,lt,mid);
                    if(tmp<b)lo=mid;
                    else hi=mid;
                }
                for(long i=lo;i<=hi;i++)
                {
                    x=query(1,1,n,lt,i);
                    if(x>=b)
                    {
                        x-=b;
                        rt=i;
                        tmp=query(1,1,n,rt,rt)-x;
                        upd(1,1,n,rt,tmp);
                        break;
                    }
                }
            }
            else
            {
                lo=lt;
                hi=rt;
                while((hi-lo)>3)
                {
                    mid=(lo+hi)/2;
                    tmp=query(1,1,n,mid,rt);
                    if(tmp<b)hi=mid;
                    else lo=mid;
                }
                for(long i=hi;i>=lo;i--)
                {
                    x=query(1,1,n,i,rt);
                    if(x>=b)
                    {
                        x-=b;
                        lt=i;
                        tmp=query(1,1,n,lt,lt)-x;
                        upd(1,1,n,lt,tmp);
                        break;
                    }
                }
            }
        }
        long ans=0;
        for(long i=lt;i<=rt;i++)ans+=arr[i].a*query(1,1,n,i,i);
        cout<<ans<<endl;
    }
    return 0;
}