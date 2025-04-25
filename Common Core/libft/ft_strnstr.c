#include <stdio.h>

int main() {
    const char *text = "Hi schöne Welt";

    printf("Adresse von text     : %p\n", (void *)text);
    printf("Adresse von text + 5 : %p\n", (void *)(text + 5));
    printf("Inhalt ab text + 5   : %s\n", text + 5);
    printf("text[5]              : %c\n", text[5]);

    return 0;
}
