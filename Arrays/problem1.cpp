// Code for moving all zeroes to end

#include <iostream>

using namespace std;

void moveZero(int arr[], int size){
    int index = 0;
    for(int i=0; i<size; i++){
        if(arr[i]!=0){
            arr[index++]=arr[i];
        }
    }

    while(index<size){
        arr[index++]=0;
    }
}

int main(){
    int arr[] = {0, 1, 2, 0, 0, 5, 12, 0, 3, 8, 0, 0, 0, 11, 6};

    int size = sizeof(arr)/sizeof(arr[0]);

    moveZero(arr, size);

    cout << "Array after moving zeroes to the end:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}