#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

void test(TestCase test_case, SortingFunction sort, char label[]) {
    sort(test_case.input, test_case.len);

    if (array_eq(test_case.input, test_case.expected, test_case.len)) {
        printf("[%s] Pass\n", label);
    } else {
        char input_str[ARRAY_SIZE * 3] = "";
        array_to_string(test_case.input, test_case.len, input_str);

        char expected_str[ARRAY_SIZE * 3] = "";
        array_to_string(test_case.expected, test_case.len, expected_str);

        printf("[%s] Fail ---- Expected `%s`, got `%s`\n", label, expected_str, input_str);
    }
}
