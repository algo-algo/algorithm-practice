#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int				N;


int main()
{
	int i, j, k;
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	vector<int> seq;
	int target;
	cin >> target;
	seq.push_back(target);
	for (i = 1; i < N; i++)
	{
		cin >> target;
		if(seq[seq.size() - 1] < target)
			seq.push_back(target);
		else
		{
			auto iter = lower_bound(seq.begin(), seq.end(), target);
			*iter = target;
		}
	}


	cout << seq.size();
}