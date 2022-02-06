/****************************************************************************************
*  @author: kzvd4729#                                        created: May/09/2017 17:41                        
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
    if(int(s.find("C"))>=0&&int(s.find("ODEFORCES"))>=0&&int(s.find("C"))<int(s.find("ODEFORCES")))f=1;
    else if(int(s.find("CO"))>=0&&int(s.find("DEFORCES"))>=0&&int(s.find("CO"))<int(s.find("DEFORCES")))f=1;
    else if(int(s.find("COD"))>=0&&int(s.find("EFORCES"))>=0&&int(s.find("COD"))<int(s.find("EFORCES")))f=1;
    else if(int(s.find("CODE"))>=0&&int(s.find("FORCES"))>=0&&int(s.find("CODE"))<int(s.find("FORCES")))f=1;
    else if(int(s.find("CODEF"))>=0&&int(s.find("ORCES"))>=0&&int(s.find("CODEF"))<int(s.find("ORCES")))f=1;
    else if(int(s.find("CODEFO"))>=0&&int(s.find("RCES"))>=0&&int(s.find("CODEFO"))<int(s.find("RCES")))f=1;
    else if(int(s.find("CODEFOR"))>=0&&int(s.find("CES"))>=0&&int(s.find("CODEFOR"))<int(s.find("CES")))f=1;
    else if(int(s.find("CODEFORC"))>=0&&int(s.find("ES"))>=0&&int(s.find("CODEFORC"))<int(s.find("ES")))f=1;
    else if(int(s.find("CODEFORCE"))>=0&&int(s.find("S"))>=0&&int(s.find("CODEFORCE"))<int(s.find("S")))f=1;
    if(f==0)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
        return 0;
}