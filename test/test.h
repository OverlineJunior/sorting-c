#define ARRAY_SIZE 64

typedef void (*SortingFunction)(int arr[], int len);

typedef struct {
    int input[ARRAY_SIZE];
    int expected[ARRAY_SIZE];
    int len;
} TestCase;

void test(TestCase test_case, SortingFunction sort, char label[]);
