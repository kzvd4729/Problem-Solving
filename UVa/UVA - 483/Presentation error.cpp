/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-15 00:10:20                      
*  solution_verdict: Presentation error                      language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-483
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    int l,i,j,u;
    while(getline(cin,s))
    {
        l=s.size();
        u=0;
        for(i=0;i<=l;i++)
        {
            if(s[i]==' '||i==l)
            {
                for(j=i-1;j>=u;j--)
                {
                    cout<<s[j];
                }
                cout<<" ";
                u=i+1;
            }
            
        }
        cout<<endl;
    }
    return 0;
}