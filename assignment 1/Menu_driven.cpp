#include<iostream>
using namespace std;
void createArray(int arr[],int&n){
    int i;
    cout<<"Enter number of elements:";
    cin>>n;
    cout<<"Enter Elements:\n";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }

}
 void displayArray(int arr[],int n){
        if(n==0){
            cout<<"Array is empty\n";
            return;
        }
        cout<<"array elements:";
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

 void insertElement(int arr[],int &n){
        int pos,ele;
        cout<<"Enter Position to insert( 1 to"<<n+1 <<"):";
        cin>>pos;
        if(pos<1||pos>n+1){
            cout<<"Invalid position\n";
            return;
        }
        cout<<"enter element to insert:";
        cin>>ele;
        for(int i=n;i>=pos-1;i--){
            arr[i]=arr[i-1];
        }
        arr[pos-1] = ele;
        n++;
    }

void deleteArray(int arr[],int &n){
        int pos;
        cout<<"Enter position to delete( 1 to "<<n<<"):";
        cin>>pos;
        if(pos<1||pos>n){
            cout<<"Invalid position\n";
            return;
        }
        for(int i = pos-1;i<n-1;i++){
            arr[i]=arr[i+1];
        }
        n--;
    }
 void linearSearch(int arr[],int n){
        int ele,found =-1;
        cout<<"enter element to search:";
        cin>>ele;
        for(int i=0;i<n;i++){
            if(arr[i]==ele){
                found = i;
                break;
            }
        }
        if(found !=-1)
            cout<<"element found at position:"<<found +1 <<"\n";
        else 
            cout << "element not found\n";
              
    }
 void bubbleSort(int arr[],int n){
        for(int i=0;i<n;i++){
            for(int j =0;j-i-1;j++){
                if(arr[j]>arr[j+1]){
                    int temp = arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]= temp;
                }
            }
        }
        cout<<"array sorted in ascending order\n";
    }
void binarySearch(int arr[],int n){
        int ele;
        cout<<"enter element to search(array must be sorted):";
        cin>>ele;
        int low =0, high=n-1, mid, found=-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(arr[mid]==ele){
                found = mid;
                break;
            }else if(arr[mid]<ele){
                low=mid+1;
            }else{
                high = mid-1;
            }
        }
        if(found !=-1)
            cout<<"element found at position:" << found+1<<"\n";
        else
        cout<<"Element not found\n";


    }
    int main(){
        int arr[100];
        int n=0;
        int choice;
          do {
        cout << "\n=== Array Operations Menu ===\n";
        cout << "1. Create\n";
        cout << "2. Display\n";
        cout << "3. Insert\n";
        cout << "4. Delete\n";
        cout << "5. Linear Search\n";
        cout << "6. Bubble Sort\n";
        cout << "7. Binary Search\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1: createArray(arr,n);
        break;
        case 2: displayArray(arr,n);
        break;
         case 3: insertElement(arr, n); 
         break;
         case 4: deleteArray(arr, n); 
         break;
         case 5: linearSearch(arr, n); 
         break;
         case 6: bubbleSort(arr, n); 
         break;
         case 7: binarySearch(arr, n);
          break;
         case 8: cout << "Exiting...\n";
          break;
         default: cout << "Invalid choice!\n";
        
        }
    }
        while(choice !=8);
        return 0;
    }