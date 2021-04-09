//#include<iostream>
//
//using namespace std;
//
////const int ROOT_MAX = 3163;
////const int MAX = 10000001;
////int sums[MAX];
////bool notPrime[ROOT_MAX] = {false, };
////int prime[446];
////
////void init() {
////    // get primes
////    for (int i = 2; i < ROOT_MAX; i++) {
////        if (!notPrime[i]) {
////            for (int j = i * 2; j < ROOT_MAX; j += i) {
////                notPrime[j] = true;
////            }
////        }
////    }
////
////    // set primes
////    int idx = 0;
////    for (int i = 2; i < ROOT_MAX; i++) {
////        if (!notPrime[i]) prime[idx++] = i;
////    }
////
////    // set sums
////    for (int i : prime) {
////        int square = i * i;
////        for (int j = square; j < MAX ; j += square) {
////            int value = sums[j] == 0 ? j : sums[j];
////            while (value % square == 0) value /= square;
////            sums[j] = value;
////        }
////    }
////}
////
////int main(int argc, char **argv) {
////    cin.tie(NULL);
////    cout.tie(NULL);
////    ios::sync_with_stdio(false);
////    int test_case;
////    int T;
////    cin >> T;
////
////    init();
////
////    for (test_case = 1; test_case <= T; ++test_case) {
////        int num;
////        cin >> num;
////
////        int result = sums[num] == 0 ? num : sums[num];
////
////        cout << "#" << test_case << " " << result << '\n';
////    }
////    return 0;
////}
//
//const int MAX = 3163;
//bool notPrime[MAX] = {false, };
//int prime[446];
//
//int getFactors(int num) {
//    int result = 1;
//
//    for (int i = 0; prime[i] * prime[i] <= num && i < 446; i++) {
//        int count = 0;
//        if (num % prime[i] == 0) {
//            while (num % prime[i] == 0) {
//                num /= prime[i];
//                count++;
//            }
//            if (count % 2 == 1) result *= prime[i];
//        }
//    }
//
//    return result * num;
//}
//
//int main(int argc, char **argv) {
//    cin.tie(NULL);
//    cout.tie(NULL);
//    ios::sync_with_stdio(false);
//    int test_case;
//    int T;
//    cin >> T;
//
//    for (int i = 2; i < MAX; i++) {
//        if (!notPrime[i]) {
//            for (int j = i * 2; j < MAX; j += i) {
//                notPrime[j] = true;
//            }
//        }
//    }
//
//    int idx = 0;
//    for (int i = 2; i < MAX; i++) {
//        if (!notPrime[i]) prime[idx++] = i;
//    }
//
//    for (test_case = 1; test_case <= T; ++test_case) {
//        int num;
//        cin >> num;
//
//        int result = getFactors(num);
//
//        cout << "#" << test_case << " " << result << '\n';
//    }
//    return 0;
//}