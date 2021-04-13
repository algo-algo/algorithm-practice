#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

string word[300000];

int score[9] = { 0, 0, 0, 1, 1, 2, 3, 5, 11 };
int dx[8] = { 0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, r;
	char map[4][4];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> word[i];
	cin >> r;
	for (int i = 0; i < r; i++) {
		int max_score = 0, num = 0;
		string max_word;
		for (int j = 0; j < 4; j++) {
			scanf("%*c");
			for (int k = 0; k < 4; k++) {
				scanf("%c", &map[j][k]);
			}
		}

		for (int j = 0; j < n; j++) {
			int tmp = 0, jn = word[j].size();
			bool att = 0;

			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					if (word[j][tmp] == map[k][l]) {
						for (int t = 1; t < jn; t++) {
							att = 0;
							for (int m = 0; m < 8; m++) {
								int x = k + dx[m];
								int y = l + dy[m];
								if (x > 3 || y > 3 || x < 0 || y < 0)
									continue;
								if (word[j][tmp + t] == map[x][y]) {
									att = 1;
									break;
								}
							}
							if (!att)
								break;
						}
					}
					if (att)
						break;
				}
				if (att)
					break;
			}

			if (att) {
				max_score += score[word[j].size()];
				num++;
				if (jn > max_word.size())
					max_word = word[j];
				else if (jn == max_word.size()) {
					int mn = max_word.size();
					for (int k = 0; k < mn; k++) {
						if (word[j][k] > max_word[k])
							max_word = word[j];
					}
				}

			}
		}
		cout << max_score << ' ' << max_word << ' ' << num << '\n';
	}
}