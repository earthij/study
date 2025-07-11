#include <cstdio>

int main(int argc, char *argv[])
{
    printf("Program started\n");
    FILE *recordFile;
    // Does the file exist?
    recordFile = fopen("recordFile.txt", "r");
    if (recordFile != NULL) {
        fclose(recordFile);
        recordFile = fopen("recordFile.txt", "a");
    }
    else {
        fclose(recordFile);
        recordFile = fopen("recordFile.txt", "w");
    }
    fprintf(recordFile, "%s,%s\n", argv[1], argv[2]);
    fclose(recordFile);


    return 0;
}