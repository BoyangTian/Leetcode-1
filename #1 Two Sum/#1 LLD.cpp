#include <map>
#include <vector>
#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/two-sum/

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must
be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9 Output: index1=1, index2=2
*/

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> result;
		map<int, int> valueindex;	// map value to index
		for(int i = nums.size() - 1; i >= 0; i--)
		{
			if(valueindex.find(target - nums[i]) != valueindex.end())
			{
				//finded
				result.push_back(i + 1);
				result.push_back(valueindex[target - nums[i]]);
				break;
			}
			else
			{
				valueindex[nums[i]] = i + 1;
			}
		}
		return result;
	}
};

/*
idea: map uses red-black tree? Searching costs O(logN)
complexity: Time O(NlogN)
*/

int main(void)
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);
	Solution engine;
	vector<int> res = engine.twoSum(nums, 9);
	cout << res[0] << '\t' << res[1] << '\n';
	return 0;
}