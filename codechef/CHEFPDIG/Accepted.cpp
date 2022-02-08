/****************************************************************************************
*  @author: kzvd4729                                         created: 05-09-2017 22:11:45                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 15.7M                                
*  problem: https://www.codechef.com/SEPT17/problems/CHEFPDIG
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 100005
using namespace std;
string s;
vector<char>v;
long fre[12],t;
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>s;
        memset(fre,0,sizeof(fre));
        v.clear();
        for(long i=0;i<s.size();i++)
        {
            fre[s[i]-'0']++;
        }
        for(char c='A';c<='Z';c++)
        {
            long x=(long)c;
            long a=x%10;
            long b=x/10;
            if(a==b)
            {
                if(fre[a]>1)v.push_back(c);
            }
            else
            {
                if(fre[a]>0&&fre[b]>0)v.push_back(c);
            }
        }
        for(long i=0;i<v.size();i++)
        {
            cout<<v[i];
        }
        cout<<endl;
    }
    return 0;
}
/*
4
65
566
11
1623455078
*/