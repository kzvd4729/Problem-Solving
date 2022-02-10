/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: 28.57 points                            language: C++                                     
*  run_time: 94 ms                                           memory_used: 5492 KB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int h,w,x,y,mat[1010][1010],ans[1010][1010],tmp[1010][1010];
int main()
{
cin>>h>>w>>x>>y;
for(int i=1;i<=h+x;i++)
{
for(int j=1;j<=w+y;j++)
{
cin>>mat[i][j];
}
}
for(int i=1;i<=h;i++)
{
if(i<=x)
{
for(int j=1;j<=w;j++)ans[i][j]=mat[i][j];
for(int j=1;j<=w;j++)tmp[i+x][j+y]=mat[i][j];
}
else
{
for(int j=1;j<=w;j++)ans[i][j]=mat[i][j]-tmp[i][j];
}
}
for(int i=1;i<=h;i++)
{
for(int j=1;j<=w;j++)cout<<ans[i][j]<<" ";
cout<<endl;
}
return 0;
}