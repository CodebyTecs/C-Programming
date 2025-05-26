#define MAX 300

struct Student {
    char name[64];
    int math;
    int phy;
    int inf;
    int total;
};

struct Student addStudent(const char* name, int math, int phy, int inf);
void CountingSort(int n, struct Student *students);
void SelectionSort(struct Student arr[], int size);
void quicksort(struct Student arr[], int low, int high);
void printPerson(struct Student p);
void CpuInfo();
