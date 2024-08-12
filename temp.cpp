#include<iostream>

using namespace std;


int main(){
    int k=10;
    for (int i = k/2-1; i >= 1; i--) {
        for (int j = i; j >= 1; j--){
            cout << k << " ";
            k = k-1;
        }
        cout << endl;
    }

 }
