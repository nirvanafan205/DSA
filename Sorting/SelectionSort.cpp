#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr)
{
	// the size of the array
	int n = arr.size();

	// traverse the array
	for(int i = 0; i < n - 1; ++i)
	{
		int minIndex = i;

		// find the minimum element in the remaining unsorted part
		for(int j = i + 1; j < n; ++j)
		{
			if(arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}

		// swap the minmum element with the first element of the unsorted part
		if(minIndex != i)
		{
			swap(arr[i], arr[minIndex]);
		}
	}
}

void print(vector<int>& arr)
{
	for(const auto& num : arr)
	{
		cout << num << " ";
	}
	
	cout << endl;
}

int main()
{
	vector<int> arr = { 64, 25, 12, 22, 11 };

	selectionSort(arr);

	cout << "Sorted array: ";
	print(arr);
}

/*
	Time Complexity: O(n^2)

	It is best used with small data sets as performance 
	is reduced as the number of elements increases

	It also works great with partially sorted arrays 
	or small number of elements out of order

	In general, it is a simple sorting algorithm
*/
