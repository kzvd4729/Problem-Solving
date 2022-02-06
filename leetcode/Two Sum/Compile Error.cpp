/****************************************************************************************
*  @author: kzvd4729                                         created: 06/09/2021 00:28                         
*  solution_verdict: Compile Error                           language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/two-sum
****************************************************************************************/
vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < numbers.size(); i++) {
        int numberToFind = target - numbers[i];
            //if numberToFind is found in map, return them
        if (hash.find(numberToFind) != hash.end()) {
                    //+1 because indices are NOT zero based
            result.push_back(hash[numberToFind] + 1);
            result.push_back(i + 1);            
            return result;
        }
            //number was not found. Put it in the map.
        hash[numbers[i]] = i;
    }
    return result;
}