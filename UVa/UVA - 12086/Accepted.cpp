/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-02-08 23:18:50                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 380                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12086
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,cs=0,seg[800000],x;
string s;
void upd(long node,long lo,long hi,long id,long vl)
{
    if(lo>id||hi<id)return ;
    if(lo==hi)
    {
        seg[node]=vl;
        return ;
    }
    long mid=(lo+hi)/2;
    upd(node*2,lo,mid,id,vl);
    upd(node*2+1,mid+1,hi,id,vl);
    seg[node]=seg[node*2]+seg[node*2+1];
}
long query(long node,long lo,long hi,long l,long r)
{
    if(lo>r||hi<l)return 0;
    if(lo>=l&&hi<=r)return seg[node];
    long mid=(lo+hi)/2;
    long p1=query(node*2,lo,mid,l,r);
    long p2=query(node*2+1,mid+1,hi,l,r);
    return p1+p2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n)
    {
        if(n==0)break;
        memset(seg,0,sizeof(seg));
        cs++;
        if(cs>1)cout<<endl;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            upd(1,1,n,i,x);
        }
        cout<<"Case "<<cs<<":"<<endl;
        while(cin>>s)
        {
            if(s=="END")break;
            if(s=="M")
            {
                long l,r;
                cin>>l>>r;
                cout<<query(1,1,n,l,r)<<endl;
            }
            else
            {
                long id,vl;
                cin>>id>>vl;
                upd(1,1,n,id,vl);
            }
        }
    }
    return 0;
}