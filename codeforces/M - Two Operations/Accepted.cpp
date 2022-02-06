/****************************************************************************************
*  @author: kzvd4729#                                        created: Oct/08/2019 15:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 3500 KB                              
*  problem: https://codeforces.com/gym/102263/problem/M
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
 #define SP(x) cerr<<#x<<" = "<<x<<endl
#define DP(x) cerr<<#x<<" = "<<x.first<<" "<<x.second<<endl
#define F cerr<<"flag"<<endl
template<typename T>//container
void _p(T v)
{
  cerr<<"( ";
  for(auto x:v)cerr<<x<<" ";
  cerr<<")"<<endl;
}
 const int N=1e6;
int cnt[30];
int main()
{
  //freopen("inp.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
   string s;cin>>s;multiset<char>st;
  for(auto x:s)st.insert(x);
   while(st.size()>1)
  {
    char a=*st.begin();if(a=='z')break;
    st.erase(st.find(a));
    if(*st.begin()==a)
    {
      st.erase(st.find(a));
      st.insert((char)(a+1));
    }
    else cnt[a-'a']++;
  }
  while(st.size())
  {
    char a=*st.begin();st.erase(st.find(a));
    cnt[a-'a']++;
  }
  for(int i=25;i>=0;i--)
    while(cnt[i]--)cout<<(char)(i+'a');
  cout<<endl;
  return 0;
}