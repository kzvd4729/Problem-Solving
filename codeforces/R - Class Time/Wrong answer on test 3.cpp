/****************************************************************************************
*  @author: JU_AAA: prdx9_abir, aniks2645, kzvd4729          created: Sep/15/2017 21:31                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/100819/problem/R
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
 pair<string,string>p[105];
bool f(pair<string,string>x,pair<string,string>y)
{
    int i;
    string xstr=x.first;
    string xstr2=x.second;
    string ystr=y.first;
    string ystr2=y.second;
    for(i=0;i<min(xstr.size(),ystr.size());i++)
    {
        if(xstr[i]==ystr[i])continue;
        if(xstr[i]>ystr[i])return true;
        else return false;
    }
    if(xstr.size()!=ystr.size())
    return xstr.size()>ystr.size();
    for(i=0;i<min(xstr2.size(),ystr2.size());i++)
    {
        if(xstr2[i]==ystr2[i])continue;
        if(xstr2[i]>ystr2[i])return true;
        else return false;
    }
    return xstr2.size()>ystr2.size();
}
int main()
{
    int n,i,j;
    cin>>n;
    string str,str2;
    for(i=0;i<n;i++)
    {
        cin>>str>>str2;
        p[i].first=str;
        p[i].second=str2;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(f(p[j],p[j+1]))
            {
                swap(p[j],p[j+1]);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        str=p[i].first;
        str2=p[i].second;
        cout<<str<<" "<<str2<<endl;
    }
     return 0;
}