//Hao D Mai
//CSE 100  
//Lab01 Insertion sort 
//9.20.22

# include<iostream> 
using namespace std;

int main(){
    int n;
    cin>>n;
    //Creating variable n as numbers of inputs 
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //insertion sort beginning sort at second index
    for(int i=1;i<n;i++){
        int e=arr[i];
        int j=i-1;
        while(j>=0 and arr[j]>e){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=e;
    //loop to accout for each sorting iteration
        for(int k=0;k<=i;k++){
            cout<<arr[k]<<";";
        }
        cout<<endl;
    }
}