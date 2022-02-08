/****************************************************************************************
*  @author: kzvd4729                                         created: 03-02-2018 19:00:11                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.05 sec                                        memory_used: 15.8M                                
*  problem: https://www.codechef.com/FEB18/problems/PERMPAL
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,cnt,odd;
vector<int>vec[30];
string s;
deque<int>dq;
int main()
{
    cin>>t;
    while(t--)
    {
        for(int i=0; i<26; i++)vec[i].clear();
        cin>>s;
        for(int i=0; i<s.size(); i++)vec[s[i]-'a'].push_back(i+1);
        cnt=0,odd=-1;
        for(int i=0; i<26; i++)
        {
            if(vec[i].size()%2==1)
            {
                odd=i;
                cnt++;
            }
        }
        while(dq.size())dq.pop_front();
        if(cnt>1)
        {
            cout<<-1<<endl;
        }
        else
        {
            if(odd!=-1)
            {
                dq.push_back(vec[odd][vec[odd].size()-1]);
                vec[odd].pop_back();
            }
            for(int i=0; i<26; i++)
            {
                while(vec[i].size())
                {
                    dq.push_back(vec[i][vec[i].size()-1]);
                    vec[i].pop_back();
                    dq.push_front(vec[i][vec[i].size()-1]);
                    vec[i].pop_back();
                }
            }
            while(dq.size())
            {
                cout<<dq.front()<<" ";
                dq.pop_front();
            }
            cout<<endl;
        }
    }
    return 0;
}