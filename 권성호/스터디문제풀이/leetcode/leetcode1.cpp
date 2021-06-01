#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {

private:
	bool cmp(const pair<int, int> p1, const pair<int, int> p2) {
		return p1.first < p2.first;
	}

	int binarySearch(const vector<pair<int,int>>& pairNums, const int& target, int start, int end)
	{
		int mid;
		while (start <= end) {
			mid = (start + end) / 2;
			if (pairNums[mid].first == target)
				return mid;
			else if (pairNums[mid].first < target)
				start = mid + 1;
			else
				end = mid - 1;
		}

		return -1; //target이 없으면 -1리턴(target이 있으면 그 위치의 idx리턴)
	}

public:
	vector<int> twoSum(vector<int>& nums, int target) {
		// nums배열에 원소 2개를 찝어서 target수를 만들 수 있는 index 2개를 리턴
		// 정확히 하나의 답만 있다고 가정(동시에 같은 수를 두번 사용하는 것은 불가)
		vector<int> res;
		vector<pair<int, int>> pairNums;
		for (int i = 0; i < nums.size(); i++)
			pairNums.push_back({ nums[i],i });

		sort(pairNums.begin(), pairNums.end());
		for (int i = 0; i < nums.size() - 1; i++)
		{
			int idx = binarySearch(pairNums, target - pairNums[i].first, i + 1, nums.size() - 1);
			if (idx == -1)
				continue;
			else {
				res = { pairNums[i].second, pairNums[idx].second };
			}
		}
		return res;
	}
};

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <utility>
//
//using namespace std;
//
//class Solution {
//
//
//
//public:
//	vector<int> twoSum(vector<int>& nums, int target) {
//		// nums배열에 원소 2개를 찝어서 target수를 만들 수 있는 index 2개를 리턴
//		// 정확히 하나의 답만 있다고 가정(동시에 같은 수를 두번 사용하는 것은 불가)
//		vector<int> res;
//
//		for (int i = 0; i < nums.size() - 1; i++)
//		{
//			for (int j = i + 1; j < nums.size(); j++)
//			{
//				if (nums[i] + nums[j] == target)
//					res = { i,j };
//			}
//		}
//		return res;
//	}
//};


// int main()
// {
// 	Solution s;
// 	vector<int> test{ 3,2,4 };
// 	s.twoSum(test, 6);
// }
