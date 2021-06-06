#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {	
		if (s.size() == 1)
			return s;

		int maxLen = 0;
		string ans;
		int start, end;
		for (int i = 0; i < s.size() - 1; i++)
		{
			start = i - 1; end = i + 1;

			while (s[i] == s[end])
				end++;

			while (start >= 0 && end < s.size()) {
				if (s[start] != s[end])
					break;
				start--;
				end++;
			}
			end--; start++;
			int currentLen = end - start + 1;
			if (maxLen > currentLen)
				continue;

			maxLen = currentLen;
			ans = s.substr(start, end -start + 1);
		}

		return ans;
	}
};
