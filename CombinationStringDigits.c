/*
Finding all combinations of a given string digits- Given an input string of digits, find all combinations of numbers that can be formed using digits in the same order. Write a C program to find all the combinations of a user given string digits.

Test Case 1:

Input:

5

11 22 99 0 33 44

Output:

22 11 99 0 33

22 99 11 0 33

22 99 0 11 33

22 99 0 33 11

99 22 0 33 11

99 0 22 33 11

99 0 33 22 11

99 0 33 11 22

0 99 33 11 22

0 33 99 11 22

0 33 11 99 22

0 33 11 22 99

33 0 11 22 99

33 11 0 22 99

33 11 22 0 99

33 11 22 99 0

11 33 22 99 0

11 22 33 99 0

11 22 99 33 0

11 22 99 0 33
*/

#include<stdio.h>

int main()
{
    int n; scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    for(int i = 0; i<n; i++){
        int k = 0;
        for(int j = 1; j<n; j++){
            int temp = arr[k];
            arr[k] = arr[j];
            arr[j] = temp;
            k++;
            for(int m = 0; m < n; m++) printf("%d ", arr[m]);
            printf("\n");
        }
    }        
}
