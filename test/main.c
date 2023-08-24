#include "../sorting.h"
#include "test.h"
#include <stdio.h>

int main(void) {
    TestCase worst_case = {
        .input = {1, 1, 0, -1},
        .expected = {-1, 0, 1, 1},
        .len = 4,
    };

    TestCase best_case = {
        .input = {-1, 0, 1, 1},
        .expected = {-1, 0, 1, 1},
        .len = 4,
    };

    TestCase average_case = {
        .input = {1, 0, -1, 1},
        .expected = {-1, 0, 1, 1},
        .len = 4,
    };

    TestCase cases[] = {worst_case, best_case, average_case};

    for (int i = 0; i < sizeof(cases) / sizeof(cases[0]); i++) {
        test(cases[i], bubble_sort, "BubbleSort");
        test(cases[i], selection_sort, "SelectionSort");
        test(cases[i], insertion_sort, "InsertionSort");
        test(cases[i], merge_sort, "MergeSort");
        test(cases[i], quick_sort, "QuickSort");
    }

    TestCase unsigned_case = {
        .input = {1, 0, 2, 1},
        .expected = {0, 1, 1, 2},
        .len = 4,
    };

    // Those sorting algorithms only work with unsigned integers.
    test(unsigned_case, counting_sort, "CountingSort");
    test(unsigned_case, bucket_sort, "BucketSort");
}
