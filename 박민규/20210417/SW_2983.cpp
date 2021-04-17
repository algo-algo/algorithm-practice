#include<iostream>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

vector<string> vecStr;
map<string, int> mapStr;
void Init()
{
    vecStr.clear();
    mapStr.clear();
}

int main(int argc, char** argv)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int result = 0;
        int L; 
        string str;
        Init();

        cin >> L;
        cin >> str;
        int strSize = str.size();
        for (int i = 0; i < strSize; i++)
        {
            string sa = str.substr(i);
            vecStr.push_back(sa);
        }

        sort(vecStr.begin(), vecStr.end());

        for (int i = 0; i < strSize; i++)
        {
            if (i == 0)
                mapStr[vecStr[i]] = 0;
            else
            {
                auto itr = mapStr.find(vecStr[i]);
                if (itr != mapStr.end()) continue;
                int minlen = min(vecStr[i - 1].size(), vecStr[i].size());
                int cnt = 0;
                for (int j = 0; j < minlen; j++)
                {
                    if (vecStr[i - 1][j] == vecStr[i][j])
                        cnt++;
                    else
                        break;
                }
                if (cnt > 0)
                {
                    for (int k = cnt; k > 0; k--) {
                        string tmp = vecStr[i].substr(cnt - k);
                        auto itr2 = mapStr.find(tmp);
                        if (itr2 == mapStr.end()) mapStr[tmp] = k;
                    }
                }
                else
                    mapStr[vecStr[i]] = 0;
            }
        }

        for (auto itr = mapStr.begin(); itr != mapStr.end(); itr++)
        {
            result = max(result, itr->second);
        }

        cout << '#' << test_case << ' ' << result << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}