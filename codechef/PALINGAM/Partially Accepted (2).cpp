/****************************************************************************************
*  @author: kzvd4729                                         created: 06-08-2017 06:12:25                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 15.7M                                
*  problem: https://www.codechef.com/AUG17/problems/PALINGAM
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int tc,s1[30],t1[30],i,f,g;
string s,t;
int main()
{
    cin>>tc;
    while(tc--)
    {
        memset(s1,0,sizeof(s1));
        memset(t1,0,sizeof(t1));
        cin>>s>>t;
        f=0;
        g=0;
        for(i=0;i<s.size();i++)
        {
            s1[(int)(s[i]-'a')]++;
        }
        for(i=0;i<t.size();i++)
        {
            t1[(int)(t[i]-'a')]++;
        }
        for(i=0;i<26;i++)
        {
            if(s1[i]>0&&t1[i]==0)g=1;
        }
        if(g==0)
        {
            cout<<"B"<<endl;
            continue;
        }
        for(i=0;i<26;i++)
        {
            if(s1[i]>1&&t1[i]==0)
            {
                cout<<"A"<<endl;
                f=1;
                break;
            }
        }
        if(f==1)continue;
        for(i=0;i<26;i++)
        {
            if(t1[i]>0&&s1[i]==0)g=1;
        }
        if(g==0)
        {
            cout<<"A"<<endl;
            continue;
        }
        cout<<"B"<<endl;
    }
    return 0;
}