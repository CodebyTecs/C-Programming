struct Student {
    char name[64];
    int math;
    int phy;
    int inf;
    int total;
};

struct Student addStudent(char *name, int math, int phy, int inf);
void printStudentInfo(struct Student students[], int n);
void SelectSort(struct Student students[], int n);
void CountingSort(struct Student students[], int n);
int partition(struct Student students[], int l, int r);
void QuickSort(struct Student students[], int l, int r);

