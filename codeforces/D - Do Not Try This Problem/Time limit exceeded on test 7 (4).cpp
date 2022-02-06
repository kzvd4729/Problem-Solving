/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/16/2019 15:59                        
*  solution_verdict: Time limit exceeded on test 7           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 4600 KB                              
*  problem: https://codeforces.com/gym/102307/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,sq=320;
int vis[N+2],cnt[sq+2];
set<vector<int> >st[sq+2];
void upd(int l,int r,int a,int c)
{
  for(int i=l/sq;i<=r/sq;i++)
  {
    if(st[i].find({l,a,c})!=st[i].end()||cnt[i]==0)
    {
      l=l+(((i+1)*sq-l+a-1)/a)*a;continue;
    }
    st[i].insert({l,a,c});
    while(l<(i+1)*sq)
      if(!vis[l])vis[l]=c,l+=a,cnt[l/sq]--;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;
  int n=s.size()-1;
  //cout<<n<<endl;
   int q;cin>>q;vector<vector<int> >qr;
  while(q--)
  {
    int i,a,k,c;char ch;cin>>i>>a>>k>>ch;c=(int)ch;
    int lt=i,rt=i+k*a;lt--,rt--;
    vector<int>v={lt,rt,a,c};
    qr.push_back(v);
  }
  for(int i=0;i<=sq;i++)cnt[i]=sq;
  while(qr.size())
  {
    vector<int>v=qr.back();qr.pop_back();
    int l=v[0],r=v[1],a=v[2],c=v[3];
    //cout<<l<<" --> "<<r<<endl;
    if(r-l<700||a>100)
    {
      for(int i=l;i<=r;i+=a)
        if(!vis[i])vis[i]=c,cnt[i/sq]--;
      continue;
    }
    int nx=((l+sq-1)/sq)*sq;
    while(l<nx)
    {
      if(!vis[l])vis[l]=c,cnt[l/sq]--;
      l+=a;
    }
    if(r%sq==sq-1)nx=r;
    else nx=r-r%sq-1;
    while(r>nx)
    {
      if(!vis[r])vis[r]=c,cnt[r/sq]--;
      r-=a;
    }
    upd(l,r,a,c);
  }
  for(int i=0;i<=n;i++)
  {
    if(vis[i])cout<<(char)vis[i];
    else cout<<s[i];
  }
  cout<<endl;
  return 0;
}