/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/15/2017 12:25                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/gym/100112/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long s1,s2;
string s;
priority_queue<long>pq1,pq2;
long convert(string s)
{
    long sum=0;
    for(long i=0;i<s.size();i++)
    {
        sum=sum*10+s[i]-'0';
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     while(cin>>s)
    {
        if(s=="#")
        {
            cout<<-pq2.top()<<endl;
            pq2.pop();
            s2--;
            if(s2<s1)
            {
                long z=pq1.top();
                pq1.pop();
                s1--;
                pq2.push(-z);
                s2++;
            }
            continue;
        }
        long x=convert(s);
        pq2.push(-x);
        s2++;
        if(s1+2==s2)
        {
            long z=pq2.top();
            pq2.pop();
            s2--;
            pq1.push(-z);
            s1++;
        }
     }
    return 0;
}