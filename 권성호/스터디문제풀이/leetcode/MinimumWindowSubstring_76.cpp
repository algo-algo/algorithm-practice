#include <iostream>
#include <string>
#include <vector>

using namespace std;

int				goalState[52];
int				currentState[52];
vector<int>		idxVec;
string			ans;


void InitState_Optinal()
{
	idxVec.clear();
	for (int i = 0; i < 52; i++)
	{
		goalState[i] = 0;
		currentState[i] = 0;
	}
	ans = "";
}

bool IsUpperCase(const char& c)
{
	return c < '[';
}

void InitState(const string& s, const string& t)
{
	for (int i = 0; i < t.size(); i++)
	{
		if (IsUpperCase(t[i]))
			goalState[t[i] - 'A']++;
		else
			goalState[t[i] - 'a' + 26]++;
	}

	for (int i = 0; i < s.size(); i++)
	{
		if (IsUpperCase(s[i])) {
			if (goalState[s[i] - 'A'] != 0)
				idxVec.push_back(i);
		}
		else {
			if (goalState[s[i] - 'a' + 26] != 0)
				idxVec.push_back(i);
		}
	}
}

class Solution {
public:
	string minWindow(string s, string t) {
		InitState_Optinal();
		ans = "";
		InitState(s, t);
		int goalSize = t.size();
		int currentSize = 0;

		int start = 0, end = 0;
		if (IsUpperCase(s[idxVec[start]])) {
			currentState[s[idxVec[start]] - 'A']++;
			if (currentState[s[idxVec[start]] - 'A'] <= goalState[s[idxVec[start]] - 'A'])
				currentSize++;
		}
		else {
			currentState[s[idxVec[start]] - 'a' + 26]++;
			if (currentState[s[idxVec[start]] - 'a' + 26] <= goalState[s[idxVec[start]] - 'a' + 26])
				currentSize++;
		}

		while (end < idxVec.size()){
			if (currentSize < goalSize) {	//지금 만족 못함 => e가 앞으로 가야함
				end++;
				if (end >= idxVec.size())
					break;
				if (IsUpperCase(s[idxVec[end]])) {
					currentState[s[idxVec[end]] - 'A']++;
					if (currentState[s[idxVec[end]] - 'A'] <= goalState[s[idxVec[end]] - 'A'])
						currentSize++;
				}
				else {
					currentState[s[idxVec[end]] - 'a' + 26]++;
					if (currentState[s[idxVec[end]] - 'a' + 26] <= goalState[s[idxVec[end]] - 'a' + 26])
						currentSize++;
				}
			}
			else {							//지금 만족 함 => s가 앞으로 가야함
				if (ans == "")
					ans = s.substr(idxVec[start], idxVec[end] - idxVec[start] + 1);
				else {
					if(ans.size() > idxVec[end] - idxVec[start] + 1)
						ans = ans = s.substr(idxVec[start], idxVec[end] - idxVec[start] + 1);
				}

				if (IsUpperCase(s[idxVec[start]])) {
					currentState[s[idxVec[start]] - 'A']--;
					if (currentState[s[idxVec[start]] - 'A'] < goalState[s[idxVec[start]] - 'A'])
						currentSize--;
				}
				else {
					currentState[s[idxVec[start]] - 'a' + 26]--;
					if (currentState[s[idxVec[start]] - 'a' + 26] < goalState[s[idxVec[start]] - 'a' + 26])
						currentSize--;
				}
				start++;
			}
		}

		//마지막에 start만 따로 처리
		while (start < end) {
			if (IsUpperCase(s[idxVec[start]])) {
				currentState[s[idxVec[start]] - 'A']--;
				if (currentState[s[idxVec[start]] - 'A'] < goalState[s[idxVec[start]] - 'A'])
					currentSize--;
			}
			else {
				currentState[s[idxVec[start]] - 'a' + 26]--;
				if (currentState[s[idxVec[start]] - 'a' + 26] < goalState[s[idxVec[start]] - 'a' + 26])
					currentSize--;
			}
			start++;
			if (currentSize == goalSize) {
				if (ans == "")
					ans = s.substr(idxVec[start], idxVec[end] - idxVec[start] + 1);
				else {
					if (ans.size() > idxVec[end] - idxVec[start] + 1)
						ans = ans = s.substr(idxVec[start], idxVec[end] - idxVec[start] + 1);
				}
			}
		}
		
		return ans;
	}
};