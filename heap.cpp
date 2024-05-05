#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+2,M=65,mod=1073741824;
#define Fast ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);

class Max_Heap{
    vector<int>v;// 0 based index
    int heap_size;
    int parent(int inx){
        return (inx-1)/2;
    }
    int left_child(int inx){
        return (inx*2)+1;
    }
    int right_child(int inx){
        return (inx*2)+2;
    }
public:
    Max_Heap():heap_size(0){
    }
    void insert(int value){
        v.push_back(value);
        heap_size++;
        int inx=heap_size-1;//bec i deal with zero based
        while (inx!=0 &&v[inx]>v[parent(inx)]){
            swap(v[inx],v[parent(inx)]);
            inx= parent(inx);
        }
    }
    int Heap_size(){
        return heap_size;
    }
    int delete_root(){
        if (heap_size==0){
            return INT_MIN;
        }
        else if (heap_size==1){
            int val=v.back();
            v.pop_back();
            heap_size--;
            return val;
        }
        int val=v.front();
        v[0]=v.back();
        v.pop_back();heap_size--;
        heapify(0);
        return val;

    }
    void heapify(int i){
        int l= left_child(i);
        int r= right_child(i);
        int max=i;
        if (l < heap_size && v[l] > v[max])
            max = l;
        if (r < heap_size && v[r] > v[max])
            max = r;
        if (max != i) {
            swap(v[i], v[max]);
            heapify(max);
        }
    }
    void print(){
        for(auto it:v)
            cout<<it<<" ";
    }
};
int main() {
    Fast
    Max_Heap m;
    m.insert(7);
    m.insert(2);
    m.insert(3);
    m.insert(1);
    m.insert(10);
    m.insert(5);
    cout<<m.Heap_size()<<"\n";
    m.print();
   cout<< m.delete_root();
    cout<<"\n"<<m.Heap_size()<<"\n";
    m.print();
    m.insert(12);
    cout<<"\n"<<m.Heap_size()<<"\n";
    m.print();
    return 0;
}
