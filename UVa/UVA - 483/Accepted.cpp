/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-15 00:15:46                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
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
                if(i==l)cout<<endl;
                else cout<<" ";
                u=i+1;
            }
            
        }
    }
    return 0;
}