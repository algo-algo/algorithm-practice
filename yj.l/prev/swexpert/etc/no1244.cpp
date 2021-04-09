////#include<iostream>
////#include<vector>
////#include<algorithm>
////
////using namespace std;
////
////bool findDup(vector<int> nums) {
////    for (int i = 1; i < nums.size(); i++) {
////        if(nums[i - 1] == nums[i]) return true;
////    }
////    return false;
////}
////
////int getNum(vector<int> nums) {
////    int num = 0;
////    for (int i = 0; i < nums.size(); i++) {
////        int e = 1;
////        for (int j = 0; j < i; j++) e *= 10;
////        num += nums[i] * e;
////    }
////    return num;
////}
////
////int getResult(vector<int> nums, vector<int> sorted, int change) {
////    unsigned long d = sorted.size() - 1;
////    while (d >= 0 && change > 0) {
////        int i;
////        for (i = d; i >= 0; i--) {
////            if (nums[i] == sorted[d] && nums[i] != sorted[i]) {
////                swap(nums[i], nums[d]);
////                break;
////            }
////        }
////        d--;
////        if (i != d) change--;
////    }
////
////    if (change % 2 == 1 && !findDup(nums)) {
////        swap(nums[0], nums[1]);
////    }
////
////    return getNum(nums);
////}
////
////int main(int argc, char** argv)
////{
////    cin.tie(NULL);
////    cout.tie(NULL);
////    ios::sync_with_stdio(false);
////    int test_case;
////    int T;
////    cin>>T;
////
////    for(test_case = 1; test_case <= T; ++test_case)
////    {
////        vector<int> nums;
////        vector<int> sortedArr;
////        int num;
////        int change;
////        cin >> num >> change;
////        int ex = 10;
////        for (int x = num % ex; num != 0; x = num % ex) {
////            num -= x;
////            int n = x * 10 / ex;
////            nums.push_back(n);
////            sortedArr.push_back(n);
////            ex *= 10;
////        }
////
////        sort(sortedArr.begin(), sortedArr.end());
////
////        int result = getResult(nums, sortedArr, change);
////
////        cout << "#" << test_case << " ";
////        cout << result;
////        cout << '\n';
////    }
////    return 0;
////}
//
//#include<iostream>
//#include<set>
//
//using namespace std;
//
//int getChangedNum(int num, int idxA, int idxB) {
//    int result = num;
//    int a, b;
//    int ex = 10, aEx;
//    for (int i = 0; i <= idxB; i++) {
//        int x = num % ex * 10 / ex;
//        if (i == idxA) {
//            a = x;
//            aEx = ex;
//            result -= a * ex / 10;
//        }
//        if (i == idxB) {
//            b = x;
//            result -= b * ex / 10;
//        }
//        ex *= 10;
//    }
//
//    result += a * ex / 100;
//    result += b * aEx / 10;
//    return result;
//}
//
//int getResult(int num, int change) {
//    // get num size
//    int size = 0;
//    for (int i = num; i != 0; i /= 10) size++;
//
//    // bfs
//    set<int> intSet;
//    intSet.insert(num);
//
//    for (int i = 0; i < change; i++) {
//        set<int> newSet;
//
//        for (auto it = intSet.begin(); it != intSet.end(); it++) {
//            for (int a = 0; a < size; a++) {
//                for (int b = a + 1; b < size; b++) {
//                    newSet.insert(getChangedNum(*it, a, b));
//                }
//            }
//        }
//        swap(intSet, newSet);
//    }
//
//    int max = 0;
//    for (auto it = intSet.begin(); it != intSet.end(); it++) {
//        max = *it > max ? *it : max;
//    }
//
//    return max;
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
//        int num;
//        int change;
//        cin >> num >> change;
//
//        int result = getResult(num, change);
//
//        cout << "#" << test_case << " ";
//        cout << result;
//        cout << '\n';
//    }
//    return 0;
//}