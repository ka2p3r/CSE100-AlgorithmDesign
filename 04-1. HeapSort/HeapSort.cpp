#include <bits/stdc++.h>
using namespace std;

// To heapify a subtree rooted with node i
void heapify(vector<int>&arr, int n, int i)
{

	// let this be the largest nodes
	int mx = i;

	// left child = 2*i + 1
	int left = 2 * i + 1;

	// right child = 2*i + 2
	int right = 2 * i + 2;

	// If left child is larger than root
	if (left < n && arr[left] > arr[mx])
		mx = left;

	// If right child is larger than largest
	if (right < n && arr[right] > arr[mx])
		mx = right;

	// If largest is not root
	if (mx != i) {
		swap(arr[i], arr[mx]);

		// Recursively heapify the affected
		// sub-tree
		heapify(arr, n, mx);
	}
}

void heapSort(vector<int>&arr, int n)
{

	// building the heap using heapify array (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// extracting element one by one
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);

		// calling heapify again to make sure that it remains a heap after swapping
		heapify(arr, i, 0);
	}
}

int main()
{
	int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

	heapSort(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<";";
    }
}
