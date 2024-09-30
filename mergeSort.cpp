// #include<iostream>
using namespace std;


void merge(float array[], int left, int middle,int right){
    int n1 = middle-left+1;
    int n2 = right-middle;

    int *leftArray = new int[n1];
    int *rightArray = new int[n2];

    for(int i=0; i<n1; ++i)
        leftArray[i] = array[left+i];
    for(int i=0; i<n2; ++i)
        rightArray[i] = array[middle+1+i];


    int i=0;    //For left array
    int j=0;    //For right array
    int k=left;     //For main array

    while(i<n1 && j<n2){
        if(leftArray[i]>rightArray[j]){
            array[k] = leftArray[i];
            ++i;
        }
        else{
            array[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    while(i<n1){
        array[k]=leftArray[i];
        ++i;
        ++k;
    }
    while(j<n2){
        array[k]=rightArray[j];
        ++j;
        ++k;
    }

}

void mergeSort(float array[], int left, int right){
    if(left < right){
        int middle = (left + right)/2;
        mergeSort(array,left,middle);
        mergeSort(array,middle+1, right);
        merge(array,left,middle,right);
    }
}

// int main(){
//     int n;
//     cout<<"Enter size of array: ";
//     cin>>n;
//     int array[n];
//     cout<<"Enter Roll No. in array: ";
//     for(int i=0; i<n; ++i)
//         cin>>array[i];
//     int size = sizeof(array) / sizeof(array[0]);

//     mergeSort(array, 0, size-1);
//     for(int i=0;i<size; ++i){
//         cout << array[i] << " ";
//     }
//     cout << endl;
// }