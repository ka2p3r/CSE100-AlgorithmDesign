# include<bits/stdc++.h>
using namespace std;

//all smaller elements (smaller than pivot)
//are placed left of pivot and all greater
// elements to right of pivot
int partition(vector<int>&arr, int l, int h)
{
	// pivot
	int pivot = arr[h];
	
	// Index of smaller element
	int i = (l - 1);

	for (int j = l; j < h; j++)
	{
		// If current element is smaller
		// than or equal to pivot
		if (arr[j] <= pivot) {

			// increment index of
			// smaller element
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[h]);
	return (i + 1);
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
int helper(vector<int>&arr, int l, int h)
{
	//for getting a random number in between the l and h indicies
	srand(time(NULL));
	int random = l + rand() % (h - l);

	swap(arr[random], arr[h]);

    //calling the utility function for merging
	return partition(arr, l, h);
}

// this is the quickSort function
void quickSort(vector<int>&arr, int l, int h)
{
	if (l < h) {

		//pivot is the partiontioning index here
		int pivot = helper(arr, l, h);

		//applying quick sort for the two parts ercursively
		quickSort(arr, l, pivot - 1);
		quickSort(arr, pivot + 1, h);
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
	quickSort(arr, 0, n - 1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<";";
    }
}
