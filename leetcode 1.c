#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void reverseVowels(char *s) {
    int left = 0, right = strlen(s) - 1;
    char temp;
    
    while (left < right) {
 
        while (left < right && !isVowel(s[left])) left++;
     
        while (left < right && !isVowel(s[right])) right--;
     
        if (left < right) {
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
}

int main() {
    char s[1000];
    
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0; 
    
    reverseVowels(s);
    
    printf("String after reversing vowels: %s\n", s);
    
    return 0;
}

