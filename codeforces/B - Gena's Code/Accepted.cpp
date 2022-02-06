/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/17/2017 20:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 4500 KB                              
*  problem: https://codeforces.com/contest/614/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,zero,i,ii;
string s[100005],ss,z;
bool ugly(string ss)
{
    ///cout<<ss.size()<<endl;
     if(ss[0]!='1')return true;
    for(ii=1;ii<ss.size();ii++)
    {
        if(ss[ii]!='0')return true;
    }
    return false;
}
int main()
{
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>s[i];
    }
    for(i=1; i<=n; i++)
    {
        if(s[i]=="0")
        {
            cout<<"0"<<endl;
            return 0;
        }
    }
    for(i=1; i<=n; i++)
    {
        if(ugly(s[i]))
        {
            z=s[i];
        }
        else
        {
            zero+=s[i].size()-1;
        }
    }
    if(z=="")z="1";
     cout<<z;
    for(i=1; i<=zero; i++)cout<<'0';
    cout<<endl;
       return 0;
}