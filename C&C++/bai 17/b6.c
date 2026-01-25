#include <stdio.h>
#include <string.h>

int main() {
    char chuoi[200];
    char tu_dai_nhat[100];
    char* token;
    int max_do_dai = 0;
    int do_dai_hien_tai;

    printf("Nhap vao mot chuoi bat ky: ");
    fgets(chuoi, sizeof(chuoi), stdin);
    chuoi[strcspn(chuoi, "\n")] = '\0';

    token = strtok(chuoi, " ");

    while (token != NULL) {
        do_dai_hien_tai = strlen(token);
        
        if (do_dai_hien_tai > max_do_dai) {
            max_do_dai = do_dai_hien_tai;
            strcpy(tu_dai_nhat, token);
        }
        
        token = strtok(NULL, " ");
    }

    printf("Tu dai nhat la: %s\n", tu_dai_nhat);
    printf("Do dai: %d\n", max_do_dai);

    return 0;
};
