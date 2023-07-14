#include<bits/stdc++.h>
using namespace std;
int mx=4;

void counting_helper(vector<vector<int>>&arr, int n, int pos){
    //since all elements can be 0-3, using a count vector to store their occurrences
    vector<int>count(4);
    int i;
    vector<vector<int>>res(n, vector<int>(10));
  
    //saving the count
    for (i = 0; i < n; i++) {
        count[arr[i][pos] % mx]++;
    }

    //prefixing the count vector
    for (i = 1; i < mx; i++) {
        count[i] += count[i - 1];
    }

    //sorting it 
    for (i = n - 1; i >= 0; i--) {
        int idx=count[arr[i][pos]%mx] - 1;
        res[idx] = arr[i];
        count[arr[i][pos] % mx]--;
    }

    //saving the result
    for (i = 0; i < n; i++)
        arr[i] = res[i];
}
//for calling the counting sort algo from lsb to msb
void radix(vector<vector<int>>&arr, int n) {
    for (int i = 9; i >= 0 ; i--) {
        //going from the 10 the position to 1st
        counting_helper(arr, n, i);
    }
}

int main(){
	int n;
    cin >> n;
    
    vector<vector<int>>arr(n, vector<int>(10));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cin>>arr[i][j];
        }
    }

    radix(arr, n);

    for (int i = 0; i < n; i++) {
        for(int j=0;j<10;j++){
            cout<<arr[i][j]<<";";
        }
        cout <<'\n';
    }
}