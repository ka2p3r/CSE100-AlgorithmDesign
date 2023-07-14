#include<iostream>

using namespace std;
int main() {
    int n; // denotes no. of inputs
    int sequence = 0; // represt. inputs from user
    int int_max =0; // initialize both min and max as reference point of comparsions via sequence input from user 
    int int_min = 0; 
    
    //denotes how many input values the sequence will consist of
    cin>>n; 

    // creating a loop to compare values assigned to the sequence inputs 
    for (int i = 0; i < n; i ++) {
        cin >> sequence;
        
        //if iteration is 0 then int_max and int_min are subset of input values within sequence 
        if (i==0) {
            int_min = sequence;
            int_max = sequence;
        }

        else if (int_min > sequence) { // loop condition to search for min and max 
            int_min = sequence; 
        }
        else if (int_max < sequence) { 
            int_max = sequence;
        }

    }
    //print the max intrger and min integer seperate by a semicolon && end of code 
    cout<<int_max<<";"<<int_min<<endl; 
    return 0; 

}