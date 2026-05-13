#include <stdio.h>
int n;
int p[10], dir[10];

void printPerm()
{
    for (int i = 0; i < n; i++)
        printf("%d ", p[i]);
    printf("\n");
}

int largestMobile()
{
    int mobile = 0;
    for (int i = 0; i < n; i++){
        if (dir[i] == -1 && i != 0 && p[i] > p[i - 1]){
            if (p[i] > mobile)
                mobile = p[i];
        }
        if (dir[i] == 1 && i != n - 1 && p[i] > p[i + 1]){
            if (p[i] > mobile)
                mobile = p[i];
        }
    }
    return mobile;
}
int main()
{
    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        p[i] = i + 1;
        dir[i] = -1;
    }
    printPerm();
    while (1){
        int mobile = largestMobile();
        if (mobile == 0)
            break;
        int pos;
        for (int i = 0; i < n; i++){
            if (p[i] == mobile){
                pos = i;
                break;
            }
        }
        int newPos = pos + dir[pos];

        int temp = p[pos];
        p[pos] = p[newPos];
        p[newPos] = temp;

        temp = dir[pos];
        dir[pos] = dir[newPos];
        dir[newPos] = temp;

        for (int i = 0; i < n; i++)
        {
            if (p[i] > mobile)
                dir[i] = -dir[i];
        }
        printPerm();
    }
    return 0;
}
