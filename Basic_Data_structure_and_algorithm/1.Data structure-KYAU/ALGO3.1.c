#include <stdio.h>
#include <string.h>

void deletePattern(char *T, const char *P) {
    int K = strstr(T, P) - T; 

    while (K >= 0) {
        memmove(&T[K], &T[K + strlen(P)], strlen(T) - K - strlen(P) + 1);
        K = strstr(T, P) - T;  
    }
}
int main() {
    char T[1000], P[100];

    printf("Enter text T: ");
    fgets(T, sizeof(T), stdin);
    T[strcspn(T, "\n")] = '\0';

    printf("Enter pattern P: ");
    fgets(P, sizeof(P), stdin);
    P[strcspn(P, "\n")] = '\0';

    deletePattern(T, P);
    printf("Updated text: %s\n", T);
    return 0;
}
