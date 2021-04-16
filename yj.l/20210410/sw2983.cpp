//#include<iostream>
//#include<vector>
//
//using namespace std;
////char str[200001];
////
////class Trie {
////public:
////    int depth;
////    vector<int> idxList;
////    vector<Trie*> children;
////    Trie(int depth) {
////        this->depth = depth;
////        for (int i = 0; i < 26; ++i) children.push_back(nullptr);
////    }
////    ~Trie() { for (auto& p: children) delete p; }
////    void insert(int idx) {
////        idxList.push_back(idx);
////    }
////    void expand(int i) {
////        vector<int> tmp;
////        for(int idx: idxList) {
////            if (idx >= i - 1) {
////                tmp.push_back(idx);
////                continue;
////            }
////            int idxCh = str[idx] - 'a';
////            if (children[idxCh] == nullptr)
////                children[idxCh] = new Trie(depth + 1);
////            children[idxCh]->insert(idx + 1);
////        }
////        tmp.swap(idxList);
////    }
////};
////
////void addNext(vector<Trie*>& correct, Trie* curr, int idx, int idxCh, int& answer) {
////    curr->expand(idx);
////    if (curr->children[idxCh] != nullptr) correct.push_back(curr->children[idxCh]);
////    else if (answer < curr->depth) {
////        answer = curr->depth;
////    }
////}
////
////int getResult() {
////    int answer = 0, n;
////    cin >> n;
////
////    Trie* root = new Trie(0);
////    vector<Trie*> correct;
////    for (int i = 0; i < n; ++i) {
////        char ch;
////        cin >> ch;
////        str[i] = ch;
////        int idxCh = ch - 'a';
////
////        vector<Trie*> newCorr;
////        addNext(newCorr, root, i, idxCh, answer);
////        for (auto p: correct) {
////            addNext(newCorr, p, i, idxCh, answer);
////        }
////        correct.swap(newCorr);
////        root->insert(i);
////    }
////
////    if (!correct.empty()) {
////        int depth = correct[correct.size() - 1]->depth;
////        if (answer < depth) answer = depth;
////    }
////
////    delete root;
////    return answer;
////}
//
//vector<pair<int, int>> idxArr[26];
//
//int getResult() {
//    int answer = 0, n;
//    cin >> n;
//
//    for (auto& vec: idxArr) vector<pair<int, int>>().swap(vec);
//
//    vector<pair<int, int>> vec;
//    for (int i = 0; i < n; ++i) {
//        char ch;
//        cin >> ch;
//        int idxCh = ch - 'a';
//
//        vector<pair<int, int>> tmpVec(idxArr[idxCh]);
//        int tmpIdx = 0;
//        for (auto p: vec) {
//            int idx2 = p.first + 1;
//            while (tmpIdx < tmpVec.size() && tmpVec[tmpIdx].first < idx2) tmpIdx++;
//            if (tmpIdx == tmpVec.size()) break;
//            if (tmpVec[tmpIdx].first == idx2) {
//                tmpVec[tmpIdx].second = p.second + 1;
//                if (answer < p.second + 1) answer = p.second + 1;
//            }
//        }
//        tmpVec.swap(vec);
//
//        idxArr[idxCh].push_back({i, 1});
//    }
//    return answer;
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
//        cout << "#" << test_case << ' ';
//        cout << getResult();
//        cout << '\n';
//    }
//    return 0;
//}