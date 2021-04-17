//#include<iostream>
//#include<vector>
//
//using namespace std;
//int sums[20][20];
//
//int canSet(const vector<int>& vec, int minLen) {
//    int prev = vec[0];
//    int curLen = 1;
//
//    for (int i = 1; i < vec.size(); ++i) {
//        if (vec[i] == prev) curLen++;
//        else {
//            if (curLen < 0) return 0;
//
//            if (vec[i] == prev + 1) {
//                if (curLen < minLen) return 0;
//                curLen = 1;
//            }
//            else if (vec[i] == prev - 1) {
//                curLen = -minLen + 1;
//            }
//            else return 0;
//            prev = vec[i];
//        }
//    }
//    return curLen >= 0;
//}
//
//int getResult(int size, int minLen) {
//    int count = 0;
//    for (int i = 0; i < size; ++i) {
//        vector<int> verVec, horVec;
//        for (int j = 0; j < size; ++j) {
//            horVec.push_back(sums[i][j]);
//            verVec.push_back(sums[j][i]);
//        }
//        count += canSet(horVec, minLen) + canSet(verVec, minLen);;
//    }
//    return count;
//}
//
//int main(int argc, char** argv)
//{
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    ios::sync_with_stdio(false);
//    int test_case;
//    int T;
//    cin>>T;
//
//    for(test_case = 1; test_case <= T; ++test_case)
//    {
//        int X, N;
//        cin >> N >> X;
//
//        for (int i = 0; i < N; ++i) {
//            for (int j = 0; j < N; ++j) {
//                cin >> sums[i][j];
//            }
//        }
//
//        cout << "#" << test_case << ' ';
//        cout << getResult(N, X);
//        cout << '\n';
//    }
//    return 0;
//}