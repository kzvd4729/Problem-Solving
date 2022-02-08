/****************************************************************************************
*  @author: kzvd4729                                         created: 13-04-2017 22:30:27                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 3.2M                                 
*  problem: https://www.codechef.com/APRIL17/problems/SIMDISH
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s1[10],s2[10];
int main()
{
    int t,i,j,cnt;
    cin>>t;
    while(t--)
    {
        for(i=0;i<4;i++)
        {
            cin>>s1[i];
        }
        for(i=0;i<4;i++)
        {
            cin>>s2[i];
        }
        cnt=0;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(s1[i]==s2[j])cnt++;
            }
        }
        if(cnt>=2)cout<<"similar"<<endl;
        else cout<<"dissimilar"<<endl;
    }
    return 0;
}