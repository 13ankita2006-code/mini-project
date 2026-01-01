#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int isPrime(int n){
    if(n<=1)
    return 0;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0)
        return 0;
    }
    return 1;
}
int main() {
    int number, choice, score=0;
    char play;
    srand(time(0));
    printf("PRIME GUESS: MATH PUZZLE GAME\n");
    do{
        number = rand()%50+1;
        printf("Generated Number: %d\n", number);
        printf("Choose option: \n");
        printf("1. Prime\n");
        printf("2. Odd\n");
        printf("3. Even\n");
        printf("Enter your choice(1-3): \n");
        scanf("%d",&choice);
        if(choice<1 || choice>3){
            printf("Invalid choice! Try again.\n");
            continue;
        }
        if(choice==1 && isPrime(number)){
            printf("Correct! It is a Prime number. \n");
            score+=10;
        }
        else if(choice==2 && number%2!=0){
            printf("Correct! it's an Odd number.\n");
            score+=10;
        }
        else if(choice==3 && number %2==0){
            printf("Correct! it's an Even number\n");
            score+=10;
        }
        else{
            printf("Wrong Answer!\n");
            score-=5;
            if(choice==1)
            printf("Hint: Check divisibility of the number.\n");
            else
            printf("Hint: Check the last digit of the number.\n");
        }
        printf("Current Score: %d\n",score);
        printf("\nDo you want to play again?(y/n): \n");
        scanf(" %c",&play);
    }
    while(play=='y'|| play=='Y');
    printf("\nFinal Score: %d\n",score);
    printf("Thanku for playing. See you soon\n");
    return 0;
}