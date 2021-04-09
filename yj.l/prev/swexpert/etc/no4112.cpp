//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int getResult(const vector<int>& vec, int a, int b) {
//    if (b < a) swap(a, b);
//    int idx1 = lower_bound(vec.begin(), vec.end(), a) - vec.begin();
//    int idx2 = lower_bound(vec.begin(), vec.end(), b) - vec.begin();
//
//    int al, ar, lval, rval;
//    if (idx1 == 0) al = 0;
//    else al = a - vec[idx1 - 1] - 1;
//    ar = vec[idx1] - a;
//    lval = vec[idx2 - 1] + 1 + al;
//    rval = vec[idx2] - ar;
//
//    if (b < lval) return idx2 - idx1 + lval - b;
//    else if (b <= rval) return idx2 - idx1;
//    else return idx2 - idx1 + b - rval;
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
//    vector<int> vec;
//    int sum = 0;
//    for (int i = 1; true; ++i) {
//        sum += i;
//        vec.push_back(sum);
//        if (sum > 10000) break;
//    }
//
//    for(test_case = 1; test_case <= T; ++test_case)
//    {
//        int a, b;
//        cin >> a >> b;
//
//        cout << "#" << test_case << ' ';
//        cout << getResult(vec, a, b);
//        cout << '\n';
//    }
//    return 0;
//}