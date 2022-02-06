/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2018 00:02                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++17                               
*  run_time: 30 ms                                           memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/190/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,p,i;
string x,y,z,ans,str,tmp;
string a="pair";
string b="int";
string c="int2";
stack<string>st;
pair<int,pair<pair<int,pair<int,int>>,int>>pt;
pair<int,pair<pair<int,pair<int,pair<pair<int,pair<pair<int,int>,int>>,int>>>,int>>pu;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>n;
    cin.ignore();
    getline(cin,str);
    stringstream ss;
    ss<<str;
    while(ss>>tmp)
    {
        if(tmp==a)p++;
        else i++;
        if(st.size()<2)st.push(tmp);
        else
        {
            st.push(tmp);
            if(st.size()>2)
            {
                x=st.top();
                st.pop();
                y=st.top();
                st.pop();
                z=st.top();
                st.pop();
                if(z==a&&y!=a&&x!=a)
                {
                    if(y==c&&x==c)
                    {
                        ans="pair<"+ans;
                        ans+=">";
                    }
                    else if(x==b&&y==b)
                    {
                        if(ans.size())
                        {
                            if(ans.back()=='>')ans+=",";
                        }
                        ans+="pair<int,int>";
                    }
                    else if(x==c&&y==b)
                    {
                        ans="pair<int,"+ans;
                        ans+=">";
                    }
                    else
                    {
                        ans="pair<"+ans;
                        ans+=",int>";
                    }
                    if(st.size())
                        st.push(c);
                }
                else
                {
                    st.push(z);
                    st.push(y);
                    st.push(x);
                    break;
                }
            }
        }
    }
    if(st.size()||p+1!=i)cout<<"Error occurred"<<endl;
    else cout<<ans<<endl;
    return 0;
}