//#include<cstdio>
//#include<algorithm>
//#define MOD_NUM 1000000007
//
//using namespace std;
//long long int nums[100];
//int N;
//long long int A, B, maxVal;
//
//long long int getCommonNum() {
//    long long int num = 1;
//    long long int count = B / N;
//
//    long long int tmp = A;
//    while (count) {
//        if (count & 1) num = (num * tmp) % MOD_NUM;
//        tmp = (tmp * tmp) % MOD_NUM;
//        count >>= 1;
//    }
//
//    return num;
//}
//
//void proceed() {
//    for (int i = 0; i < N; ++i) {
//        while (nums[i] * A < maxVal) {
//            nums[i] *= A;
//            B--;
//        }
//    }
//
//    long long int commonProduct = getCommonNum();
//
//    sort(nums, nums + N);
//    int rest = B % N;
//    int i;
//    for (i = 0; i < rest; ++i) {
//        nums[i] = (nums[i] * A) % MOD_NUM;
//    }
//
//    while (nums[i] != -1) {
//        nums[i] = (nums[i] * commonProduct) % MOD_NUM;
//        printf(" %lld", nums[i]);
//        nums[i] = -1;
//        ++i %= N;
//    }
//}
//
//int main(int argc, char** argv)
//{
//    int test_case;
//    int T;
//    scanf("%d", &T);
//
//    for(test_case = 1; test_case <= T; ++test_case)
//    {
//        maxVal = 0;
//        printf("#%d", test_case);
//        scanf("%d %lld %lld", &N, &A, &B);
//        for (int i = 0; i < N; ++i) {
//            long long int num;
//            scanf("%lld", &num);
//            nums[i] = num;
//            if (num > maxVal) maxVal = num;
//        }
//
//        if (A == 1) {
//            sort(nums, nums + N);
//            for (int i = 0; i < N; ++i) printf(" %lld", nums[i]);
//        }
//        else proceed();
//
//        printf("\n");
//    }
//    return 0;
//}