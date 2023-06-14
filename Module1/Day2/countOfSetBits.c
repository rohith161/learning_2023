#include <stdio.h>

int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1; // checking if every bits in the num is set or not and added to count returned to Totalset bits
        num >>= 1;
    }
    return count;
}

int totalSetBits(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += countSetBits(arr[i]); // every elements in array sets bits are counted in countSetBits
    }
    return total;
}

int main() {
    int arr[] = {0x1, 0xF4, 0x10001};
    int total = totalSetBits(arr, sizeof(arr) / sizeof(arr[0]));
    printf("Total number of set bits in an array : %d bits\n", total);

    return 0;
}
