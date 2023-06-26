#include <iostream>

using namespace std;

// get the maximum element in the array
int getMax(const int arr[], int n)
{
	int maxVal = arr[0];

	for(int i = 1; i < n; ++i)
	{
		if(arr[i] > maxVal)
		{
			maxVal = arr[i];
		}
	}

	return maxVal;

	/*
		Traverses array once
	       	compares each elements with current max value
       		updates max value if larger value is found
		returns maximum value in the array
	*/
}

// performs counting sort based on a particular digit
void countingSort(vector<int>& arr, int exp)
{
	const int n = arr.size();
	vector<int> count(10, 0);
	vector<int> output(n, 0);

	// Count the occurrences of each digit)
	for(int i = 0; i < n; ++i)
	{
		int digit = (arr[i] / exp) % 10;
		count[digit]++;
	}

	// Calculate cumulative counts
	for(int i = 1; i < 10; ++i)
	{
		count[i] += count[i - 1];
	}

	// build the sorted output array 
	for(int i = n - 1; i >= 0; --i)
	{
		int digit = (arr[i] / exp) % 10;
		output[count[digit] - 1] = arr[i];
		count[digit]--;
	}

	// update the original array with the sorted elements
	for(int i = 0; i < n; ++i)
	{
		arr[i] = output[i];
	}
}

// perform radix sort
void radixSort(vector<int>& arr)
{
	int maxVal = getMax(arr);

	// perform counting sort for each digit
	for(int exp = 1; maxVal / exp > 0; exp *= 10)
	{
		countingSort(arr, exp);
	}
}

int main()
{
	cout << "Hello World" << endl;
}
