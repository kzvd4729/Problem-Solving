/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/06/2018 22:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2500 KB                              
*  problem: https://codeforces.com/contest/946/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s;
int f,mark[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    char c='a';
     /////////////////////
     for(int i=0; i<s.size(); i++)
    {
        if(s[i]<=c)mark[i]=1,c++;
        if(c>'z')
        {
            f=1;
            break;
        }
    }
    if(f==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    c='a';
    for(int i=0; i<s.size(); i++)
    {
        if(mark[i])
            s[i]=c++;
    }
    cout<<s<<endl;
    return 0;
}