/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/09/2020 19:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2027 ms                                         memory_used: 81300 KB                             
*  problem: https://codeforces.com/contest/628/problem/E
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=3e3;
string s[N+2];int r[N+2][N+2],l[N+2][N+2];
int bit[N+2];
void add(int x,int vl)
{
  for( ;x>0;x-=x&-x)bit[x]+=vl;
}
int get(int x)
{
  int ret=0;
  for( ;x<=N;x+=x&-x)ret+=bit[x];
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>s[i];s[i]="."+s[i];
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=m;j>=1;j--)
    {
      if(s[i][j]=='.')r[i][j]=0;
      else r[i][j]=1+r[i][j+1];
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(s[i][j]=='.')l[i][j]=0;
      else l[i][j]=1+l[i][j-1];
    }
  }
  long ans=0;set<pair<int,int> >st;
  for(int i=1;i<=n;i++)
  {
    int nm=0;
    for(int j=1;j<=min(i,m);j++)
    {
      int rw=i-j+1,cl=j;nm++;
       //cout<<rw<<" "<<cl<<endl;
       if(s[rw][cl]=='.')
      {
        for(auto x:st)add(x.second,-1);
        st.clear();
      }
      else
      {
        ans++;
        ans+=get(max(1,nm-l[rw][cl]+1));
        add(nm,1);
        st.insert({nm+r[rw][cl]-1,nm});
         auto it=st.lower_bound(make_pair(nm,-1));
        vector<pair<int,int> >bf;
        while(it!=st.end())
        {
          if(it->first>nm)break;
          add(it->second,-1);bf.push_back(*it);
          it++;
        }
        for(auto x:bf)st.erase(x);
      }
    }
    for(auto x:st)add(x.second,-1);
    st.clear();
  }
  for(int i=2;i<=m;i++)
  {
    int nm=0;
    for(int j=i;j<=min(m,i+n-1);j++)
    {
      int rw=n-(j-i),cl=j;nm++;
      if(s[rw][cl]=='.')
      {
        for(auto x:st)add(x.second,-1);
        st.clear();
      }
      else
      {
        ans++;
        ans+=get(max(1,nm-l[rw][cl]+1));
        add(nm,1);
        st.insert({nm+r[rw][cl]-1,nm});
         auto it=st.lower_bound(make_pair(nm,-1));
        vector<pair<int,int> >bf;
        while(it!=st.end())
        {
          if(it->first>nm)break;
          add(it->second,-1);bf.push_back(*it);
          it++;
        }
        for(auto x:bf)st.erase(x);
      }
    }
    for(auto x:st)add(x.second,-1);
    st.clear();
  }
  cout<<ans<<endl;
  return 0;
}