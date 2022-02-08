/****************************************************************************************
*  @author: kzvd4729                                         created: 02-02-2018 15:11:43                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.33 sec                                        memory_used: 15.9M                                
*  problem: https://www.codechef.com/FEB18/problems/CHEFCHR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        int c=0,h=0,e=0,f=0,ans=0;
        for(int i=0;i<4;i++)
        {
            if(s[i]=='c')c++;
            if(s[i]=='f')f++;
            if(s[i]=='h')h++;
            if(s[i]=='e')e++;
        }
        if(c&&h&&e&&f)ans++;
        for(int i=4;i<s.size();i++)
        {
            if(s[i-4]=='c')c--;
            if(s[i-4]=='f')f--;
            if(s[i-4]=='h')h--;
            if(s[i-4]=='e')e--;
            if(s[i]=='c')c++;
            if(s[i]=='f')f++;
            if(s[i]=='h')h++;
            if(s[i]=='e')e++;
            if(c&&h&&e&&f)ans++;
        }
        if(ans)cout<<"lovely "<<ans<<endl;
        else cout<<"normal"<<endl;
    }
    return 0;
}