/****************************************************************************************
*  @author: kzvd4729                                         created: 17-05-2017 13:52:41                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/MAY17/problems/CHEFROUT
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
long t,f,i,j;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>s;
        for(i=0;i<s.size();i++)
        {
            if(s[i]=='E')break;
        }
        for(j=i+1;j<s.size();j++)
        {
            if(s[j]=='C')
            {
                f=1;
                break;
            }
        }
        for(i=0;i<s.size();i++)
        {
            if(s[i]=='S')break;
        }
        for(j=i+1;j<s.size();j++)
        {
            if(s[j]=='C'||s[j]=='E')
            {
                f=1;
                break;
            }
        }
        if(f==1)cout<<"no"<<endl;
        else cout<<"yes"<<endl;
            }
    return 0;
}