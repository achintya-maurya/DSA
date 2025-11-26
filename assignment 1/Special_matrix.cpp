#include<iostream>
using namespace std;
int main(){
    int i,j,n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    int arr[n];

    cout<<"enter array elements:"<<endl;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
     cout<<"Diagonal Matrix:"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
               cout<<arr[i]<<" ";
            }else{
                cout<<"0"<<" ";
            }
        }
        cout<<"\n";
    }
   
    return 0;
}