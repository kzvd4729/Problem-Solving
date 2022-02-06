/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/13/2017 21:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3000 KB                              
*  problem: https://codeforces.com/contest/831/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
string s1,s2,txt,tmp1,tmp2;
char ans[1000003];
int i,id,f;
int main()
{
    cin>>s1>>s2>>txt;
     for(i=0;i<s1.size();i++)
    {
        tmp1.clear();
        tmp2.clear();
        tmp1+=s1[i];
        tmp2+=s2[i];
        mp[tmp1]=tmp2;
    }
     id=-1;
     for(i=0;i<txt.size();i++)
    {
        if((txt[i]<'A'||txt[i]>'Z')&&(txt[i]<'a'||txt[i]>'z'))
        {
            ans[++id]=(char)txt[i];
        }
        else
        {
            f=0;
            if(txt[i]>='A'&&txt[i]<='Z')
            {
                f=1;
                txt[i]=txt[i]-('A'-'a');
            }
            tmp1.clear();
            tmp2.clear();
            tmp1+=txt[i];
            tmp2=mp[tmp1];
            ans[++id]=tmp2[0];
            if(f==1)
            {
                ans[id]=ans[id]+('A'-'a');
            }
         }
    }
    ans[++id]='\0';
    cout<<ans<<endl;
     return 0;
}