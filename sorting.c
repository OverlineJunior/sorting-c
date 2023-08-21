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
