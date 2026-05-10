#include <stdio.h>
#include <stdlib.h>

/// Calculate String Length
int Strlen(char *str)
{
    int l = 0;
    while (str[l] != '\0')
    {
        l++;
    }
    return l;
}

/// Copy String
void myStrcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

/// Compare Two Strings
int myStrcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            return s1[i] - s2[i];
        }
        i++;
    }
    return s1[i] - s2[i];
}

/// Concatenate Two Strings
void myStrcat(char *dest, char *src)
{
    int i = 0, j = 0;
    while (dest[i] != '\0')
    {
        i++;    // Move to end of dest
    }
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';  // Null terminate
}

/// Find Substring (Returns Start Index or -1)
int isSubstring(char *str, char *sub)
{
    int i, j;
    for (i = 0; str[i] != '\0'; i++)
    {
        for (j = 0; sub[j] != '\0'; j++)
        {
            if (str[i + j] != sub[j])
            {
                break;
            }
        }
        if (sub[j] == '\0')
        {
            return i;  // Found
        }
    }
    return -1;  // Not found
}

/// Extract Substring
void substring(char *orig, char *substr, int index, int length)
{
    int i = 0;
    while (i < length && orig[index + i] != '\0')
    {
        substr[i] = orig[index + i];
        i++;
    }
    substr[i] = '\0';
}

/// Insert Substring at a Position
void insertSubstring(char *mainStr, char *subStr, int pos)
{
    char result[200];
    int i, j = 0, k = 0;

    for (i = 0; i < pos; i++)
    {
        result[i] = mainStr[i];
    }
    while (subStr[j] != '\0')
    {
        result[i++] = subStr[j++];
    }
    while (mainStr[pos + k] != '\0')
    {
        result[i++] = mainStr[pos + k++];
    }
    result[i] = '\0';

    myStrcpy(mainStr, result);
}

/// Delete a Substring
void deleteSubstring(char *mainStr, char *subStr)
{
    int index = isSubstring(mainStr, subStr);
    if (index == -1) return;  // Substring not found

    int i;
    for (i = index; mainStr[i + Strlen(subStr)] != '\0'; i++)
    {
        mainStr[i] = mainStr[i + Strlen(subStr)];
    }
    mainStr[i] = '\0';  // Null terminate
}


/// Replace a Substring
void replaceSubstring(char *mainStr, char *oldSub, char *newSub)
{
    char result[300];
    int i = 0, j = 0, index = isSubstring(mainStr, oldSub);

    if (index == -1)
    {
        return;  // Substring not found
    }

    while (i < index)
    {
        
        result[i++] = mainStr[j++];
    }

    j += Strlen(oldSub);  // Skip old substring

    int k = 0;
    while (newSub[k] != '\0')
    {
        result[i++] = newSub[k++];
    }

    while (mainStr[j] != '\0')
    {
        result[i++] = mainStr[j++];
    }

    result[i] = '\0';

    myStrcpy(mainStr, result);
}


/// Read String Without `string.h`
void readString(char *str, int size)
{
    int i = 0;
    char c;
    while ((c = getchar()) != '\n' && i < size - 1)
    {
        str[i++] = c;
    }
    str[i] = '\0';
}

/// Main Menu
int main()
{
    char Str1[100], Str2[100], Str3[100], part_num[100], subStri[50], subStrd[50], oldSub[50], newSub[50];
    int choice, st, nofc, index, pos;

    while (1)
    {
        printf("\n--- String Operations Menu ---\n");
        printf("1. Input a String\n");
        printf("2. Length of the String\n");
        printf("3. Display the String\n");
        printf("4. Sub-string of the String\n");
        printf("5. Compare Two Strings\n");
        printf("6. Concatenation of Two Strings\n");
        printf("7. Find Substring (Indexing)\n");
        printf("8. Insert a Sub-string\n");
        printf("9. Delete a Sub-string\n");
        printf("10. Replace a Sub-string\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice)
        {
        case 1:
            printf("Enter a string: ");
            readString(Str1, sizeof(Str1));
            break;

        case 2:
            printf("The length of the string is: %d\n", Strlen(Str1));
            break;

        case 3:
            printf("Stored String: %s\n", Str1);
            break;

        case 4:
            printf("Enter start index: ");
            scanf("%d", &st);
            printf("Enter number of characters: ");
            scanf("%d", &nofc);
            substring(Str1, part_num, st, nofc);
            printf("Sub-string: %s\n", part_num);
            break;

        case 5:
            printf("Enter second string: ");
            readString(Str2, sizeof(Str2));
            if (myStrcmp(Str1, Str2) == 0)
                printf("The two strings are the same.\n");
            else
                printf("The two strings are different.\n");
            break;

        case 6:
            printf("Enter a string to add: ");
            readString(Str2, sizeof(Str2));
            myStrcat(Str1, Str2);
            printf("Concatenated String: %s\n", Str1);
            break;

        case 7:
            printf("Enter substring to find: ");
            readString(Str3, sizeof(Str3));
            index = isSubstring(Str1, Str3);
            if (index != -1)
                printf("Substring found at index: %d\n", index);
            else
                printf("Substring not found.\n");
            break;

        case 8:
            printf("Enter substring to insert: ");
            readString(subStri, sizeof(subStri));
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            insertSubstring(Str1, subStri, pos);
            printf("Updated String: %s\n", Str1);
            break;

        case 9:
            printf("Enter substring to delete: ");
            readString(subStrd, sizeof(subStrd));
            deleteSubstring(Str1, subStrd);
            printf("Updated String: %s\n", Str1);
            break;

        case 10:
            printf("Enter substring to replace: ");
            readString(oldSub, sizeof(oldSub));
            printf("Enter new substring: ");
            readString(newSub, sizeof(newSub));
            replaceSubstring(Str1, oldSub, newSub);
            printf("Updated String: %s\n", Str1);
            break;

        case 0:
            exit(0);
        }
    }
}
