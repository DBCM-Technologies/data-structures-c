/* traverse.c Input an integer array and display its elements.

Copyright (C) DBCM Technologies 2025
Author: Amal Irfan K C
Date: 2025-06-17

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include <stdio.h>

int clear_input_line(void) {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
    return c == EOF;
}

int safer_get_int(int *a) {
    if (1 != scanf("%d", a)) {
        printf("Bad input.\n");
        return 1;
    }
    return 0;
}

#define A_MAX 100

int main(void) {
    int A[A_MAX] = {0};
    int i = 0;
    int n = 0;
    printf("Enter the number of elements (max=%d).\n", A_MAX);
    if (safer_get_int(&n))  /* returns non-zero if failed */
        return 1;
    clear_input_line();  /* remove trailing characters in the input line */
    if (n >= A_MAX || n < 0) {
        printf("Bad input '%d'.\n", n);
        return 1;
    }
    printf("Enter the %d elements.\n", n);
    for (i = 0; i < n; i++) {
        if (safer_get_int(&A[i]))  /* returns non-zero if failed */
            return 1;
    }
    clear_input_line();  /* remove trailing characters in the input line */
    if (n == 0)
        printf("Array elements (n=%d): \n  {}\n", n);
    else {
        printf("Array elements (n=%d): \n  {", n, n);
        for (i = 0; i < n - 1; i++)  /* print all except the last element */
            printf(" %d,", A[i]);
        printf(" %d }\n", A[i]); /* print the last element without a comma */
    }
    printf("Press enter to exit.\n");
    getchar();
    return 0; 
}