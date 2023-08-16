void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

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
