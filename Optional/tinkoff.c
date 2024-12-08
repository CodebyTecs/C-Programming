#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int numbers[100000];
    int count = 0;

    char res[] = "1";

    char *interval = strtok(res, ",");
    while (interval != NULL)
    {
        char *dash = strchr(interval, '-');
        if (dash)
        {
            int start = atoi(interval);
            int end = atoi(dash + 1);

            for (int i = start; i <= end; i++)
            {
                numbers[count] = i;
                count++;
            }
        }
        else
        {
            numbers[count] = atoi(interval);
            count++;
        }

        interval = strtok(NULL, ",");
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d", numbers[i]);
        if (i < count - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}
