/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/29/2018 20:20                        
*  solution_verdict: Time limit exceeded on pretest 7        language: GNU C++11                               
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
  it=upper_bound(st.begin(),st.end(),b);
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
  it=upper_bound(el.begin(),el.end(),b);
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>cl>>ce>>v;
  while(cl--)
  {
    cin>>x;
    st.insert(x);
  }
  while(ce--)
  {
    cin>>x;
    el.insert(x);
  }
  st.insert(inf);
  st.insert(-inf);
  el.insert(inf);
  el.insert(-inf);
    cin>>q;
  while(q--)
  {
    cin>>a>>b>>c>>d;
     if(a==c)
    {
      cout<<abs(b-d)<<endl;
      continue;
    }
     print=inf;
    way1();///right stair;
    way2();///left stair;
    way3();///right elevator;
    way4();///left elevator
    cout<<print<<endl;
  }
  return 0;
}