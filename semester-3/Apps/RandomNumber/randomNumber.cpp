#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>

int parseInt(const char *string);

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int start, end;
    int userOwn = 0;

    if (argc == 3) {
        start = parseInt(argv[1]);
        end = parseInt(argv[2]);
    }
    else {
        printf("Bad run command.");
        return 0;
    }
    
    int tries = 0;
    int theNumber = (rand() % (1 + end - start)) + start;
    while (userOwn == 0) {
        tries++;
        int userInput;
        printf("Input: ");
        scanf("%d", &userInput);
        if (userInput == theNumber) {
            userOwn = 1;
        }
        else if (userInput < theNumber) {
            printf("Try higher.\t");
        }
        else {
            printf("Try lower.\t");
        }
    }
    printf("You worn. Tries: %d", tries);
    return 0;
}

int parseInt(const char *string)
{
    int exponent = 0;
    int number = 0;
    const int base = 10;
    while (string[exponent+1] != '\0') {
        exponent++;
    }
    for (int i = 0; i <= exponent; i++) {
        number += (string[i] - 48) * int(pow(base, exponent-i));
    }
    return number;
}