#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int A[4000], B[4000], C[4000], D[4000];

//map<int, int> m1, m2;
vector<int> v1, v2;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	/*input*/

	//1) 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{	
			v1.push_back(A[i] + B[j]);
			v2.push_back(C[i] + D[j]);
		}
	}

	long long ans = 0;
	//sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v1.size(); i++)
	{
		long long temp = upper_bound(v2.begin(), v2.end(), -v1[i]) - lower_bound(v2.begin(), v2.end(), -v1[i]);
		ans += temp;
	}
	cout << ans << '\n';
	return 0;
}