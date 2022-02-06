/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/16/2017 21:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/801/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s,s2;
int main()
{
    int l,i,c1,c2,c3,j;
    cin>>s;
    l=s.size();
    c1=0,c2=0,c3=0;
    for(i=1;i<l;i++)
    {
        if(s[i-1]=='V'&&s[i]=='K')
        {
            c1++;
            i++;
        }
    }
    s2=s;
    for(j=0;j<l;j++)
    {
        s2=s;
        s2[j]='V';
        c2=0;
        for(i=1;i<l;i++)
        {
            if(s2[i-1]=='V'&&s2[i]=='K')
            {
                c2++;
                i++;
            }
        }
        if(c2>c1)c1=c2;
    }
    for(j=0;j<l;j++)
    {
        s2=s;
        s2[j]='K';
        c3=0;
        for(i=1;i<l;i++)
        {
            if(s2[i-1]=='V'&&s2[i]=='K')
            {
                c3++;
                i++;
            }
        }
        if(c3>c1)c1=c3;
    }
    cout<<c1<<endl;
    return 0;
}