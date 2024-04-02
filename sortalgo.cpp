#include <bits/stdc++.h>
using namespace std;
#define ll long long
void insertion_sort(int arr[],int n){
    for (int i = 1,j; i <n ; ++i) {
        int temp=arr[i];
        for ( j = i; j >0&&temp<arr[j-1] ; --j) {
            arr[j]=arr[j-1];
        }
        arr[j]=temp;
    }
}
void bubble_sort(int arr[],int n){
    for (int i = 0; i < n-1; ++i) {
        int move=0;
        for (int j = 1; j <n-i ; ++j) {
            if (arr[j]<arr[j-1]) {
                swap(arr[j], arr[j - 1]);
                move++;
            }
        }
        if (!move)
            break;
    }
}
void selection_sort(int arr[],int n){
    for (int i = 0; i <n-1 ; ++i) {
        int mn=i;
        for (int j = i+1; j <n ; ++j) {
            if (arr[j]<arr[mn])
                mn=j;
        }
        swap(arr[i],arr[mn]);
    }
}
void shell_sort(int arr[],int n){
    for (int g = n/2; g>0 ; g/=2) {
        for (int i = g,j; i <n ; ++i) {
            int t=arr[i];
            for ( j = i; j >0&&t<arr[j-g] ; j-=g) {
                arr[j]=arr[j-g];
            }
            arr[j]=t;
        }

    }
}
void merg(int arr[],int l,int m,int r){
    int n1 = m-l + 1;
    int  n2 =r-m;
    int  L[n1], R[n2];
    for (int i = 0; i <n1 ; ++i) {
        L[i]=arr[l+i];
    }
    for (int i = 0; i <n2 ; ++i) {
        R[i]=arr[m+i+1];
    }
    int i=0,j=0,k=l;
    while (i<n1&&j<n2){
        if (L[i]<=R[j]){
            arr[k++]=L[i++];
        }
        else
            arr[k++]=R[j++];
    }
    while (i<n1){
        arr[k++]=L[i++];
    }
    while (j<n2){
        arr[k++]=R[j++];
    }
}
void merge_sort(int arr[],int l,int r){
    if (l>=r)
        return;
    else{
        int m=(l+r)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merg(arr,l,m,r);
    }
}
int partition(int arr[],int l,int r){
    int i=l;
    for (int j = i+1; j <=r ; ++j) {
        if (arr[j]<arr[l]){
            swap(arr[j],arr[++i]);
        }
    }
    swap(arr[l],arr[i]);
    /*  for (int x = 0; x <=r ; ++x) {
          cout<<arr[x]<<" ";
      }
      cout<<'\n';*/
    return i;

}
void quick_sort(int arr[],int l,int r){
    if (l>=r)
        return;
    else{
        int m= partition(arr,l,r);
        quick_sort(arr,l,m-1);
        quick_sort(arr,m+1,r);
    }
}
void count_sort(int arr[],int n,int mx){
    vector<int>freq(mx+1,0);
    int temp[n];
    copy((arr),(arr+n),(temp));
    for (int i = 0; i <n ; ++i) {
        freq[arr[i]]++;
    }
    for (int i = 1; i <=mx ; ++i) {
        freq[i]+=freq[i-1];
    }
    for (int i = n-1; i >=0 ; --i) {
        arr[--freq[temp[i]]]=temp[i];
    }
}
int main() {
int arr[5]={4,1,2,5,3};
    bubble_sort(arr,5);
    return 0;
}
