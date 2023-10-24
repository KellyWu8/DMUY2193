#include <stdio.h>
#include <string.h>

char* mystrchr(const char* str, const char);

int main() {
    const char str[] = "NYU.TANDON";
    const char ch = '.';
    char* ret;
    ret = mystrchr(str, ch);
    printf("String after |%c| is = |%s|\n", ch, ret+1);

    return 0;
}

char* mystrchr(const char* str, const char ch) {
    char* curr = str;
    while (curr) {
        if (*curr == ch) {
            return curr;
        }
        ++curr;
    }
    return NULL;
}