#include <stdio.h>
#include <stdlib.h>

int main() {
    int number = 5;
    int guess;
    int amountOfTries = 5;

    while (number != guess) {
        
        if (amountOfTries == 0) {
            printf("Unfortunately you lost all of your tries.\n");
            printf("The correct answer was: %d\n", number);
            break;
        }
        else{
            printf("Try guessing the number: \n");
            scanf("%d", &guess);
            
            amountOfTries--;
        }
    }
    if (number == guess){
        printf("Congratulations you guessed right! The number was %d\n", number);
    }
    else{
        printf("Try again by clicing the play button\n");
    }
    return 0;
}