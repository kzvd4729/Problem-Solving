/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/09/2018 01:33                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++17                               
*  run_time: 30 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/110/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long R=2e9;
long l1,r1,l2,r2,tt,ok,lt,rt,k;
set<long>st;
 void gen(long num)
{
if(num>R)return ;
if(num)st.insert(num);
gen(num*10+4);
gen(num*10+7);
}
 void one(vector<long>v)
{
for(int i=l1;i<=r1; )
{
int id=lower_bound(v.begin(),v.end(),i)-v.begin();
lt=min(v[id],r1)-i+1;
i=v[id]+1;
id+=k-1;
if(id>v.size()-2)return ;
rt=min(v[id+1]-1LL,r2)-max(l2,v[id])+1;
if(rt<=0)return;
ok+=(lt*rt);
}
}
    void two(vector<long>v)
{
for(int i=l2;i<=r2; )
{
int id=lower_bound(v.begin(),v.end(),i)-v.begin();
lt=min(r2,v[id])-i+1;
i=v[id]+1;
id+=k-1;
if(id>v.size()-2)return ;
rt=min(v[id+1]-1LL,r1)-max(l1,v[id])+1;
if(rt<=0)return ;
ok+=(lt*rt);
}
}
 int main()
{
gen(0);
cin>>l1>>r1>>l2>>r2>>k;
vector<long>v(st.begin(),st.end());
 tt=(r1-l1+1)*(r2-l2+1);
 one(v);
two(v);
 double ans=(ok*1.00)/(tt*1.00);
cout<<setprecision(12)<<fixed<<ans<<endl;
    return 0;
}