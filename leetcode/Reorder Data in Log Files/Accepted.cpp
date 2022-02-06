/****************************************************************************************
*  @author: kzvd4729                                         created: 07/19/2021 22:55                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 20 ms                                           memory_used: 18.7 MB                              
*  problem: https://leetcode.com/problems/reorder-data-in-log-files
****************************************************************************************/
class Solution {
public:
        int findSpace(string s)
    {
        // finding first space
        for(int i=0;i<(int)s.size();i++)
        {
            if(s[i]==' ')
            {
                return i;
                break;
            }
        }
        return -1;
    }
        bool isDigit(string s)
    {
        int space=findSpace(s);
                for(int i=space+1;i<(int)s.size();i++)
        {
            if(s[i]==' ')continue;
                        if(s[i]>='a' && s[i]<='z')return false;
        }
        return true;
    }
        vector<string> reorderLogFiles(vector<string>& logs) 
    {
        vector<string>letter, digit;
                for(auto x:logs)
        {
            if(isDigit(x))digit.push_back(x);
            else letter.push_back(x);
        }
                sort(letter.begin(),letter.end(),[&](string a,string b)
        {
            int i=findSpace(a),j=findSpace(b);
                        if(a.substr(i,a.size()-i)!=b.substr(j,b.size()-j))
            {
                return a.substr(i,a.size()-i) < b.substr(j,b.size()-j);
            }
            else 
            {
                return a.substr(0,i+1) < b.substr(0,j+1);
            }
        });
                for(auto x:digit)letter.push_back(x);
                return letter;
    }
};