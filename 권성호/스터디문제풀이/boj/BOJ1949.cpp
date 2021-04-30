#include <iostream>
#include <vector>

using namespace std;

int				N;
int				nodeNum[10001];
bool			check[10001];
vector<int>		treeGraph[10001];

void InputAndInit()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> nodeNum[i];
		check[i] = false;
		treeGraph[i].clear();
	}
	int s, e;
	for (int i = 0; i < N - 1; i++) {
		cin >> s >> e;
		treeGraph[s].push_back(e);
		treeGraph[e].push_back(s);
	}
}

int OutPut() {
	int ans = nodeNum[1];
	for (int i = 2; i <= N; i++)
	{
		ans = ans > nodeNum[i] ? ans : nodeNum[i];
	}

	return ans;
}

void ReculsiveDP(int currentNode, int parentNode, int grandParent)
{
	check[currentNode] = true;
	int option1 = 0, option2 = 0;

	option1 = nodeNum[currentNode];
	for (int i = 0; i < treeGraph[currentNode].size(); i++) {
		int child = treeGraph[currentNode][i];
		if (child == parentNode)
			continue;

		if (!check[child]) {
			ReculsiveDP(child, currentNode, parentNode);
			option2 += nodeNum[child];

			for (int j = 0; j < treeGraph[child].size(); j++) {
				int childchild = treeGraph[child][j];
				if (childchild == grandParent || childchild == currentNode)
					continue;
				if (!check[childchild]) {
					ReculsiveDP(childchild, child, currentNode);
					option1 += nodeNum[childchild];
				}
				else
					option1 += nodeNum[childchild];

			}
		}
		else 
			option2 += nodeNum[child];

	}

	nodeNum[currentNode] = option1 > option2 ? option1 : option2;
}

int main()
{
	InputAndInit();

	int root = 1;
	ReculsiveDP(root, -1, -1);
	/*for (int i = 1; i <= N; i++)
	{
		if (check[i] == true)
			continue;

		ReculsiveDP(i);

	}*/

	cout << OutPut() << "\n";
}