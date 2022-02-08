/****************************************************************************************
*  @author: kzvd4729                                         created: 09-10-2018 23:50:45                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.14 sec                                        memory_used: 20.5M                                
*  problem: https://www.codechef.com/OCT18A/problems/CPCOMP
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int fr[N+2];
int main()
{
  //ifstream cin("out.txt");
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;unordered_set<int>st;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;fr[x]++;
    st.insert(x);
  }
  int ans=0;
  while(st.size())
  {
    int bg=*st.begin();
    vector<int>er;er.push_back(bg);
    ans++;int cnt=0;
    while(er.size())
    {
      for(auto x:er)st.erase(x);
      vector<int>tmp;cnt++;
      for(auto z:st)
      {
        for(auto x:er)
        {
          if(__gcd(x,z)==1)
          {
            tmp.push_back(z);break;
          }
        }
      }
      er.clear();er=tmp;
    }
    if(cnt<=1)
    {
      ans+=fr[bg]-1;
      for(auto x:st)
        ans+=fr[x];
      break;
    }
    //cout<<st.size()<<endl;
  }
  cout<<ans<<endl;
  return 0;
}