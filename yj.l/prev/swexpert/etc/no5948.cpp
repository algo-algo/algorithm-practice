//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//int sums[301];
//
//int getResult(vector<int> vec, int t) {
//    sort(vec.begin(), vec.end());
//
//    for (int i = 4; i >= 0; --i) {
//        for (int j = 5; j > i; --j) {
//            if (i + j < 5) break;
//            for (int k = 6; k > j; --k) {
//                if (i + j + k < 11) break;
//                sums[vec[i] + vec[j] + vec[k]] = t;
//            }
//        }
//    }
//    int min = 300, count = 0;
//    while (count < 5) {
//        if (sums[min] == t) count++;
//        min--;
//    }
//
//    return min + 1;
//}
//
//int main(int argc, char** argv)
//{
//    cin.tie(NULL);
//    cout.tie(NULL);
//    ios::sync_with_stdio(false);
//    int test_case;
//    int T;
//    cin>>T;
//
//    for(test_case = 1; test_case <= T; ++test_case)
//    {
//        vector<int> vec;
//        for (int i = 0; i < 7; i++) {
//            int n;
//            cin >> n;
//            vec.push_back(n);
//        }
//
//        int result = getResult(vec, test_case);
//
//        cout << "#" << test_case << " ";
//        cout << result;
//        cout << '\n';
//    }
//    return 0;
//}