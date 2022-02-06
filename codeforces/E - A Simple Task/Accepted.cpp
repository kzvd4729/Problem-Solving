/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/04/2018 14:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 702 ms                                          memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/558/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,sq=320;
int n,cnt[sq+2][26],lazy[sq+2],fr[26];
string s;
void too_lazy(int sg)
{
  if(lazy[sg]==0)return ;
  string tmp;
  if(lazy[sg]>0)
  {
    for(int i=0;i<26;i++)
    {
      int x=cnt[sg][i];
      while(x--)tmp.push_back(char(i+'a'));
    }
  }
  else
  {
    for(int i=25;i>=0;i--)
    {
      int x=cnt[sg][i];
      while(x--)tmp.push_back(char(i+'a'));
    }
  }
  int j=0;
  for(int i=sq*sg;i<min((int)s.size(),sq*(sg+1));i++)
    s[i]=tmp[j++];
  lazy[sg]=0;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;cin>>n>>q;cin>>s;
  for(int i=0;s[i];i++)
    cnt[i/sq][s[i]-'a']++;
  while(q--)
  {
    int lt,rt,ty;cin>>lt>>rt>>ty;lt--,rt--;if(!ty)ty=-1;
    int l=lt,r=rt;memset(fr,0,sizeof(fr));
    too_lazy(l/sq);too_lazy(r/sq);
//    for(int i=0;i<sq;i++)
//      too_lazy(i);
    //cout<<s<<endl;
    while(true)
    {
      if(l%sq==0)break;if(l>r)break;
      fr[s[l]-'a']++;cnt[l/sq][s[l]-'a']--;l++;
    }
    while(true)
    {
      if(r%sq==sq-1)break;if(r<l)break;
      fr[s[r]-'a']++;cnt[r/sq][s[r]-'a']--;r--;
    }
//        cout<<endl<<endl;
//    for(int i=0;i<26;i++)
//      cout<<i<<" "<<fr[i]<<endl;
    if(r>l)
    {
      for(int i=l/sq;i<=r/sq;i++)
      {
        for(int j=0;j<26;j++)
        {
          fr[j]+=cnt[i][j];
          cnt[i][j]=0;
        }
      }
    }
 //    cout<<endl<<endl;
//    for(int i=0;i<26;i++)
//      cout<<i<<" "<<fr[i]<<endl;
    l=lt,r=rt;int pt;if(ty==1)pt=0;else pt=25;
    while(true)
    {
      if(l%sq==0)break;if(l>r)break;
      while(!fr[pt])pt+=ty;
      //cout<<char(pt+'a')<<endl;
      s[l]=char(pt+'a');cnt[l/sq][pt]++;fr[pt]--;l++;
    }
    if(ty==1)pt=25;else pt=0;
    while(true)
    {
      if(r%sq==sq-1)break;if(r<l)break;
      while(!fr[pt])pt-=ty;
      //cout<<char(pt+'a')<<endl;
      s[r]=char(pt+'a');cnt[r/sq][pt]++;fr[pt]--;r--;
    }
    if(r>l)
    {
      for(int i=l/sq;i<=r/sq;i++)
      {
        //cout<<i<<endl;
        int sz=0,j;if(ty==1)j=0;else j=25;
        for( ;sz!=sq;j+=ty)
        {
          if(sz+fr[j]<=sq)
          {
            cnt[i][j]+=fr[j];
            sz+=fr[j];fr[j]=0;
          }
          else
          {
            int rq=sq-sz;
            cnt[i][j]+=rq;sz+=rq;
            fr[j]-=rq;
          }
        }
        lazy[i]=ty;
      }
    }
  }
  for(int i=0;i<sq;i++)
    too_lazy(i);
  cout<<s<<endl;
  return 0;
}