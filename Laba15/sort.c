void SelectSort(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) { 
            if (students[j].total < students[minIndex].total) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            struct Student temp = students[i];
            students[i] = students[minIndex];
            students[minIndex] = temp;
        }
    }
}

// comment