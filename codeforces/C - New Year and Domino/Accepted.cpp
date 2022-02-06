/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/29/2017 01:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1075 ms                                         memory_used: 4300 KB                              
*  problem: https://codeforces.com/contest/611/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long r,c,qm1[505][505],qm2[505][505],q,x1,x2,yy1,y2;
char mat[505][505];
long fx(long row,long col)
{
    long ans=0;
    for(long i=1;i<=row;i++)
    {
        ans+=qm1[i][col];
    }
    for(long i=1;i<=col;i++)
    {
        ans+=qm2[row][i];
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(long i=0;i<=501;i++)
    {
        for(long j=0;j<=501;j++)
        {
            mat[i][j]='#';
            qm1[i][j]=0;
            qm2[i][j]=0;
        }
    }
    cin>>r>>c;
    for(long i=1;i<=r;i++)
    {
        for(long j=1;j<=c;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(long i=1;i<=r;i++)
    {
        for(long j=1;j<=c;j++)
        {
            if(mat[i][j]=='.'&&mat[i][j-1]=='.')qm1[i][j]=qm1[i][j-1]+1;
            else qm1[i][j]=qm1[i][j-1];
        }
    }
     for(long i=1;i<=r;i++)
    {
        for(long j=1;j<=c;j++)
        {
            if(mat[i][j]=='.'&&mat[i-1][j]=='.')qm2[i][j]=qm2[i-1][j]+1;
            else qm2[i][j]=qm2[i-1][j];
        }
    }
    cin>>q;
    while(q--)
    {
        cin>>x1>>yy1>>x2>>y2;
        long sum=fx(x2,y2)-fx(x1-1,y2)-fx(x2,yy1-1)+fx(x1-1,yy1-1);
         for(long i=x1;i<=x2;i++)
        {
            if(mat[i][yy1]=='.'&&mat[i][yy1-1]=='.')sum--;
        }
        for(long i=yy1;i<=y2;i++)
        {
            if(mat[x1][i]=='.'&&mat[x1-1][i]=='.')sum--;
        }
        cout<<sum<<endl;
         /*cout<<fx(x2,y2)<<endl;
        cout<<fx(x1-1,y2)<<endl;
        cout<<fx(x2,yy1-1)<<endl;
        cout<<fx(x1-1,yy1-1)<<endl;*/
     }
    return 0;
}