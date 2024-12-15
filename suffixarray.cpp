#include <iostream>
using namespace std;
const int N=1e5;
bool compare(int i, int j, int rank[], int k, int length) {
    if (rank[i] != rank[j])
        return rank[i] < rank[j];
    int ri = (i + k < length) ? rank[i + k] : -1;
    int rj = (j + k < length) ? rank[j + k] : -1;
    return ri < rj;
}
int partition(int arr[],int rank[],int l,int r,int k){
    int i=l;
    for (int j = i+1; j <=r ; ++j) {
        if (compare(arr[j],arr[l],rank,k,r+1)){
            swap(arr[j],arr[++i]);
        }
    }
    swap(arr[l],arr[i]);
    return i;

}
void quick_sort(int arr[],int rank[],int l,int r,int k){
    if (l>=r)
        return;
    else{
        int m= partition(arr,rank,l,r,k);
        quick_sort(arr,rank,l,m-1,k);
        quick_sort(arr,rank,m+1,r,k);
    }
}
class SuffixArray {
private:
    char text[N];
    int length;
    int suffixArray[N];
    int rank[N];
    int trank[N];
public:
    SuffixArray(const char* s) {
        int cnt=0;
        for (int i = 0; N ; ++i) {
                text[i]=s[i];
                cnt++;
            if (s[i]=='$')break;
        }
        length=cnt;
    }
    void ConstructUsingPrefixDoubling() {
        for (int i = 0; i < length; i++) {
            suffixArray[i] = i;
            rank[i] = text[i]-'A';
        }
        for (int k = 1; k < length; k *= 2) {
            quick_sort(suffixArray,rank,0,length-1,k);
            trank[suffixArray[0]] = 0;
            for (int i = 1; i < length; i++) {
                trank[suffixArray[i]] = trank[suffixArray[i - 1]] +
                                        (compare(suffixArray[i - 1], suffixArray[i],rank,k,length) ? 1 : 0);
            }
            for (int i = 0; i <length ; ++i) {
                rank[i]=trank[i];
            }
        }
    }
    void Print() {
        for (int i = 0; i < length; i++) {
            cout << suffixArray[i] << " ";
        }
    }
};

int main() {
    SuffixArray t("ACGACTACGATAAC$");
    t.ConstructUsingPrefixDoubling();
    t.Print(); // Prints:  14 11 12  0  6  3  9 13  1  7  4  2  8 10  5
    return 0;
}
