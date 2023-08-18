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

// Merges two arrays into a new, sorted one.
void merge(int buf_arr[], int arr1[], int arr1_len, int arr2[], int arr2_len) {
    int buf_i = 0, i1 = 0, i2 = 0;

    while (i1 < arr1_len && i2 < arr2_len) {
        if (arr1[i1] < arr2[i2]) {
            buf_arr[buf_i] = arr1[i1];
            i1++;
        } else {
            buf_arr[buf_i] = arr2[i2];
            i2++;
        }

        buf_i++;
    }

    while (i1 < arr1_len) {
        buf_arr[buf_i] = arr1[i1];
        i1++;
        buf_i++;
    }

    while (i2 < arr2_len) {
        buf_arr[buf_i] = arr1[i2];
        i2++;
        buf_i++;
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

void merge_sort(int arr[], int len) {
    if (len <= 1)
        return;
    
    int mid_i = len / 2;
    int left_i[mid_i];
    int right_i[len - mid_i];
    
    for (int i = 0; i < mid_i; i++)
        left_i[i] = arr[i];
    
    for (int i = mid_i; i < len; i++)
        right_i[i - mid_i] = arr[i];
    
    merge_sort(left_i, mid_i);
    merge_sort(right_i, len - mid_i);
    merge(arr, left_i, mid_i, right_i, len - mid_i);
}
