#include <gtest/gtest.h>
#include "../../DSA/Sorting/BubbleSort.cpp"

// Test case for bubble sort
TEST(BubbleSortTest, SortsArray)
{
        int arr[] = {5, 2, 7, 1, 9};
        int expected[] = {1, 2, 5, 7, 9};

        bubbleSort(arr, sizeof(arr) / sizeof(arr[0]));

        for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        {
                EXPECT_EQ(arr[i], expected[i]);
        }

        // second set of arrays to check 
        int arr2[] = {10, 6, 3, 8};
        int expected2[] = {3, 6, 8, 10};

        bubbleSort(arr2, sizeof(arr2) / sizeof(arr2[0]));

        for(int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
        {
                EXPECT_EQ(arr2[i], expected2[i]);
        }

        // checking for it to fail 
        int arr3[] = {5, 2, 7, 1, 9};
        int expected3[] = {1, 2, 5, 7, 9};

        bubbleSort(arr3, sizeof(arr3) / sizeof(arr3[0]));

        // Intentionally modifying the expected array
        expected3[2] = 10;

        for(int i = 0; i < sizeof(arr3) / sizeof(arr3[0]); i++)
        {
                EXPECT_EQ(arr3[i], expected3[i]);
        }
}

int main(int argc, char** argv)
{
        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}
