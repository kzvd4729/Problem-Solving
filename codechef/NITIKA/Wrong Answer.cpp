/****************************************************************************************
*  @author: kzvd4729                                         created: 08-07-2017 07:50:15                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/JULY17/problems/NITIKA
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,i,cnt;
string s,temp,name[10];
int main()
{
    cin>>t;
    getchar();
    while(t--)
    {
        getline(cin,s);
        cnt=0;
        for(i=0;i<s.size();i++)
        {
            if((s[i]<'a'||s[i]>'z')&&(s[i]<'A'||s[i]>'Z'))
            {
                if(temp.size())name[++cnt]=temp;
                temp.clear();
            }
            else
            {
                if(s[i]>'A'&&s[i]<'Z')s[i]=s[i]-'A'+'a';
                if(!temp.size())s[i]=s[i]+'A'-'a';
                temp+=s[i];
            }
        }
        if(temp.size())name[++cnt]=temp,temp.clear();
        if(cnt==1)cout<<name[1]<<endl;
        if(cnt==2)cout<<name[1][0]<<". "<<name[2]<<endl;
        if(cnt==3)cout<<name[1][0]<<". "<<name[2][0]<<". "<<name[3]<<endl;
    }
    return 0;
}