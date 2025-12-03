#include <stdio.h>
#include <string.h>

// Function to check if a string is palindrome
int isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right) {
        if (str[left] != str[right])
            return 0; // Not a palindrome
        left++;
        right--;
    }
    return 1; // Palindrome
}

int main() {
    int n,i;
    printf("Enter number of strings: ");
    scanf("%d", &n);
    getchar();

    char words[n][100]; 

  
    for (i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        fgets(words[i], 100, stdin);
        words[i][strcspn(words[i], "\n")] = 0; 
    }

  
    int found = 0;
    for (i = 0; i < n; i++) {
        if (isPalindrome(words[i])) {
            printf("First palindromic string: %s\n", words[i]);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No palindromic string found.\n");

    return 0;
}

