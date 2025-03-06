void SelectSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) { 
            if (a[j]< a[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

int main() {
    int a[] = {4, 2};
    int n = 2;

    SelectSort(a, n);
}