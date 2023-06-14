#include <iostream>

using namespace std; 

void bubbleSort(int arr[], int size)
{
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				// swap arr[j] and arr[j + 1]
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int arr[] = { 5, 2, 8, 12, 1, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Original Array: ";

	// print array
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	// call function to sort array
	bubbleSort(arr, size);

	// print sorted array
	cout << "\nSorted array: ";

	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	/*
		Bubble Sort has a worst-case and average0case time complexity of O(n^2)
		where "n" is the number of elements in the array to be sorted.
		The time it takes to sort the array increases quadratically as 
		the number of elements increases.

		Useful for small datasets and to understand sorting concepts

	*/ 
}
