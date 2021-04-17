//#include<iostream>
//#include<vector>
//
//using namespace std;
//bool sums[13][20];
//bool mapOri[13][20];
//int d, w, k;
//
//bool checkPassed() {
//    for (int i = 0; i < w; ++i) {
//        int count = 1, max = 1;
//        bool prev = sums[0][i];
//        for (int j = 1; j < d; ++j) {
//            if (sums[j][i] == prev) {
//                count++;
//                max = count > max ? count : max;
//            }
//            else if (d - j < k) break;
//            else {
//                count = 1;
//                prev = sums[j][i];
//            }
//        }
//        if (max < k) return false;
//    }
//    return true;
//}
//
////int dfs(int idx, int depth) {
////    if (checkPassed()) return depth;
////    else if (depth >= k) return k;
////
////    int minVal = k;
////    for (int i = idx; i < d; ++i) {
////        for (int j = 0; j < w; ++j) sums[i][j] = true;
////        minVal = min(minVal, dfs(i + 1, depth + 1));
////        for (int j = 0; j < w; ++j) sums[i][j] = false;
////        minVal = min(minVal, dfs(i + 1, depth + 1));
////        for (int j = 0; j < w; ++j) sums[i][j] = mapOri[i][j];
////    }
////    return minVal;
////}
//
//int dfs(int idx, int depth) {
//    if (idx == d) {
//        if (checkPassed()) return depth;
//        else return k;
//    }
//    else if (depth >= k) return k;
//
//    int minVal = k;
//    minVal = min(minVal, dfs(idx + 1, depth));
//    for (int j = 0; j < w; ++j) sums[idx][j] = true;
//    minVal = min(minVal, dfs(idx + 1, depth + 1));
//    for (int j = 0; j < w; ++j) sums[idx][j] = false;
//    minVal = min(minVal, dfs(idx + 1, depth + 1));
//    for (int j = 0; j < w; ++j) sums[idx][j] = mapOri[idx][j];
//    return minVal;
//}
//
//int getResult() {
//    if (k == 1) return 0;
//
//    for (int i = 0; i < d; ++i) {
//        for (int j = 0; j < w; ++j) {
//            sums[i][j] = mapOri[i][j];
//        }
//    }
//
//    return dfs(0, 0);
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
//        cin >> d >> w >> k;
//        for (int i = 0; i < d; ++i) {
//            for (int j = 0; j < w; ++j) {
//                cin >> mapOri[i][j];
//            }
//        }
//
//        cout << "#" << test_case << ' ';
//        cout << getResult();
//        cout << '\n';
//    }
//    return 0;
//}