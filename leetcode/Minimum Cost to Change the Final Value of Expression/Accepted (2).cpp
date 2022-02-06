/****************************************************************************************
*  @author: kzvd4729                                         created: 06/12/2021 21:32                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 92 ms                                           memory_used: 19.2 MB                              
*  problem: https://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression
****************************************************************************************/
const int N=1e6,inf=1e9,mod=1e9+7;
const int lp=10,rp=9,sa=8,so=7;
class Solution 
{
public:
  pair<int,int>merge(pair<int,int>a,pair<int,int>b,pair<int,int>c)
  {
    int zr=inf,on=inf;
    zr=min(zr,a.first+c.first+(b.first==so));
    zr=min(zr,a.first+c.second+(b.first==so));
    zr=min(zr,a.second+c.first+(b.first==so));
    on=min(on,a.second+c.second+(b.first==so));
    zr=min(zr,a.first+c.first+(b.first==sa));
    on=min(on,a.first+c.second+(b.first==sa));
    on=min(on,a.second+c.first+(b.first==sa));
    on=min(on,a.second+c.second+(b.first==sa));
    return {zr,on};
  }
  int minOperationsToFlip(string s) 
  {
    stack<pair<int,int> >st;
    s="("+s+")";
    for(auto x:s)
    {
      if(x=='(')st.push({lp,0});
      else if(x=='&')st.push({sa,0});
      else if(x=='|')st.push({so,0});
      else if(x=='0' || x=='1')
      {
        pair<int,int>p;
        if(x=='0')p={0,1};else p={1,0};
        if((int)st.size() && ((st.top().first==sa) || (st.top().first==so)))
        {
          pair<int,int>sgn=st.top();st.pop();
          pair<int,int>an=st.top();st.pop();
          pair<int,int>now=merge(an,sgn,p);
          st.push(now);
        }
        else st.push(p);
      }
      else
      {
        pair<int,int>p=st.top();st.pop();
        st.pop();
        if((int)st.size() && ((st.top().first==sa) || (st.top().first==so)))
        {
          pair<int,int>sgn=st.top();st.pop();
          pair<int,int>an=st.top();st.pop();
          pair<int,int>now=merge(an,sgn,p);
          st.push(now);
        }
        else st.push(p);
      }
    }
    pair<int,int>p=st.top();
    //cout<<p.first<<" "<<p.second<<endl;
    return max(p.first,p.second);
  }
};