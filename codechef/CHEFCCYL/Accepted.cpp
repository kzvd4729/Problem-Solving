/****************************************************************************************
*  @author: kzvd4729                                         created: 08-10-2017 13:41:49                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.90 sec                                        memory_used: 28M                                  
*  problem: https://www.codechef.com/OCT17/problems/CHEFCCYL
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,q,ecsp[100005],qm[100005];
vector<long>vv[100005];
struct data
{
    long own;
    long next;
    long cost;
} arr[100005];
void mem(void)
{
    for(long i=0; i<=100000; i++)
    {
        vv[i].clear();
        vv[i].push_back(0);
        vv[i].push_back(0);
    }
}
long clock_wise(long v1,long c1,long v2,long c2)
{
    long u,ownd,nexd,tmp;
    u=arr[c1].own;
    if(u>v1)swap(u,v1);
    ownd=min(vv[c1][v1]-vv[c1][u],vv[c1][vv[c1].size()-1]-vv[c1][v1]+vv[c1][u]);
    if(c2==1)u=arr[n].next;
    else u=arr[c2-1].next;
    if(u>v2)swap(u,v2);
    nexd=min(vv[c2][v2]-vv[c2][u],vv[c2][vv[c2].size()-1]-vv[c2][v2]+vv[c2][u]);
    tmp=c2-1;
    if(tmp==0)tmp=n;
    return qm[tmp]-qm[c1]+ownd+nexd+arr[tmp].cost;
}
long anti_clock_wise(long v1,long c1,long v2,long c2)
{
    long u,ownd,nexd,tmp;
    if(c1==1)u=arr[n].next;
    else u=arr[c1-1].next;
    if(u>v1)swap(u,v1);
    ownd=min(vv[c1][v1]-vv[c1][u],vv[c1][vv[c1].size()-1]-vv[c1][v1]+vv[c1][u]);
    u=arr[c2].own;
    if(u>v2)swap(u,v2);
    nexd=min(vv[c2][v2]-vv[c2][u],vv[c2][vv[c2].size()-1]-vv[c2][v2]+vv[c2][u]);
    if(c1==1)
    {
        return qm[n]-qm[c2]+nexd+arr[n].cost+ownd;
    }
    else
    {
        return qm[n]-qm[c2]+nexd+arr[n].cost+qm[c1-1]+ownd+arr[c1-1].cost;
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
        cin>>n>>q;
        mem();
        for(long i=1; i<=n; i++)
        {
            long x,c,s;
            cin>>x;
            while(x--)
            {
                cin>>c;
                s=vv[i].size()-1;
                vv[i].push_back(vv[i][s]+c);
            }
        }
        for(long i=1; i<=n; i++)
        {
            cin>>arr[i].own>>arr[i].next>>arr[i].cost;
        }
        for(long i=1; i<=n; i++)
        {
            long u,v;
            u=arr[i].own;
            if(i==1)v=arr[n].next;
            else v=arr[i-1].next;
            if(u>v)swap(u,v);
            ecsp[i]=min(vv[i][v]-vv[i][u],vv[i][vv[i].size()-1]-vv[i][v]
                +vv[i][u]);
        }
        qm[1]=ecsp[1];
        for(long i=2; i<=n; i++)
        {
            qm[i]=qm[i-1]+arr[i-1].cost+ecsp[i];
        }
        while(q--)
        {
            long v1,c1,v2,c2;
            cin>>v1>>c1>>v2>>c2;
            if(c1>c2)
            {
                swap(c1,c2);
                swap(v1,v2);
            }
            if(c1==c2)
            {
                if(v1>v2)swap(v1,v2);
                cout<<min(vv[c1][v2]-vv[c1][v1],vv[c1][vv[c1].size()-1]
                    -vv[c1][v2]+vv[c1][v1])<<endl;
            }
            else cout<<min(clock_wise(v1,c1,v2,c2),anti_clock_wise(v1,c1,v2,c2
                ))<<endl;
        }
    }
    return 0;
}