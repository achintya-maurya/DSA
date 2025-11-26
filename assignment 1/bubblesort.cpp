// #include<iostream>
// using namespace std;
// void bubble_sort(int arr[],int n){
//     int i,j,temp;
//     for(i=0;i<n-1;i++){
//         for(j=0;j<n-i-1;j++){
//             if(arr[j]>arr[j+1]){
//                 temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }


// }
// int main(){
//     int i,n;
//     cout<<"enter the size of array:"<<endl;
//     cin>>n;
//     int arr[n];
//     cout<<"enter "<< n <<" elements:"<<endl;
//     for(i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     bubble_sort(arr,n);
//     cout<<"sorted array:";
//     for(i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

#include<iostream>
using namespace std;
void bubble_sort(int arr[],int n){
    int i, j, temp;
    for(i = 0; i <n ; i++){
        for(j= 0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
}
int main(){
    int n,i;
    cout<<"enter the size of array:"<< endl;
    cin>>n;
    int arr[n];
    cout<<"enter " << n<<" elements"<<endl;
    for(i = 0;i<n;i++){
        cin>>arr[i];
    }
    bubble_sort(arr,n);
    cout<<"sorted array:";
      for(i = 0;i<n;i++){
        cout<<arr[i]<<" ";
     
    }
    return 0;
    }
