#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SuffixArray {
private:
    string text;
    int length;
    vector<int> suffixArray;
    vector<int> rank;
    vector<int> tempRank;
public:
    SuffixArray(const string &text) {
        this->text = text;
        this->length = text.size();
        suffixArray.resize(length);
        rank.resize(length);
        tempRank.resize(length);
    }
    void createSuffixArray() {
        for (int i = 0; i < length; i++) {
            suffixArray[i] = i;
            rank[i] = text[i];
        }
        for (int k = 1; k < length; k *= 2) {

            auto compare = [this, k](int i, int j) {
                if (rank[i] != rank[j])
                    return rank[i] < rank[j];
                int rank_i_k = (i + k < length) ? rank[i + k] : -1;
                int rank_j_k = (j + k < length) ? rank[j + k] : -1;
                return rank_i_k < rank_j_k;
            };


            sort(suffixArray.begin(), suffixArray.end(), compare);

            tempRank[suffixArray[0]] = 0;
            for (int i = 1; i < length; i++) {
                tempRank[suffixArray[i]] = tempRank[suffixArray[i - 1]] +
                                           (compare(suffixArray[i - 1], suffixArray[i]) ? 1 : 0);
            }
            rank = tempRank;
        }
    }

    void printSuffixArray() {
        for (int i = 0; i < length; i++) {
            cout << text.substr(suffixArray[i]) << "\t" << suffixArray[i] << endl;
        }
    }
    void Search(const string& temp){
        int l=0,r=text.size(),mid;
        while (r-l>1){
            mid=(r+l)/2;
            if (text.substr(suffixArray[mid], temp.size())<=temp)l=mid;
            else
                r=mid;
        }
        cout<<(temp==text.substr(suffixArray[l],temp.size())?"Yes":"No")<<"\n";
    }
};

int main() {
    string text;
    cin >> text;
    SuffixArray suffixArray(text);
    suffixArray.createSuffixArray();
int q;cin>>q;
    while (q--){
        cin>>text;
        suffixArray.Search(text);
    }



    return 0;
}
