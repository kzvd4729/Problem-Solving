/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-18 00:08:11                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 27                                         memory_used (MB): 2.1                             
*  problem: https://vjudge.net/problem/LightOJ-1285
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
int t,tc,n,vis[N+2];
vector<int>ans;
struct point
{
int x,y,id;
}arr[N+2];
stack<point>st;
 
bool cmp(point A,point B)
{
if(A.x!=B.x)return A.x<B.x;
else return A.y<B.y;
}
 
int cross(point a,point b,point c)
{
b.x-=a.x;
b.y-=a.y;
c.x-=a.x;
c.y-=a.y;
return b.x*c.y-c.x*b.y;    
}
 
void balance(void)
{
point a,b,c;
while(st.size()>=3)
{
c=st.top();
st.pop();
b=st.top();
st.pop();
a=st.top();
if(cross(a,b,c)>0)st.push(c);
else
{
st.push(b);
st.push(c);
break;
}          
}    
}
   
void upper(void)
{
for(int i=1;i<=n;i++)
{
st.push(arr[i]);
balance();  
}
while(st.size())
{
int tmp=st.top().id;
vis[tmp]=1;
ans.push_back(tmp);
st.pop();
}
reverse(ans.begin(),ans.end());    
}
 
int main()
{
cin>>t;
while(t--)
{
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>arr[i].x>>arr[i].y;
arr[i].id=i-1;
}
sort(arr+1,arr+n+1,cmp);
int f=0;
for(int i=3;i<=n;i++)
if(cross(arr[1],arr[2],arr[i]))f=1;
if(f==0)cout<<"Case "<<++tc<<":"<<endl<<"Impossible"<<endl;
else
{
ans.clear();
memset(vis,0,sizeof(vis));
upper();
for(int i=n;i>=1;i--)
{
if(vis[arr[i].id])continue;
ans.push_back(arr[i].id);
}
if(f)cout<<"Case "<<++tc<<":"<<endl;
for(int i=0;i<ans.size();i++)
{
if(i)cout<<" ";
cout<<ans[i];      
}
cout<<endl;
}
}
return 0;
}