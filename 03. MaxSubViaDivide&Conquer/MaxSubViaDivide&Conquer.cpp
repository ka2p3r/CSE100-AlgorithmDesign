#include<bits/stdc++.h>
using namespace std;

int containSum(vector<int>&arr, int l, int mid, int h)
{
	int curr = 0, ls=INT_MIN, rs=INT_MIN;
    for (int i = mid; i <= h; i++) {
		curr += arr[i];
		if (curr > rs)
			rs = curr;
	}

	curr = 0;
    for (int i = mid; i >= l; i--) {
		curr += arr[i];
		if (curr > ls)
			ls = curr;
	}
	
    int op = ls+rs-arr[mid];
	return max(op, max(ls, rs));
}

int helper(vector<int>&arr, int l, int h)
{
    int mid = (l + h) / 2;

	if (l > h)
		return INT_MIN;

	if (l == h)
		return arr[l];

    int op1 = helper(arr, l, mid-1);
    int op2 = helper(arr, mid+1, h);
    int op3 = containSum(arr, l, mid, h);
    return max(op1, max(op2, op3));
}

int main()
{
	int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = helper(arr, 0, n-1);
    cout<<ans;
}