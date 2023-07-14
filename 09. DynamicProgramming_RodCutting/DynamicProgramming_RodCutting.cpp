#include <limits.h>
#include <iostream>
using namespace std;
void extendedBottomUpCutRod(int* pSeq, int n)// input of form p1,p2,p3,p4,p5,...pn
{ 
    int* rn = new int[n+1]; //maximum revanue represented by rn
    int* F = new int[n+1];
    rn[0] = 0;
    int q =INT_MIN;
    for(int j = 1; j < n; j++)  // for loop for getting maximum revenue
	{
        q=INT_MIN;
        for(int i = 1; i <= j; i++)
		{
            if(q< pSeq[i] + rn[j-i]){
                q = pSeq[i] + rn[j-i]; // conditions for getting maximum revenue
                F[j] = i; 
            }
        }
        rn[j] = q;
    }  
    n = n - 1; // getting r values
    cout << rn[n] << endl;
    while(n > 0)// Here we getting output with space represented by F here
	{
        cout << F[n] << " ";
        n = n-F[n];
    }
    cout << "-1" << endl;  // -1 is multiplied by enter 
}
int main()
{
    int n;
    cin >> n;   
    int* pSeq = new int[n + 1]; // input the p sequance one by one in new line
    pSeq[0] = 0;
    for(int i = 1; i < n + 1; i++){
        cin >> pSeq[i];
    }
    extendedBottomUpCutRod(pSeq, n+1);
    return 0;
}