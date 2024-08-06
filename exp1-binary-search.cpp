#include <iostream>
using namespace std;
int binary_search(int arr[], int beg, int end, int value){
    while (beg <= end){
        int mid = (beg + (end - beg) / 2);
        if (arr[mid] == value){
            return mid;
        }
        else if (value > arr[mid]){
            beg = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter Roll No. in array: ";
    for(int i=0; i<n; ++i)
        cin>>arr[i];
    int ele;
    char c = 'y';
    while(c == 'y' || 'Y'){
        cout <<"Roll no. to find: ";
        cin >> ele;
        int pos = binary_search(arr, 0, n - 1, ele);

        if (pos != -1)
            cout << "Roll No. is present at location: " << pos << endl;
        else
            cout << "Roll No. not found!";
        cout << "Do you want to continue?(y/n): ";
        cin >> c;
        cout << "\n\n\n\n";
    }
    
}