/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 585 ms                                          memory_used: 45 MB                                
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6+2;
//od[i] is largest palindromic substring centered at i;
vector<int>od;
//ev[i] is largest palindromic substring centered at i and i+1;
vector<int>ev;
void manachar(string s)
{
  string x="@#";
  for(auto c:s)x.push_back(c),x.push_back('#');
  x.push_back('$');s=x;
  int n=s.size();
  int l=0,r=0;vector<int>pp(n);
  for(int i=0;i<n;i++)
  {
    pp[i]=min(r-i,pp[l+r-i]);
    while(s[i-pp[i]]==s[i+pp[i]])pp[i]++;
    if(i+pp[i]>r)l=i-pp[i],r=i+pp[i];
  }
  for(int i=2;i<n-1;i+=2)od.push_back(pp[i]-1);
  for(int i=3;i<n-1;i+=2)ev.push_back(pp[i]-1);
}
int bit[N+2];
void upd(int x,int vl)
{
  x++;
  for( ;x<=N;x+=x&-x)bit[x]+=vl;
}
int get(int x)
{
  x++;int ret=0;
  for( ;x>0;x-=x&-x)ret+=bit[x];
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;manachar(s);long ans=0;int n=s.size();
  priority_queue<pair<int,int> >pq;
  for(int i=0;i<s.size()-1;i++)
  {
    while(pq.size())
    {
      pair<int,int>p=pq.top();
      if(-p.first<i)
      {
        upd(p.second,-1);pq.pop();
      }
      else break;
    }
    ev[i]/=2;
    int l=i-ev[i],r=i-1;
    //ans+=get(rot[r],0,n,i+1);
    ans+=get(r);
    //if(l)ans-=get(rot[l-1],0,n,i+1);
    if(l)ans-=get(l-1);
    //rot[i]=++nw;upd(rot[i],rot[i-1],0,n,i+1+ev[i]);
    pq.push({-(i+ev[i]),i});upd(i,1);
  }
  cout<<ans<<endl;
  return 0;
}