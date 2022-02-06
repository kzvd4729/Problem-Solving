/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/29/2018 20:34                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 202 ms                                          memory_used: 4900 KB                              
*  problem: https://codeforces.com/contest/967/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,cl,ce,v,q,a,b,c,d,print,x;
const int inf=1e9;
vector<int>st,el;
vector<int>::iterator it;
void way1(void)
{
  it=upper_bound(st.begin(),st.end(),b);
  //it=st.upper_bound(b);
  int nn=*it,here=0;
  if(nn==inf||nn==-inf)return ;
  here=abs(nn-b);
  here+=abs(a-c);
  here+=abs(nn-d);
  print=min(print,here);
}
void way2(void)
{
  it--;
  int nn=*it,here=0;
  if(nn==inf||nn==-inf)return ;
  here=abs(nn-b);
  here+=abs(a-c);
  here+=abs(nn-d);
  print=min(print,here);
}
void way3(void)
{
  it=upper_bound(el.begin(),el.end(),b);
  //it=el.upper_bound(b);
  int nn=*it,here=0;
  if(nn==inf||nn==-inf)return ;
  here=abs(nn-b);
  here+=((abs(a-c)+v-1)/v);
  here+=abs(nn-d);
  print=min(print,here);
}
void way4(void)
{
  it--;
  int nn=*it,here=0;
  if(nn==inf||nn==-inf)return ;
  here=abs(nn-b);
  here+=((abs(a-c)+v-1)/v);
  here+=abs(nn-d);
  print=min(print,here);
 }
int main()
{
  scanf("%d%d%d%d%d",&n,&m,&cl,&ce,&v);
  st.push_back(-inf);
  for(int i=1;i<=cl;i++)
  {
    scanf("%d",&x);
    st.push_back(x);
  }
  st.push_back(inf);
  el.push_back(-inf);
  for(int i=1;i<=ce;i++)
  {
    scanf("%d",&x);
    el.push_back(x);
  }
  el.push_back(inf);
   scanf("%d",&q);
  while(q--)
  {
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a==c)
    {
      printf("%d\n",abs(b-d));
      continue;
    }
    print=inf;
    way1();///right stair;
    way2();///left stair;
    way3();///right elevator;
    way4();///left elevator
    printf("%d\n",print);
  }
  return 0;
}