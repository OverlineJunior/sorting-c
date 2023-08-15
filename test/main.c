#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../sorting.h"

#define ARRAY_SIZE 64

typedef void (*SortingFunction)(int arr[], int len);

typedef struct {
    int input[ARRAY_SIZE];
    int expected[ARRAY_SIZE];
    int len;
} TestCase;

bool array_eq(int arr1[], int arr2[], int len) {
    for (int i = 0; i < len; i++)
        if (arr1[i] != arr2[i])
            return false;

    return true;
}

void array_to_string(int arr[], int len, char buffer[]) {
    strcat(buffer, "[");

    for (int i = 0; i < len; i++) {
        char num_str[] = ";";
        sprintf(num_str, "%i", arr[i]);

        strcat(buffer, num_str);

        if (i != len - 1)
            strcat(buffer, ", ");
    }

    strcat(buffer, "]");
}

void test(TestCase test_case, SortingFunction sort) {
    sort(test_case.input, test_case.len);

    if (array_eq(test_case.input, test_case.expected, test_case.len)) {
        printf("Pass\n");
    } else {
        char input_str[ARRAY_SIZE * 3] = "";
        array_to_string(test_case.input, test_case.len, input_str);

        char expected_str[ARRAY_SIZE * 3] = "";
        array_to_string(test_case.expected, test_case.len, expected_str);

        printf("Fail ---- Expected `%s`, got `%s`\n", expected_str, input_str);
    }
}

int main(void) {
    TestCase case1 = {
        .input = {5, 4, 3, 2, 1},
        .expected = {1, 2, 3, 4, 5},
        .len = 5,
    };

    test(case1, bubblesort);
}
