#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of array:\n";
    cin>>n;
    int arr[n];
    cout<<"Enter " << n <<" element"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int distinctcount=0;
    cout<<"Distinct elements are:\n";
    for(int i=0;i<n;i++){
        int j;
        for( j=0;j<i;j++){
            if(arr[i]==arr[j]){
                break;
            }
        }
            if( j == i){
                cout<<arr[i]<<" ";
                distinctcount++;
        }
    }
    cout << "\nTotal number of distinct elements: " << distinctcount << endl;
    return 0;
}
