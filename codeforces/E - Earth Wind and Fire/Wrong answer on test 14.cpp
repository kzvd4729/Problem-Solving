/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/14/2019 15:56                        
*  solution_verdict: Wrong answer on test 14                 language: GNU C++14                               
*  run_time: 1263 ms                                         memory_used: 26800 KB                             
*  problem: https://codeforces.com/contest/1148/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2];
void no(void){cout<<"NO"<<endl,exit(0);}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;set<pair<int,int> >st;vector<pair<pair<int,int>,int> >ans;
   for(int i=1;i<=n;i++)cin>>aa[i],st.insert({aa[i],i});
   for(int i=1;i<=n;i++)cin>>bb[i];
   sort(bb+1,bb+n+1);int a=1,b=n;
   while(true)
   {
      /*cout<<endl;
      for(auto x:st)
         cout<<x.first<<" "<<x.second<<endl;
      cout<<a<<" "<<b<<" "<<bb[a]<<" "<<bb[b]<<endl;
      cout<<endl;*/
      if(st.size()==0)break;
      pair<int,int>x=*st.begin(),y=*st.rbegin();
      if(st.size()==1)
      {
         if(x.first!=bb[a])no();
         break;
      }
      st.erase(x);st.erase(y);
      int c=bb[a]-x.first,d=y.first-bb[b];
      int m=min(c,d);if(m<0)no();
      ans.push_back({{x.second,y.second},m});
      if(x.first+m==bb[a])a++;
      else st.insert({x.first+m,x.second});
      if(y.first-m==bb[b])b--;
      else st.insert({y.first-m,y.second});
   }
   cout<<"YES"<<endl;cout<<ans.size()<<endl;
   for(auto x:ans)
      cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
   return 0;
}