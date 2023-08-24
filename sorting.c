#include <stdlib.h>

// TODO! Bucket size should be dynamic, based on arr.len. A solution to it is using a linked list instead.
#define BUCKET_SIZE 10

typedef struct {
    int elements[BUCKET_SIZE];
    int len;
} Bucket;

void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

// Returns the index of the smallest element.
int smallest_index(int arr[], int len, int starting_index) {
    int n = arr[starting_index];
    int index = starting_index;

    for (int i = starting_index; i < len; i++)
        if (arr[i] < n) {
            n = arr[i];
            index = i;
        }

    return index;
}

void merge(int arr[], int left_i, int mid_i, int right_i) {
    int left_len = mid_i - left_i + 1;
    int right_len = right_i - mid_i;

    int left[left_len], right[right_len];

    for (int i = 0; i < left_len; i++)
        left[i] = arr[left_i + i];

    for (int j = 0; j < right_len; j++)
        right[j] = arr[mid_i + 1 + j];

    int i = 0;
    int j = 0;
    int k = left_i;

    while (i < left_len && j < right_len) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }

        k++;
    }

    while (i < left_len) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < right_len) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void bubble_sort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void selection_sort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++)
        swap(&arr[i], &arr[smallest_index(arr, len, i)]);
}

void insertion_sort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        if (arr[i] > arr[i + 1])
            swap(&arr[i], &arr[i + 1]);

        // From i + 1 to 1, swap everything out of order.
        for (int j = i + 1; j > 0; j--)
            if (arr[j - 1] > arr[j])
                swap(&arr[j - 1], &arr[j]);
    }
}

void merge_sort_(int arr[], int left_i, int right_i) {
    if (left_i >= right_i)
        return;

    int mid_i = left_i + (right_i - left_i) / 2;

    merge_sort_(arr, left_i, mid_i);
    merge_sort_(arr, mid_i + 1, right_i);

    merge(arr, left_i, mid_i, right_i);
}

void merge_sort(int arr[], int len) {
    merge_sort_(arr, 0, len - 1);
}

// Assuming pivot is the last element, place elements greater than pivot after it and smaller than pivot before it.
// Returns the pivots index after the changes.
int partition(int arr[], int start_i, int end_i) {
    int pivot_i = end_i;

    for (int i = start_i; i < pivot_i; i++)
        if (arr[i] > arr[pivot_i]) {
            swap(&arr[i], &arr[pivot_i - 1]);
            swap(&arr[pivot_i - 1], &arr[pivot_i]);
            pivot_i--;

            // Dont skip this iteration because its new value after swap might be greater than the pivot.
            i--;
        }

    return pivot_i;
}

void quick_sort_(int arr[], int start_i, int end_i) {
    if (start_i >= end_i)
        return;

    int pivot_i = partition(arr, start_i, end_i);

    quick_sort_(arr, start_i, pivot_i - 1);
    quick_sort_(arr, pivot_i + 1, end_i);
}

void quick_sort(int arr[], int len) {
    quick_sort_(arr, 0, len - 1);
}

void counting_sort(int arr[], int len) {
    int max = arr[0];

    for (int i = 0; i < len; i++)
        if (arr[i] > max)
            max = arr[i];

    int counter_len = max + 1;
    int counter[counter_len];

    for (int i = 0; i < counter_len; i++)
        counter[i] = 0;

    for (int i = 0; i < len; i++)
        counter[arr[i]]++;

    int i = 0;

    for (int n = 0; n < counter_len; n++)
        for (int _j = 0; _j < counter[n]; _j++) {
            arr[i] = n;
            i++;
        }
}

void bucket_sort(int arr[], int len) {
    int max = arr[0], min = arr[0];

    for (int i = 0; i < len; i++) {
        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)
            min = arr[i];
    }

    int buckets_len = (max - min) / BUCKET_SIZE + 1;
    Bucket buckets[buckets_len];

    for (int i = 0; i < buckets_len; i++)
        buckets[i].len = 0;

    // Scatter.
    for (int i = 0; i < len; i++) {
        int bucket_i = arr[i] / BUCKET_SIZE;
        buckets[bucket_i].elements[buckets[bucket_i].len] = arr[i];
        buckets[bucket_i].len++;
    }

    int arr_i = 0;

    // Gather.
    for (int i = 0; i < buckets_len; i++) {
        Bucket bucket = buckets[i];
        quick_sort(bucket.elements, bucket.len);

        for (int j = 0; j < bucket.len; j++) {
            arr[arr_i] = bucket.elements[j];
            arr_i++;
        }
    }
}
