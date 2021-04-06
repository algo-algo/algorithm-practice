#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N;
int currentInput;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<int, vector<int>, greater<int> >		minHeap;
	priority_queue<int, vector<int>, less<int> >		maxHeap;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> currentInput;
		if (minHeap.size() == 0) {
			minHeap.push(currentInput);
			cout << currentInput << "\n";
			continue;
		}
		if (maxHeap.size() == 0) {
			if (minHeap.top() < currentInput) {
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(currentInput);
				cout << maxHeap.top() << "\n";
			}
			else {
				maxHeap.push(currentInput);
				cout << maxHeap.top() << "\n";
			}
			continue;
		}

		if (minHeap.size() >= maxHeap.size()) {	//maxHeap에 넣어야 함
			if (minHeap.top() > currentInput)
				maxHeap.push(currentInput);
			else {
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(currentInput);
			}
		}
		else if (minHeap.size() < maxHeap.size()) {
			if (maxHeap.top() < currentInput) 
				minHeap.push(currentInput);
			else {
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(currentInput);
			}
		}
		cout << maxHeap.top() << "\n";
	}

	return 0;
}