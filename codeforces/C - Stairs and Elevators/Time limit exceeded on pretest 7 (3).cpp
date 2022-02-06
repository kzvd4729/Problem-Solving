/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/29/2018 20:28                        
*  solution_verdict: Time limit exceeded on pretest 7        language: GNU C++17                               
*  run_time: 2000 ms                                         memory_used: 7000 KB                              
*  problem: https://codeforces.com/contest/967/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,cl,ce,v,q,a,b,c,d,print,x;
const int inf=1e9;
set<int>st,el;
set<int>::iterator it;
void way1(void)
{
  it=upper_bound(st.begin(),st.end(),b);
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
  for(int i=1;i<=cl;i++)
  {
    scanf("%d",&x);
    st.insert(x);
  }
  for(int i=1;i<=ce;i++)
  {
    scanf("%d",&x);
    el.insert(x);
  }
  st.insert(inf);
  st.insert(-inf);
  el.insert(inf);
  el.insert(-inf);
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