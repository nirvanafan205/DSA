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
}

int main(int argc, char** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
