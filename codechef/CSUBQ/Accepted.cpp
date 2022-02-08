/****************************************************************************************
*  @author: kzvd4729                                         created: 09-11-2017 23:18:51                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.90 sec                                        memory_used: 198.8M                               
*  problem: https://www.codechef.com/NOV17/problems/CSUBQ
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long N,Q,L,R,ck,id,vl,ff;
struct segment
{
    long slo;
    long shi;
    long tlt;
    long trt;
    long flt;
    long frt;
    long ans;
    long ckr;
} seg[3000000];
void upd(long node,long lo,long hi,long idx,long val)
{
    if(idx>hi||idx<lo)return ;
    if(lo==hi)
    {
        if(val>=L&&val<=R)seg[node]= {lo,hi,lo,hi,0,0,1,1};
        else if(val>R) seg[node]= {lo,hi,0,0,lo,hi,0,1};
        else seg[node]= {lo,hi,0,0,0,0,0,1};
        return ;
    }
    long mid=(lo+hi)/2;
    upd(node*2,lo,mid,idx,val);
    upd(node*2+1,mid+1,hi,idx,val);
    seg[node].slo=seg[node*2].slo;
    seg[node].shi=seg[node*2+1].shi;
    if(seg[node*2].tlt)seg[node].tlt=seg[node*2].tlt;
    else seg[node].tlt=seg[node*2+1].tlt;
    if(seg[node*2+1].trt)seg[node].trt=seg[node*2+1].trt;
    else seg[node].trt=seg[node*2].trt;
    if(seg[node*2].flt)seg[node].flt=seg[node*2].flt;
    else seg[node].flt=seg[node*2+1].flt;
    if(seg[node*2+1].frt)seg[node].frt=seg[node*2+1].frt;
    else seg[node].frt=seg[node*2].frt;
    long x,y,xx,yy;
    if(seg[node*2].trt==0)x=0;
    else if(seg[node*2].frt==0)x=seg[node*2].trt-seg[node*2].slo+1;
    else
    {
        if(seg[node*2].trt<seg[node*2].frt)x=0;
        else x=seg[node*2].trt-seg[node*2].frt;
    }
    xx=seg[node*2].shi-max(seg[node*2].trt,max(seg[node*2].frt,seg[node*2].slo-1
        ));
    if(seg[node*2+1].tlt==0)y=0;
    else if(seg[node*2+1].flt==0)y=seg[node*2+1].shi-seg[node*2+1].tlt+1;
    else
    {
        if(seg[node*2+1].tlt>seg[node*2+1].flt)y=0;
        else y=seg[node*2+1].flt-seg[node*2+1].tlt;
    }
    if(seg[node*2+1].flt==0)yy=seg[node*2+1].shi-seg[node*2+1].slo+1;
    else yy=seg[node*2+1].flt-seg[node*2+1].slo;
    /*if(ff&&lo==1&&hi==2)
    {
        cout<<x<<" "<<xx<<" "<<y<<" "<<yy<<endl;
        cout<<seg[node*2+1].tlt<<" "<<seg[node*2+1].trt<<" "<<seg[node*2+1].shi
            <<" "<<seg[node*2+1].slo<<endl;
    }*/
    seg[node].ans=seg[node*2].ans+seg[node*2+1].ans+(x*yy)+(y*xx);
}
segment query(long node,long lo,long hi,long lt,long rt)
{
    if(lo>rt||hi<lt)return {0,0,0,0,0,0,0,0};
    if(lo>=lt&&hi<=rt)
    {
        seg[node].ckr=1;
        return seg[node];
    }
    long mid=(lo+hi)/2;
    segment p,p1,p2;
    p1=query(node*2,lo,mid,lt,rt);
    p2=query(node*2+1,mid+1,hi,lt,rt);
    if(p1.ckr==0&&p2.ckr==0)return {0,0,0,0,0,0,0,0};
    else if(p1.ckr&&p2.ckr==0)return p1;
    else if(p1.ckr==0&&p2.ckr)return p2;
    else
    {
        p.slo=p1.slo;
        p.shi=p2.shi;
        if(p1.tlt)p.tlt=p1.tlt;
        else p.tlt=p2.tlt;
        if(p2.trt)p.trt=p2.trt;
        else p.trt=p1.trt;
        if(p1.flt)p.flt=p1.flt;
        else p.flt=p2.flt;
        if(p2.frt)p.frt=p2.frt;
        else p.frt=p1.frt;
        long x,y,xx,yy;
        if(p1.trt==0)x=0;
        else if(p1.frt==0)x=p1.trt-p1.slo+1;
        else
        {
            if(p1.trt<p1.frt)x=0;
            else x=p1.trt-p1.frt;
        }
        xx=p1.shi-max(p1.trt,max(p1.frt,p1.slo-1));
        if(p2.tlt==0)y=0;
        else if(p2.flt==0)y=p2.shi-p2.tlt+1;
        else
        {
            if(p2.tlt>p2.flt)y=0;
            else y=p2.flt-p2.tlt;
        }
        if(p2.flt==0)yy=p2.shi-p2.slo+1;
        else yy=p2.flt-p2.slo;
        p.ans=p1.ans+p2.ans+x*yy+y*xx;
        p.ckr=1;
        return p;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>Q>>L>>R;
    for(long i=1; i<=N; i++)upd(1,1,N,i,0);
    /*for(long i=1;i<=10;i++)cout<<seg[i].ans;
    cout<<endl;*/
    while(Q--)
    {
        cin>>ck>>id>>vl;
        ff=1;
        if(ck==1)upd(1,1,N,id,vl);
        else
        {
            segment xx=query(1,1,N,id,vl);
            cout<<xx.ans<<endl;
        }
        /*cout<<endl;
        for(long i=1;i<=10;i++)
        {
            cout<<seg[i].slo<<" "<<seg[i].shi<<" "<<seg[i].ans<<endl;
        }
        cout<<endl;*/
    }
    return 0;
}