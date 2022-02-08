/****************************************************************************************
*  @author: kzvd4729                                         created: 25-07-2019 18:20:02                      
*  solution_verdict: Compilation Error                       language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/problems/DARTSEGM
****************************************************************************************/
struct point
{
  int x,y;
  point(){}
  point(int _x,int _y):x(_x), y(_y){}
  bool operator<(const point &p)const{return x<p.x||(x==p.x&&y<p.y);}
  point operator-(const point &p)const{return {x-p.x,y-p.y};}
  int operator^(const point &p)const{return x*p.y-y*p.x;}
};
point stck[N+2];int top=0;
void balance(void)
{
  while(top>=3)
  {
    //>=0 to omit straight line point;
    //for repetative point have to be >=0;
    if(((stck[top-1]-stck[top-2])^(stck[top]-stck[top-2]))>=0)
      stck[top-1]=stck[top],top--;
    else break;
  }
}
struct convexHull
{
  vector<point>up,dw;
  //counter-clockwise;
  void lowerConvex(void)
  {
    //points need to be sorted;
    int n=dw.size();
    for(int i=n-1;i>=0;i--)
      stck[++top]=dw[i],balance();
    dw.clear();
    while(top>0)
      dw.push_back(stck[top--]);
  }
  //clockwise
  void upperConvex(void)
  {
    //points need to be sorted;
    int n=up.size();
    for(int i=0;i<n;i++)
      stck[++top]=up[i],balance();
    up.clear();
    while(top>0)
      up.push_back(stck[top--]);
    reverse(up.begin(),up.end());
  }
  void build(vector<point>&v)
  {
    sort(v.begin(),v.end());
    up=v;dw=v;
    lowerConvex();upperConvex();
  }
  void mergeConvex(const convexHull &c)
  {
    vector<point>tmp;
    tmp.resize(dw.size()+c.dw.size());
    merge(dw.begin(),dw.end(),c.dw.begin(),c.dw.end(),tmp.begin());
    dw=tmp;lowerConvex();
    tmp.resize(up.size()+c.up.size());
    merge(up.begin(),up.end(),c.up.begin(),c.up.end(),tmp.begin());
    up=tmp;upperConvex();
  }
  vector<point>getHull(void)
  {
    vector<point>ret=dw;
    for(int i=up.size()-2;i>0;i--)
      ret.push_back(up[i]);
    return ret;
  }
};