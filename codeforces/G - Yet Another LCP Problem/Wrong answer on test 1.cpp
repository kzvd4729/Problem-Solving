/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2019 02:33                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 98800 KB                             
*  problem: https://codeforces.com/contest/1073/problem/G
****************************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define last last2
 using namespace std;
 typedef long long ll;
 int dep[400005];
 namespace SAM {
 int ch[400005][26],tot=1,last=1;
int fa[400005],mx[400005];
int ed[400005];
 void add(char x,int id) {
  x-='a';
  int p=last,np=++tot;
  mx[np]=mx[p]+1;
  ed[id]=np;
  for(;p&&!ch[p][x];p=fa[p]) ch[p][x]=np;
  if (!p) fa[np]=1;
  else {
   int q=ch[p][x];
   if (mx[q]==mx[p]+1) fa[np]=q;
   else {
    int nq=++tot;
    memcpy(ch[nq],ch[q],sizeof(ch[nq]));
    mx[nq]=mx[p]+1;
    fa[nq]=fa[q];
    fa[q]=fa[np]=nq;
    for(;p&&ch[p][x]==q;p=fa[p]) ch[p][x]=nq;
   }
  }
  last=np;
}
 int dfn[400005],dfs_cnt;
int p[400005][20];
vector <int> son[400005];
 void dfs(int x) {
  dfn[x]=++dfs_cnt;
  for(int i=0;i<son[x].size();i++) {
   int u=son[x][i];
   dep[u]=dep[x]+1;p[u][0]=x;
   for(int j=1;j<20;j++) p[u][j]=p[p[u][j-1]][j-1];
   dfs(u);
  }
}
 int lca(int x,int y) {
  if (dep[x]<dep[y]) swap(x,y);
  int d=dep[x]-dep[y];
  for(int i=0;i<20;i++)
    if (d&(1<<i)) x=p[x][i];
  if (x==y) return x;
  for(int i=19;i>=0;i--)
    if (p[x][i]!=p[y][i]) {
     x=p[x][i];
     y=p[y][i];
 }
  return p[x][0];
}
 int q[400005],cnt[400005];
 void build(int n) {
  //for(int i=1;i<=tot;i++) cnt[mx[i]]++;
  //for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
  //for(int i=1;i<=tot;i++) q[cnt[mx[i]]--]=i;
  for(int i=tot;i>1;i--) {
   int x=q[i];
   son[fa[i]].push_back(i);
  }
  dep[1]=1;
  dfs(1);
}
 }
 int a[200005],b[200005];
 namespace VT {
 int st[400005],top;
int sz1[400005],sz2[400005];
int num[400005],now[400005],p[400005],cnt;
 bool cmp(int x,int y) {
  return SAM::dfn[x]<SAM::dfn[y];
}
 void addEdge(int x,int y) {
  p[y]=x;
  now[++cnt]=y;
}
 ll solve(int n,int m) {
  int tot=0;
  for(int i=1;i<=n;i++) {
   int x=SAM::ed[a[i]];
   num[++tot]=x;
   sz1[x]++;
  }
  for(int i=1;i<=m;i++) {
   int x=SAM::ed[b[i]];
   num[++tot]=x;
   sz2[x]++;
  }
  sort(num+1,num+tot+1,cmp);
  int top=0;
  st[++top]=1;cnt=0;
  for(int i=1;i<=tot;i++) {
    int x=num[i];
   if (x==st[top]) continue;
   int p=SAM::lca(x,st[top]);
   for(;;) {
    if (dep[p]<=dep[st[top-1]]) {
     addEdge(st[top-1],st[top]);
     top--;
    }
  else if (dep[p]<dep[st[top]]) {
   addEdge(p,st[top]);
   st[top]=p;
   break;
  }
  else break;
   }
 if (p!=st[top]) st[++top]=p;
 st[++top]=x;
  }
  for(;top;top--) addEdge(st[top-1],st[top]);
  ll ans=0;
  for(int i=1;i<=cnt;i++) {
   int x=now[i];
   ans+=(ll)sz1[x]*sz2[x]*(SAM::mx[x]-SAM::mx[p[x]]);
   sz1[p[x]]+=sz1[x];
   sz2[p[x]]+=sz2[x];
  }
  for(int i=1;i<=cnt;i++) {
   int x=now[i];
   p[x]=sz1[x]=sz2[x]=0;
  }
  return ans;
}
 }
 char str[200005];
 int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  scanf("%s",str+1);
  for(int i=n;i>0;i--) SAM::add(str[i],i);
  SAM::build(n);
  for(int i=1;i<=m;i++) {
   int x,y;
   scanf("%d%d",&x,&y);
   for(int j=1;j<=x;j++) scanf("%d",&a[j]);
   for(int j=1;j<=y;j++) scanf("%d",&b[j]);
   printf("**%lld\n",VT::solve(x,y));
  }
  return 0;
}