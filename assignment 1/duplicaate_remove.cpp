#include<iostream>
using namespace std;
int main(){
    int i,j,k,n;
    cout<<"Enter the size of array:\n";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements:\n";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                for(k=j;k<n-1;k++){
                    arr[k]=arr[k+1];
                }
                n--;
                j--;
            }

        }
    }cout<<"array after removal of duplicate elements:\n";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}