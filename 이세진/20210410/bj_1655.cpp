#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

int main(void) {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (max_heap.empty())
			max_heap.push(num);
		else if (max_heap.size() == min_heap.size())
			max_heap.push(num);
		else
			min_heap.push(num);

		if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
			int x = max_heap.top();
			int y = min_heap.top();

			max_heap.pop();
			min_heap.pop();
			max_heap.push(y);
			min_heap.push(x);
		}

		cout << max_heap.top() << '\n';
	}
}