#include <stdio.h>

void smalldLarged(int n) {
    int smallest = 0, largest = 0, temp;
    int t = 0;

    while (n > 0) {

        // Extracting the single digit every time
        temp = n % 10;

        // to check if there a single digit or same digits are repeated
        if (t == 0) {
            smallest = temp;
            largest = temp;
            t++;
        }
        
        // comparing the largest number and the smallest number
        if (temp > largest) {
            largest = temp;
        } else if (temp < smallest) {
            smallest = temp;
        }

        // Deleting the single digit every iteration
        n /= 10;
    }

    // Result
    if (smallest != largest) {
        printf("%d and %d\n", smallest, largest);
    } else {
        printf("Not Valid\n");
    }
}

int main() {
    
    int n = 3;
    smalldLarged(n);
    n = 8;
    smalldLarged(n);
    n = 156;
    smalldLarged(n);
    n = 123450;
    smalldLarged(n);
    return 0;
}
