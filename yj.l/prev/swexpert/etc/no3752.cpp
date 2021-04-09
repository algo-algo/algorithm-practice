//#include<iostream>
//
//using namespace std;
//int nums[100];
//int sums[10001];
//
//int getResult(int size, int t) {
//    sums[0] = t;
//    int max = 0;
//    for (int i = 0; i < size; i++) {
//        for (int j = max; j >= 0; j--) {
//            if (sums[j] == t) {
//                sums[j + nums[i]] = t;
//                if (j + nums[i] > max) {
//                    max = j + nums[i];
//                }
//            }
//        }
//    }
//
//    int count = 0;
//    for (int b : sums) {
//        if(b == t) count++;
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
//        int num;
//        cin >> num;
//        for (int i = 0; i < num; ++i) {
//            cin >> nums[i];
//        }
//
//        cout << "#" << test_case << " ";
//        cout << getResult(num, test_case);
//        cout << '\n';
//    }
//    return 0;
//}

//#include<iostream>
//#include<vector>
//
//using namespace std;
//int nums[100];
//int sums[10001];
//
//int getResult(int size, int t) {
//    vector<int> vec;
//    vec.push_back(0);
//    sums[0] = t;
//    for (int i = 0; i < size; i++) {
//        for (int j = vec.size() - 1; j >= 0; j--) {
//            if (sums[vec[j] + nums[i]] != t) {
//                sums[vec[j] + nums[i]] = t;
//                vec.push_back(vec[j] + nums[i]);
//            }
//        }
//    }
//
//    return vec.size();
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
//        int num;
//        cin >> num;
//        for (int i = 0; i < num; ++i) {
//            cin >> nums[i];
//        }
//
//        cout << "#" << test_case << " ";
//        cout << getResult(num, test_case);
//        cout << '\n';
//    }
//    return 0;
//}