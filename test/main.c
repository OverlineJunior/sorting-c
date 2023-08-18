#include "../sorting.h"
#include "test.h"

int main(void) {
    TestCase case1 = {
        .input = {5, 4, 3, 2, 1},
        .expected = {1, 2, 3, 4, 5},
        .len = 5,
    };

    test(case1, bubble_sort, "BubbleSort");
    test(case1, selection_sort, "SelectionSort");
    test(case1, insertion_sort, "InsertionSort");
    test(case1, merge_sort, "MergeSort");
}
