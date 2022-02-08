/****************************************************************************************
*  @author: kzvd4729                                         created: 08-07-2017 08:29:42                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.04 sec                                        memory_used: 3.2M                                 
*  problem: https://www.codechef.com/JULY17/problems/CHEFSIGN
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,x,y,mx,i;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        x=100000;
        y=100000;
        mx=0;
        cin>>s;
        for(i=0;i<s.size();i++)
        {
            if(s[i]=='<')x++;
            if(s[i]=='>')x--;
            mx=max(mx,x);
            mx=max(mx,y+y-x);
        }
        cout<<mx-y+1<<endl;
    }
    return 0;
}