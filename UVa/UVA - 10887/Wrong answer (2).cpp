/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-18 15:07:29                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10887
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s1[1505],s2[1505],tmp;
long tc,t,n,m,ans,h1,h2;
set<pair<long,long> >st;
long Hash1(string x)
{
    long z=1;
    for(int i=0;i<x.size();i++)
    {
        z=(z*19+(long)x[i])%10000000007;
    }
    return z;
}
long Hash2(string x)
{
    long z=1;
    for(int i=0;i<x.size();i++)
    {
        z=(z*17+(long)x[i])%10000000007;
    }
    return z;
}
int main()
{
    ///ofstream cout("out.txt");
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>s1[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>s2[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                tmp.clear();
                tmp=s1[i]+s2[j];
                h1=Hash1(tmp);
                h2=Hash2(tmp);
                if(h1>h2)swap(h1,h2);
                st.insert(make_pair(h1,h2));
            }
        }
        cout<<"Case "<<++tc<<": "<<st.size()<<endl;
        st.clear();
    }
    return 0;
}