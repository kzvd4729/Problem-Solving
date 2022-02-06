/****************************************************************************************
*  @author: JU_AAA: prdx9_abir, aniks2645, kzvd4729          created: Sep/16/2017 01:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 900 KB                               
*  problem: https://codeforces.com/gym/100819/problem/U
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long w,h,b;
long dr[]= {0,1,1,1,0,-1,-1,-1};
long dc[]= {1,1,0,-1,-1,-1,0,1};
struct fraction
{
    long up;
    long dw;
} mt[102][102],tmp[102][102];
map<pair<long,long>,long>mp;
fraction add(fraction a,fraction b)
{
    fraction x;
    x.dw=a.dw*b.dw;
    x.up=a.up*b.dw+b.up*a.dw;
    return x;
}
fraction calculate(long row,long col)
{
    fraction sum=mt[row][col];
    for(long i=0; i<8; i++)
    {
        long r,c;
        r=row+dr[i];
        c=col+dc[i];
        if(r>h)r=1;
        if(r<1)r=h;
        if(c>w)c=1;
        if(c<1)c=w;
        sum=add(sum,mt[r][c]);
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>w>>h>>b;
    for(long i=1; i<=h; i++)
    {
        for(long j=1; j<=w; j++)
        {
            long ddd;
            cin>>ddd;
            tmp[i][j].up=ddd;
            tmp[i][j].dw=1;
        }
    }
    while(b--)
    {
        for(long i=1; i<=h; i++)
        {
            for(long j=1; j<=w; j++)
            {
                mt[i][j]=tmp[i][j];
                mt[i][j].up*=9;
            }
        }
        for(long i=1; i<=h; i++)
        {
            for(long j=1; j<=w; j++)
            {
                tmp[i][j]=calculate(i,j);
                long u=tmp[i][j].up;
                long v=tmp[i][j].dw;
                while(true)
                {
                    long gc=__gcd(u,v);
                    if(gc==1)break;
                    u=u/gc;
                    v=v/gc;
                }
                tmp[i][j]={u,v};
            }
        }
    }
     /*for(long i=1; i<=h; i++)
    {
        for(long j=1; j<=w; j++)
        {
            cout<<tmp[i][j].up<<"/"<<tmp[i][j].dw<<" ";
        }
        cout<<endl;
    }*/
     ///mp[ {0,1}]=1;
    ///mp[ {1,1}]=1;
    long ans=0;
    for(long i=1; i<=h; i++)
    {
        for(long j=1; j<=w; j++)
        {
            if(mp[ {tmp[i][j].up,tmp[i][j].dw}]==0)
            {
                ans++;
                mp[ {tmp[i][j].up,tmp[i][j].dw}]=1;
            }
         }
    }
    cout<<ans<<endl;
    return 0;
}