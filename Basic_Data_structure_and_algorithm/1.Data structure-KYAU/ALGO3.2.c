#include <stdio.h>
#include <string.h>

int INDEX(char *T, char *P) {
    char *ptr = strstr(T, P); 
    if (ptr != NULL)
        return ptr - T; 
    else
        return 0; 
}
void REPLACE(char *T, char *P, char *Q) {
    char buffer[1000];
    char *pos = strstr(T, P);
    if (pos != NULL) {
        int i = 0;
        while (T + i != pos) {
            buffer[i] = T[i];
            i++;
        }
        int j = 0;
        while (Q[j] != '\0') {
            buffer[i++] = Q[j++];
        }
        i = 0;
        while (T[i + (pos - T) + strlen(P)] != '\0') {
            buffer[i + strlen(Q)] = T[i + (pos - T) + strlen(P)];
            i++;
        }
        buffer[i + strlen(Q)] = '\0';
        strcpy(T, buffer);
    }
}
int main() {
    char T[1000], P[100], Q[100];

    printf("Enter the text T: ");
    gets(T);
    printf("Enter the pattern P: ");
    gets(P);
    printf("Enter the replacement Q: ");
    gets(Q);

    int K = INDEX(T, P);
    
    while (K != 0) {
        REPLACE(T, P, Q);
        K = INDEX(T, P);
    }
    printf("Updated Text: %s\n", T);
    return 0;
}
