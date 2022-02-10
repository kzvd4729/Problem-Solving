/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-06 14:13:44                      
*  solution_verdict: Compile Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-2187
****************************************************************************************/
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
const int N=5e4;
int n;
struct point
{
  int x,y;
}pt[N+2];
stack<point>st;
vector<point>hull;
bool cmp(point a,point b)
{
  if(a.x!=b.x)return a.x<b.x;
  else return a.y<b.y;
}
long long area(point a,point b,point c)
{
  b.x-=a.x;b.y-=a.y;
  c.x-=a.x;c.y-=a.y;
  return b.x*c.y-c.x*b.y;
}
long long _area(const point &a, const point &b, const point &c)
{
    return abs((b.x - a.x) *1LL* (c.y - a.y) - (b.y - a.y)*1LL * (c.x - a.x));
}
void balance(void)
{
  while(st.size()>=3)
  {
    point c=st.top();st.pop();
    point b=st.top();st.pop();
    point a=st.top();
    if(area(a,b,c)<=0)st.push(c);
    else
    {
      st.push(b);st.push(c);
      break;
    }
  }
}
void upper(void)
{
  for(int i=n;i>=1;i--)
  {
    st.push(pt[i]);
    balance();
  }
  while(st.size())
    hull.push_back(st.top()),st.pop();
}
void lower(void)
{
  for(int i=1;i<=n;i++)
  {
    st.push(pt[i]);
    balance();
  }
  st.pop();
  while(st.size())
    hull.push_back(st.top()),st.pop();
  hull.pop_back();
}
long long dist(point a,point b)
{
  long long t1=(a.x-b.x)*(a.x-b.x);
  long long t2=(a.y-b.y)*(a.y-b.y);
  return t1+t2;
}
long long rotating_calipars(void)
{
    vector<point> h = hull;
    int m = h.size();
    if (m == 1)
        return 0;
    if (m == 2)
        return dist(h[0], h[1]);
    int k = 1;
    while (_area(h[m - 1], h[0], h[(k + 1) % m]) > _area(h[m - 1], h[0], h[k]))
        ++k;
    long long res = 0;
    for (int i = 0, j = k; i <= k && j < m; i++) {
        res = max(res, dist(h[i], h[j]));
        while (j < m && _area(h[i], h[(i + 1) % m], h[(j + 1) % m]) > _area(h[i], h[(i + 1) % m], h[j])) {
            res = max(res, dist(h[i], h[(j + 1) % m]));
            ++j;
        }
    }
    return res;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>pt[i].x>>pt[i].y;
  sort(pt+1,pt+n+1,cmp);
  upper();lower();
//  for(int i=0;i<hull.size();i++)
//    cout<<hull[i].x<<" "<<hull[i].y<<endl;

  cout<<rotating_calipars()<<endl;


  return 0;
}