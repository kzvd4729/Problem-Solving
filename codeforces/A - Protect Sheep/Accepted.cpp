/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/10/2018 21:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/948/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long r,c,f;
char mat[505][505];
string s;
long dr[]={0,0,1,-1};
long dc[]={1,-1,0,0};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        cin>>r>>c;
    for(long i=1;i<=r;i++)
    {
      cin>>s;
      for(long j=1;j<=c;j++)
      {
        mat[i][j]=s[j-1];
      }
    }
    for(long i=1;i<=r;i++)
    {
      for(long j=1;j<=c;j++)
      {
        if(mat[i][j]=='S')
        {
          for(long k=0;k<4;k++)
          {
            long ii=i+dr[k];
            long jj=j+dc[k];
            if(ii<1||ii>r||jj<1||jj>c)continue;
            if(mat[ii][jj]=='S')continue;
            if(mat[ii][jj]=='W')f=1;
            mat[ii][jj]='D';
          }
        }
      }
    }
    if(f)cout<<"No"<<endl;
    else
    {
      cout<<"Yes"<<endl;
      for(long i=1;i<=r;i++)
      {
        for(long j=1;j<=c;j++)
        {
          cout<<mat[i][j];
        }
        cout<<endl;
      }
    }
    return 0;
}