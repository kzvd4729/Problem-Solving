/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 8 ms                                            memory_used: 656 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    while(true)
    {
        long f=0;
        for(long i=0;i<s.size()-1;i++)
        {
            if(s[i]=='A'&&s[i+1]=='A')
            {
                s.erase(i,1);
                f=1;
                break;
            }
        }
        if(f==0)break;
    }
    cout<<s<<endl;
    return 0;
}