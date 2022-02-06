/****************************************************************************************
*  @author: kzvd4729                                         created: 01/28/2022 20:21                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 4 ms                                            memory_used: 7.1 MB                               
*  problem: https://leetcode.com/problems/divide-a-string-into-groups-of-size-k
****************************************************************************************/
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) 
    {
        vector<string>v;
        string tmp;
                for(int i=0;i<(int)s.size();i++)
        {
            tmp.push_back(s[i]);
            if((int)tmp.size()==k)
            {
                v.push_back(tmp);
                tmp.clear();
            }
        }
        if((int)tmp.size()==0)return v;
        while((int)tmp.size()<k)tmp.push_back(fill);
                v.push_back(tmp);
        return v;
    }
};