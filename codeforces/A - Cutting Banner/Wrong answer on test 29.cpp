/****************************************************************************************
*  @author: kzvd4729#                                        created: May/09/2017 17:32                        
*  solution_verdict: Wrong answer on test 29                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/538/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    cin>>s;
    int f=0;
    if(int(s.find("C"))>=0&&int(s.find("ODEFORCES"))>=0)f=1;
    else if(int(s.find("CO"))>=0&&int(s.find("DEFORCES"))>=0)f=1;
    else if(int(s.find("COD"))>=0&&int(s.find("EFORCES"))>=0)f=1;
    else if(int(s.find("CODE"))>=0&&int(s.find("FORCES"))>=0)f=1;
    else if(int(s.find("CODEF"))>=0&&int(s.find("ORCES"))>=0)f=1;
    else if(int(s.find("CODEFO"))>=0&&int(s.find("RCES"))>=0)f=1;
    else if(int(s.find("CODEFOR"))>=0&&int(s.find("CES"))>=0)f=1;
    else if(int(s.find("CODEFORC"))>=0&&int(s.find("ES"))>=0)f=1;
    else if(int(s.find("CODEFORCE"))>=0&&int(s.find("S"))>=0)f=1;
    else if(int(s.find("CODEFORCES"))>=0)f=1;
    if(f==0)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
        return 0;
}