/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-13 15:34:07                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 40                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10635
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define inf 999999;
int n,p,q,ip,iq,pp[62505],qq[62505],arr[62505];
int k,tc=0;
void input(void)
{
    cin>>n>>p>>q;
    int i;
    memset(pp,-1,sizeof(pp));
    for(i=0; i<=p; i++)
    {
        cin>>ip;
        pp[ip]=i;

    }
    k=-1;
    for(i=0; i<=q; i++)
    {
        cin>>iq;
        if(pp[iq]!=-1)
        {
            arr[++k]=pp[iq];
        }
    }
}
int lis(void)
{
    int t[62505];
    int lo,mid,hi,l;
    t[0]=-inf;
    for(int i=1; i<62505; i++)
    {
        t[i]=inf;
    }
    l=0;
    for(int i=0; i<=k; i++)
    {
        lo=0;
        hi=l;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            if(arr[i]>t[mid])
            {
                lo=mid+1;
            }
            else hi=mid-1;
        }
        t[lo]=arr[i];
        if(lo>l)l=lo;
    }
    return l;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        input();
        cout<<"Case "<<++tc<<": "<<lis()<<endl;
    }
    return 0;
}