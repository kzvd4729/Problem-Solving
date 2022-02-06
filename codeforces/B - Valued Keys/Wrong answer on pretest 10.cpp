/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/16/2017 22:33                        
*  solution_verdict: Wrong answer on pretest 10              language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/801/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s1,s2;
char s3[1000];
int main()
{
    int l,i,f=0;
    cin>>s1>>s2;
    l=s1.size();
    for(i=0;i<l;i++)
    {
        if(s1[i]==s2[i])
        {
            if(s1[i]=='z')
            {
                f=1;
                break;
            }
            else s3[i]=s1[i]+1;
        }
        else
        {
            if(s1[i]=='a')
            {
                f=1;
                break;
            }
            if(s2[i]>s1[i])
            {
                f=1;
                break;
            }
            s3[i]=s2[i];
        }
    }
    if(f==1)cout<<-1<<endl;
    else
    {
        for(i=0;i<l;i++)
        {
            cout<<s3[i];
        }
        cout<<endl;
    }
    return 0;
}