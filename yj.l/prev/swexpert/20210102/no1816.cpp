//#include<iostream>
//
//using namespace std;
//
//int notCycle[15];
//string nums[15];
//int sums[750];
//long long dp[32768][100];
//int rests[15], lens[15];
//int test_case, T;
//int N, K;
//
//void setMap() {
//    int lenSum = 0;
//    for (const auto& item : nums) lenSum+= item.length();
//
//    sums[0] = 1;
//    for (int j = 1; j <= lenSum; ++j) {
//        sums[j] = sums[j - 1] * 10;
//        if (sums[j] >= K) sums[j] %= K;
//    }
//}
//
//void makeNodes() {
//    for (int i = 0; i < N; ++i) {
//        int rest = 0, len = nums[i].length();
//
//        for (int j = len - 1; j >= 0 ; --j) {
//            int digit = nums[i][j] - '0';
//            rest += digit * sums[len - 1 - j];
//            if (rest >= K) rest %= K;
//        }
//
//        rests[i] = rest;
//        lens[i] = len;
//    }
//}
//
//long long dfs(int rest, int checkInt, const int endCondition) {
//    if (checkInt == endCondition) return !rest;
//
//    if (dp[checkInt][rest] != -1) return dp[checkInt][rest];
//    long long sum = 0;
//    for (int i = 0; i < N; ++i) {
//        if (checkInt & notCycle[i]) continue;
//
//        int nRest = rests[i] + rest * sums[lens[i]];
//        if (nRest >= K) nRest %= K;
//        sum += dfs(nRest, checkInt + notCycle[i], endCondition);
//    }
//    dp[checkInt][rest] = sum;
//    return sum;
//}
//
//long long getResult() {
//    if (K == 1) {
//        long long result = 1;
//        for (int i = 1; i <= N; ++i) result *= i;
//        return result;
//    }
//
//    for (int i = 0; i < 1 << N; ++i) {
//        for (int j = 0; j < K; ++j) {
//            dp[i][j] = -1;
//        }
//    }
//    setMap();
//    makeNodes();
//
//    return dfs(0, 0, (1 << N) - 1);
//}
//
//int main(int argc, char** argv)
//{
//    scanf("%d", &T);
//    for (int i = 0; i < 15; ++i) notCycle[i] = 1 << i;
//
//    for(test_case = 1; test_case <= T; ++test_case)
//    {
//        scanf("%d", &N);
//        for (int i = 0; i < N; ++i) cin >> nums[i];
//        scanf("%d", &K);
//
//        printf("#%d %lld\n", test_case, getResult());
//    }
//    return 0;
//}