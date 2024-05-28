#include <stdio.h>
#include <string.h>

main() {
    int i = 0, m;
    char r[256], c;
    FILE *fIn, *fOut;

    scanf("%d", &m);

    fIn = fopen("./recenice.txt", "r");
    fOut = fopen("./sadrze.txt", "w");

    while (!feof(fIn)) {
        c = getc(fIn);

        if (i > 0) {
            r[i++] = c;

            if (c == '.' || c == '!' || c == '?') {
                r[i] = '\0';
                i = 0;
                if (strlen(r) > m) {
                    fputs(fOut, r);
                    fputs(fOut, "\n");
                }
            }
        } else {
            if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '"' || c == '\'') {
                r[i++] = c;
            }
        }
    }

    fclose(fIn);
    fclose(fOut)
}