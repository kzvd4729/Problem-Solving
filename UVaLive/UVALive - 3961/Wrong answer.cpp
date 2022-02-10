/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-19 19:24:42                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-3961
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int tr;
struct treap
{
  int lt,rt,dt,pri,sz,lz,mn,id,mnid;
}bst[N+2];
void cal(int node)
{
  bst[node].sz=bst[bst[node].lt].sz+bst[bst[node].rt].sz+1;
  bst[node].mn=bst[node].dt;
  if(bst[node].lt)bst[node].mn=min(bst[node].mn,bst[bst[node].lt].mn);
  if(bst[node].rt)bst[node].mn=min(bst[node].mn,bst[bst[node].rt].mn);

  bst[node].mnid=1e9;
  if(bst[node].mn==bst[node].dt)bst[node].mnid=bst[node].id;
  if(bst[node].lt&&bst[bst[node].lt].mn==bst[node].mn)
    bst[node].mnid=min(bst[node].mnid,bst[bst[node].lt].mnid);
  if(bst[node].rt&&bst[bst[node].rt].mn==bst[node].mn)
    bst[node].mnid=min(bst[node].mnid,bst[bst[node].rt].mnid);
}
void tooLazy(int node)
{
  if(!bst[node].lz)return ;
  swap(bst[node].lt,bst[node].rt);

  if(bst[node].lt)bst[bst[node].lt].lz^=1;
  if(bst[node].rt)bst[bst[node].rt].lz^=1;

  bst[node].lz=0;
}
pair<int,int>splitbySize(int node,int ss)
{
  tooLazy(node);
  if(!node)return {0,0};pair<int,int>p;
  if(bst[bst[node].lt].sz>=ss)
  {
    p=splitbySize(bst[node].lt,ss);
    bst[node].lt=p.second;cal(node);
    return {p.first,node};
  }
  else
  {
    p=splitbySize(bst[node].rt,ss-bst[bst[node].lt].sz-1);
    bst[node].rt=p.first;cal(node);
    return {node,p.second};
  }
}
int join(int lt,int rt)
{
  tooLazy(lt);tooLazy(rt);
  if(!lt)return rt;if(!rt)return lt;
  if(bst[lt].pri>=bst[rt].pri)
  {
    bst[lt].rt=join(bst[lt].rt,rt);
    cal(lt);return lt;
  }
  else
  {
    bst[rt].lt=join(lt,bst[rt].lt);
    cal(rt);return rt;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;while(cin>>n)
  {
    if(!n)break;tr=0;int root=0;vector<pair<int,int> >v;
    for(int i=1;i<=n;i++)bst[i]={0,0,0,0,0,0,0,0,0};
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;v.push_back({x,i});
      bst[++tr]={0,0,x,rand(),1,0,x,i,i};
      root=join(root,tr);
    }
    sort(v.begin(),v.end());vector<int>ans;
    for(int i=0;i<n;i++)
    {
      //cout<<bst[root].mn<<" *** "<<bst[root].mnid<<endl;
      int mn=v[i].first,id=v[i].second;//cout<<"**"<<bst[root].sz<<endl;
      int lo=1,hi=bst[root].sz,md;pair<int,int>p;
      while(hi-lo>2)
      {
        md=(lo+hi)/2;
        p=splitbySize(root,md);
        if(bst[p.first].mn==mn&&bst[p.first].mnid==id)hi=md;
        else lo=md;

        root=join(p.first,p.second);
      }
      for(md=lo;md<=hi;md++)
      {
        p=splitbySize(root,md);
        if(bst[p.first].mn==mn&&bst[p.first].mnid==id)break;

        root=join(p.first,p.second);
      }
      ans.push_back(i+bst[p.first].sz);
      bst[p.first].lz^=1;
      root=join(p.first,p.second);

      p=splitbySize(root,1);
      root=p.second;

      //cout<<"**"<<bst[root].mn<<endl;

    }
//
    for(int i=0;i<n;i++)
    {
      if(i)cout<<" ";
      cout<<ans[i];
    }
    cout<<"\n";
  }
  return 0;
}