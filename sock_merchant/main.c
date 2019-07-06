#include <stdlib.h>
#include <string.h>
#include <printf.h>

void printc(int expected, int actual)
{
    printf("Expected %d. Actual %d.\n\n", expected, actual);
}

void print_arr(int ar_count, int *ar)
{
    for (int i = 0; i < ar_count; i++)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

int sockMerchant(int n, int ar_count, int *ar)
{
    int r = 0;
    int max = 100;
    int *t = calloc(max, sizeof(int));

    for (int i = 0; i < ar_count; i++)
    {
        t[ar[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        if (t[i] > 0)
        {
            r += t[i] / 2;
        }
    }

    return r;
}

int test_1()
{
    int n = 6;
    int ar[] = {1, 2, 1, 2, 1, 2};
    int expected = 2;

    print_arr(n, ar);
    int actual = sockMerchant(n, n, ar);
    printc(expected, actual);

    return expected == actual;
}

int test_2()
{
    int n = 0;
    int ar[] = {};
    int expected = 0;

    print_arr(n, ar);
    int actual = sockMerchant(n, n, ar);
    printc(expected, actual);

    return expected == actual;
}

int test_3()
{
    int n = 2;
    int ar[] = {1, 1};
    int expected = 1;

    print_arr(n, ar);
    int actual = sockMerchant(n, n, ar);
    printc(expected, actual);

    return expected == actual;
}

int test_4()
{
    int n = 1;
    int ar[] = {1};
    int expected = 0;

    print_arr(n, ar);
    int actual = sockMerchant(n, n, ar);
    printc(expected, actual);

    return expected == actual;
}

int test_5()
{
    int n = 6;
    int ar[] = {1, 2, 3, 4, 5, 6};
    int expected = 0;

    print_arr(n, ar);
    int actual = sockMerchant(n, n, ar);
    printc(expected, actual);

    return expected == actual;
}

int test_6()
{
    int n = 9;
    int ar[] = {10, 20, 20, 10, 10, 30, 50, 10, 20};
    int expected = 3;

    print_arr(n, ar);
    int actual = sockMerchant(n, n, ar);
    printc(expected, actual);

    return expected == actual;
}

int test_7()
{
    int n = 2;
    int ar[] = {100, 100};
    int expected = 1;

    print_arr(n, ar);
    int actual = sockMerchant(n, n, ar);
    printc(expected, actual);

    return expected == actual;
}

int main()
{
    return !(test_1() && test_2() && test_3() && test_4() && test_5() && test_6() && test_7());
}
