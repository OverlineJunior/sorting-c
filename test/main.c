#include "../sorting.h"
#include "test.h"

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
    }   
}
