# include<bits/stdc++.h>
using namespace std;

void helper(vector<int>&arr, int s, int e){
    if(s==e){
        return;
    }
    //divide
    int mid = (s+e)/2;
    //left half
    helper(arr, s, mid);

    //right half
    helper(arr, mid+1, e);

    //merge
    vector<int>temp;
    int i=s, j=mid+1;
    while(i<=mid and j<=e){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]); //if left side array size is offset
        i++;
    }
    while(j<=e){ //if right side array is offset 
        temp.push_back(arr[j]);
        j++;
    }
    int k=0;
    for(int l=s;l<=e;l++){
        arr[l]=temp[k];
        k++;
    }
}
//main function to loop and print output 
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    helper(arr, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<";";
    }
}
