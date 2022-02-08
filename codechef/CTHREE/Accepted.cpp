/****************************************************************************************
*  @author: kzvd4729                                         created: 18-02-2018 22:20:45                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.50 sec                                        memory_used: 22.7M                                
*  problem: https://www.codechef.com/COOK91/problems/CTHREE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,a,b,c,lim,lm,nn,ans,t;
struct data
{
    long a,b,c;
};
vector<data>v;
set<pair<long,pair<long,long> > >st;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        v.clear();
        st.clear();
        cin>>n>>a>>b>>c;
        lim=sqrt(n);
        for(long i=1;i<=lim;i++)
        {
            if(n%i)continue;
            nn=n/i;
            lm=sqrt(nn);
            for(long j=1;j<=lm;j++)
            {
                if(nn%j)continue;
                v.push_back({i,j,nn/j});
            }
        }
        for(auto x:v)
        {
            if(x.a<=a&&x.b<=b&&x.c<=c)st.insert({x.a,{x.b,x.c}});
            if(x.a<=a&&x.c<=b&&x.b<=c)st.insert({x.a,{x.c,x.b}});
            if(x.b<=a&&x.a<=b&&x.c<=c)st.insert({x.b,{x.a,x.c}});
            if(x.b<=a&&x.c<=b&&x.a<=c)st.insert({x.b,{x.c,x.a}});
            if(x.c<=a&&x.a<=b&&x.b<=c)st.insert({x.c,{x.a,x.b}});
            if(x.c<=a&&x.b<=b&&x.a<=c)st.insert({x.c,{x.b,x.a}});
        }
        cout<<st.size()<<endl;
    }
    return 0;
}