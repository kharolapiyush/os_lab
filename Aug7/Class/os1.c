//write a program to check whether a number is prime or not in the child processs and the process calcualte factoial of a number in the parent process.
 #include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int n, i, prime = 1;
    long long fact = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        printf("Process creation failed.\n");
    }
    else if (pid == 0) {
        // Child process - Check Prime
        if (n <= 1)
            prime = 0;
        else {
            for (i = 2; i <= n / 2; i++) {
                if (n % i == 0) {
                    prime = 0;
                    break;
                }
            }
        }

        if (prime)
            printf("Child Process: %d is a Prime number.\n", n);
        else
            printf("Child Process: %d is not a Prime number.\n", n);
    }
    else {
        // Parent process - Calculate Factorial
        wait(NULL); // Wait for child process to finish

        for (i = 1; i <= n; i++) {
            fact *= i;
        }

        printf("Parent Process: Factorial of %d = %lld\n", n, fact);
    }

    return 0;
}



