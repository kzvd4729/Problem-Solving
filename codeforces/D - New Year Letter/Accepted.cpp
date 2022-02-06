/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/11/2020 21:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 826 ms                                          memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/379/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int x;
string gen(int len,int ac,int f,int l)
{
  string s;
  if(ac*2>len)return "-1";
  if(ac*2==len)
  {
    if(f==1&&l==2)
    {
      for(int i=1;i<=ac;i++)
      {
        s.push_back('A');s.push_back('C');
      }
      return s;
    }
    return "-1";
  }
  if(ac*2+1==len)
  {
    for(int i=1;i<=ac;i++)
    {
      s.push_back('A');s.push_back('C');
    }
    if(f==0&&l==0)return "-1";
    if(f==0&&l==1)return "-1";
    if(f==0&&l==2)return "B"+s;
     if(f==1&&l==0)return s+"B";
    if(f==1&&l==1)return s+"A";
    if(f==1&&l==2)return s+"C";
     if(f==2&&l==0)return "-1";
    if(f==2&&l==1)return "-1";
    if(f==2&&l==2)return "C"+s;
   }
  for(int i=1;i<=ac;i++)
  {
    s.push_back('A');s.push_back('C');
  }
  while(s.size()<len-2)s.push_back('B');
  if(l==0)s.push_back('B');
  if(l==1)s.push_back('A');
  if(l==2)s.push_back('C');
   if(f==0)s="B"+s;
  if(f==1)s="A"+s;
  if(f==2)s="C"+s;
   return s;
}
bool cal(int k,int ac1,int f1,int l1,int ac2,int f2,int l2)
{
  for(int i=3;i<=k;i++)
  {
    int a=ac2,b=f2,c=l2;
    ac2=ac2+ac1;
    if(l1==1&&f2==2)ac2++;
    f2=f1;l2=l2;
     ac1=a,f1=b,l1=c;
     if(ac2>x)return false;
  }
  return ac2==x;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int k,n,m;cin>>k>>x>>n>>m;
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=m;j++)
    {
      for(int f1=0;f1<=2;f1++)
      {
        for(int l1=0;l1<=2;l1++)
        {
          for(int f2=0;f2<=2;f2++)
          {
            for(int l2=0;l2<=2;l2++)
            {
              string a=gen(n,i,f1,l1);
              string b=gen(m,j,f2,l2);
              if(a=="-1"||b=="-1")continue;
              if(cal(k,i,f1,l1,j,f2,l2))cout<<a<<endl<<b<<endl,exit(0);
            }
          }
        }
      }
    }
  }
  cout<<"Happy new year!"<<endl;
  return 0;
}