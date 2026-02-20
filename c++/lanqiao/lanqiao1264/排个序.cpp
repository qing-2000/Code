
#include <stdio.h>
int jiang(int a[], int n) {
    int i;
    for (i = 1; i < n; i++) {
        if (a[i] < a[i + 1]) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int n, m;
    scanf_s("%d%d", &n, &m);
    int a[1010], p[1010];
    int i, j, k = 0;
    for (i = 1; i <= n; i++) {
        scanf_s("%d", &a[i]);
    }
    for (i = 1; i <= m; i++) {
        scanf_s("%d", &p[i]);
    }
    for (i = 1; i <= m - 1; i++) {
        for (j = 1; j <= m - i; j++) {
            if (a[p[i]] < a[p[i] + 1]) {
                k = a[p[i]];
                a[p[i]] = a[p[i + 1]];
                a[p[i + 1]] = k;
            }
        }
    }
    if (jiang(a, n) != 0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}