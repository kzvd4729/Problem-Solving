/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/12/2018 14:45                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 62 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/990/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int n,a,b,mat[N+2][N+2];
 void print(void)
{
cout<<"YES"<<endl;
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
cout<<mat[i][j];    
}
cout<<endl;
}
}
 void case1(void)
{
if(n==2||n==3)cout<<"NO"<<endl,exit(0);
for(int i=1;i<n;i++)
{
mat[i][i+1]=1;
mat[i+1][i]=1;
}
print();
}
 void case2(void)
{
for(int i=1;i<=b-1;i++)
{
for(int j=1;j<=n;j++)
{
if(i!=j)mat[i][j]=1;
if(i!=j)mat[j][i]=1;
}
}
print();
}
 void case3(void)
{
for(int i=1;i<=n-a+1;i++)
{
for(int j=1;j<=n-a+1;j++)
{
if(i!=j)mat[i][j]=1;
if(i!=j)mat[j][i]=1;
}
}
print();        
}
    int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
 cin>>n>>a>>b;
if(a==1&&b==1)case1();
else if(a==1)case2();
else if(b==1)case3();
else cout<<"NO"<<endl;
return 0;
}