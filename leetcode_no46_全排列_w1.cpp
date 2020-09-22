/*----------------------------------------------------------------------|
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-----------------------------------------------------------------------*/

/*	递归法
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了88.82%的用户
*	内存消耗：7.6 MB, 在所有 C++ 提交中击败了21.32%的用户
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void backtrack(vector<vector<int>>& res, vector<int>& nums, int start, int end)
{
	if (start == end)
	{
		res.emplace_back(nums);
		return;
	}

	for (int i = start;i < end; i++)
	{
		swap(nums[i], nums[start]);

		backtrack(res, nums, start + 1, end);

		swap(nums[i], nums[start]);
	}
}

vector<vector<int> > permute(vector<int>& nums) 
{
	vector<vector<int> > res;
	backtrack(res, nums, 0, nums.size());
	return res;
}

int main()
{
	vector<int> nums = { 1, 2, 3 };

	vector<vector<int> > res = permute(nums);
}