/****************************************************************************************
*  @author: kzvd4729                                         created: 05/30/2021 19:45                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 80 ms                                           memory_used: 35 MB                                
*  problem: https://leetcode.com/problems/maximum-value-after-insertion
****************************************************************************************/
class Solution {
public:
    string maxValue(string n, int x) 
    {
      string a=n;
      int p=a.size();
      if(a[0]!='-')
      {
        for(int i=0;i<(int)a.size();i++)
        {
          if(a[i]-'0'<x){p=i;break;}
        }
        a.insert(a.begin()+p,(char)(x+'0'));
      }
      else
      {
        for(int i=1;i<(int)a.size();i++)
        {
          if(a[i]-'0'>x){p=i;break;}
        }
        a.insert(a.begin()+p,(char)(x+'0'));
      }
      return a;
    }
};