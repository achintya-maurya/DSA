// #include <iostream>
// using namespace std;
// int binarySearch(int arr[],int tar,int size){
//     int st = 0;
//     int end = size-1;
//     while(st<=end){
//         int mid = st +(end-st)/2;
//         if(tar > arr[mid]){
//             st = mid +1;
//         }else if (tar< arr[mid])
//         {
//             end = mid-1;
//         }else{
//         return mid;
//         }
        
//     }
//     return -1;
// }
// int main(){
//     int arr[]={1,2,3,4,5,9,12};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int tar = 12;
//     int result = binarySearch(arr,size,tar);
//     if(result!= -1){
//         cout<< "enter found at index:"<<result<<endl;
//     }else{
//         cout << "element not found "<< endl;
//     }
//     return 0;
// }


// binary search using array(HARDCODE)

// #include <iostream>
// using namespace std;

// // Binary search function
// int binarySearch(int arr[], int size, int tar) {
//     int st = 0;
//     int end = size - 1;

//     while (st <= end) {
//         int mid = st + (end - st) / 2;  // safer mid calculation
//         if (tar > arr[mid]) {
//             st = mid + 1;
//         } else if (tar < arr[mid]) {
//             end = mid - 1;
//         } else {
//             return mid;  // found the target
//         }
//     }
//     return -1;  // not found
// }

// int main() {
//     int arr[] = {1, 2, 3, 4, 5, 9, 12,13,15};  // Correct array syntax
//     int size = sizeof(arr) / sizeof(arr[0]);  // Calculate size of array
//     int tar = 4;

//     int result = binarySearch(arr, size, tar);

//     if (result != -1) {
//         cout << "Element found at index: " << result << endl;
//     } else {
//         cout << "Element not found" << endl;
//     }

//     return 0;
// }


// binary search using array using( user choice)

#include<iostream>
using namespace std;
int binarySearch(int arr[],int size, int tar){
    int st = 0;
    int end = size - 1;
    while(st<=end){
        int mid = st + (end-st)/2;
    
    if(tar > arr[mid]){
        st = mid+1;

    }else if(tar< arr[mid]){
        end = mid-1;
    }else{
        return mid;
    }
}
    return -1;
}
int main (){
    int size,i;
    cout<<"enter the size of array:"<<endl;
    cin>>size;
    // int *arr = new int[size];
    int arr[size];
    cout<<"enter "<< size <<"  elements(in sorterd order):"<<endl;
    for(i=0;i<size;i++){
        cin>>arr[i];
    }
    int tar;
    cout<<"enter the element to search:"<<endl;
    cin>>tar;
   int result = binarySearch(arr,size,tar);
   if(result !=-1){
    cout<<"element found at index:"<<result<<endl;
   }else{
    cout<<"element not found !";
   }
   return 0;
}