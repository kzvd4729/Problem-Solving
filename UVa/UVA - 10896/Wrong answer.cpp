/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-02-02 01:27:39                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10896
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t;
string enc,ddc,s[100];
int main()
{
    cin>>t;
    while(t--)
    {
        getchar();
        getline(cin,enc);
        int l=0,id=0;
        for(int i=0;i<enc.size();i++)
        {
            if(enc[i]==' ')
            {
                s[++id]=enc.substr(l,i-l);
                l=i+1;
            }
            if(i==enc.size()-1)
            {
                s[++id]=enc.substr(l,i-l+1);
            }
        }
        ///for(int i=1;i<=id;i++)cout<<s[i]<<endl;
        cin>>ddc;
        ///cout<<enc<<endl<<ddc<<endl;
        ///for(int i=1;i<=id;i++)cout<<s[i]<<endl;
        string tmp,ans;
        for(int i=0;i<25;i++)
        {
            tmp.clear();
            for(int j=0;j<ddc.size();j++)
            {
                int c=ddc[j]+i;
                c=c%123;
                if(c<30)c+=97;
                ///c%=26;
                ///char c=s[j][k]+i;
                tmp+=char(c);
                ///tmp.push_back(char(int(s[j][k]+i)%26));
            }
            for(int j=1;j<=id;j++)
            {
                ///cout<<tmp<<endl;
                if(tmp==s[j])
                {
                    int c=i+'a';
                    c=c%123;
                    if(c<30)c+=97;
                    ans.push_back(char(c));
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}