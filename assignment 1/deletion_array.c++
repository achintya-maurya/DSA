// #include<iostream>
// using namespace std;
// int main(){  
//     int n,i,ele;
//     cout<<"enter the size of array:\n";
//     cin>>n;
//     int arr[n];
//     cout<<"enter array elements"<<endl;
//     for(i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     cout<<"after insertion:"<<endl;
//     for(i=0;i<n;i++){
//         cout<<arr[i]<<" "<<endl;
//     }
//     cout<<"select index number to delete from 0 to"<< n-1<<endl;
//     cin>>ele;
//     if(ele<0 || ele>n){
//         cout<<"invalid index"<<endl;
//         return 1;
//     }
//     for(i=ele;i<n-1;i++){
//         arr[i]=arr[i+1];
//     }
//     n--;
//     cout<<"after deletion"<<endl;
//     for(i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }


///////////////////////////////////////////////////// find the largest value in array 
// #include<iostream>
// using namespace std;
// int main(){
//     int i,n;
//     cout<<"enter the size of array"<<endl;
//     cin>>n;
//     int arr[n];
//     cout<<"enter array elements"<<endl;
//     for(i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int max_number = arr[0];
//     for(i=1;i<n;i++){
//         if(max_number<arr[i]){
//             max_number=arr[i];
//         }
//     }
//     cout<<"largest element in array is :"<<max_number<<endl;
//     return 0;
// }

///////////////////////////////////////////////////////find the smallest elemnet in the array
// #include<iostream>
// using namespace std;
// int main(){
//     int i,n;
//     cout<<"enter the size of array:"<<endl;
//     cin>>n;
//     int arr[n];
//     cout<<"enter array element:"<<endl;
//     for(i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int min_number=arr[0];
//     for(i=0;i<n;i++){
//         if(arr[i]<min_number){
//             min_number=arr[i];
//         }
//     }
// cout<<"min element in array :"<<min_number<<endl;

// }


// #include<iostream>
// using namespace std;
// int main(){
//     int i,n;
//     cout<<"enter the size of array"<<endl;
//     cin>>n;
//     int arr[n];
//     cout<<"enter the elements of array"<<endl;
//     for(i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int pos;
//     cout<<"select the position to add a new number:"<<endl;
//     cin>>pos;
//     int ele;
//     cout<<"enter new element:"<<endl;
//     cin>>ele;
//     for(i=n-1;i>=pos-1;i--){
//         arr[i+1]=arr[i];
//     }
//     arr[pos-1]=ele;
//     n++;
//     cout<<"array after insertion"<<endl;
//     for(i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }

#include<iostream>
using namespace std;
int main(){
    int i,n;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the elements of array"<<endl;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    int pos;
    cout<<"select the position to delete the number:"<<endl;
    cin>>pos;
    if(pos<0 ||pos>n){
        cout<<"invalid number:"<<endl;
    }
    for(i=pos;i<n;i++){
        arr[i-1]=arr[i];
    }

    n--;
    cout<<"array after deletion"<<endl;
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}