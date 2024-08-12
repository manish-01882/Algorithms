#include<iostream>
using namespace std;

int partition(int array[], int l, int r){
    int p = array[r];
    int i= l-1;
    for(int j=l; j<=r-1; ++j){
        if(array[j] <= p){
            ++i;
            swap(array[i],array[j]);
        }
    }
    swap(array[i+1],array[r]);
    return i+1;
}

void quickSort(int array[], int l, int r){
    if (l>=r)
        return;
    int m = partition(array,l,r);
    quickSort(array,l,m -1);
    quickSort(array,m+1,r);
    

}
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int array[n];
    cout<<"Enter Roll No. in array: ";
    for(int i=0; i<n; ++i)
        cin>>array[i];

    int size = sizeof(array) / sizeof(array[0]);
    quickSort(array,0,size-1);
    for(int i=0; i<size; ++i){
        cout<<array[i]<< " ";
    }
    cout << endl;
}