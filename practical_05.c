#include <stdio.h>

// Function to move n disks from tower 'src' to tower 'dest' using tower 'temp'
void towerOfHanoi(int n, char src, char dest, char temp) {
    if(n == 1) {
        printf("Move disk 1 from tower %c to tower %c\n", src, dest);
        return;
    }
    
    towerOfHanoi(n - 1, src, temp, dest);
    printf("Move disk %d from tower %c to tower %c\n", n, src, dest);
    towerOfHanoi(n - 1, temp, dest, src);
}

int main() {
    int n;
    
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    towerOfHanoi(n, 'A', 'C', 'B');
    
    return 0;
}

