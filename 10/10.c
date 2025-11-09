#include <stdio.h>

int main() {
    FILE *src, *dest;
    char source[30], target[30], ch;

    printf("Enter source file name: ");
    scanf("%s", source);
    printf("Enter destination file name: ");
    scanf("%s", target);

    src = fopen(source, "r");
    if (src == NULL) {
        printf("Cannot open source file.\n");
        return 1;
    }

    dest = fopen(target, "w");
    if (dest == NULL) {
        printf("Cannot create destination file.\n");
        fclose(src);
        return 1;
    }

    while ((ch = fgetc(src)) != EOF)
        fputc(ch, dest);

    printf("File copied successfully.\n");

    fclose(src);
    fclose(dest);
    return 0;
}
