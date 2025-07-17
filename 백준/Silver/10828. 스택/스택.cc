#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {   
    int cmd, num;
    char str[6];
    scanf("%d", &cmd);

    int size = 0;
    int idx = 0;
    int arr[10001];

    for (int i = 0; i < cmd; i++) {
        scanf("%s", str);

        if (strstr(str, "push") != NULL) {
            scanf("%d", &num);
            arr[idx] = num;
            idx++;
            size++;

        }

        if (strcmp(str, "pop") == 0) {
            if (idx == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", arr[idx-1]);
                idx--;
                size--;
            }
        }

        if (strcmp(str, "top") == 0) {
            if (idx == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", arr[idx-1]);
            }
        }

        if (strcmp(str, "empty") == 0) {
            if (size > 0) {
                printf("0\n");
            } else if (size == 0) {
                printf("1\n");
            }
        }

        if (strcmp(str, "size") == 0) {
            printf("%d\n", size);
        }
    }
}