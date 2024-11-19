int twoStacks(int maxSum, int a_count, int* a, int b_count, int* b) {
int s1 = 0, s2 = 0, maxCount = 0, i = 0, j = 0; 

    while (i < a_count && s1 + a[i] <= maxSum) {
        s1 += a[i];
        i++;
    }
    maxCount = i; 

    while (j < b_count && i >= 0) {
        s2 += b[j];
        j++;
        while (s1 + s2 > maxSum && i > 0) {
            s1 -= a[--i];
        }
        if (s1 + s2 <= maxSum) {
            if (i + j > maxCount) {
                maxCount = i + j;
            }
        }
    }
    return maxCount;
}
/* Output: Input 
1
5 4 10
4 2 4 6 1
2 1 8 5
Output
4 */
