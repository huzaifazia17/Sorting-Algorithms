#include <iostream>
#include <string>

using namespace std;

int extractOdd(int list1[], int list2[], int list3[], int SIZE_M, int SIZE_N);
int extractEven(int list1[], int list2[], int list3[], int SIZE_M, int SIZE_N);
int merge(int list1[], int list2[], int list3[], int SIZE_M, int SIZE_N);
int mergeSort(int list1[], int list2[], int list3[], int SIZE_M, int SIZE_N);
int display(int list3[], int SIZE_MN);

int main()
{
    int SIZE_M;                    //size 5
    int SIZE_N;                    // size 10
    int SIZE_MN = SIZE_M + SIZE_N; // size would be 5 +10
    int *list1, *list2, *list3;    // * Indicates a pointer- This is a vraible meant to store the address of some other variable

    cout << "Please enter the size of List 1: ";
    cin >> SIZE_M;
    cout << "Please enter the size of List 2: ";
    cin >> SIZE_N;

    list1 = new int[SIZE_M];
    list2 = new int[SIZE_N];
    list3 = new int[SIZE_MN];

    cout << "Enter " << SIZE_M + 1 << " values to fill List 1" << endl;
    for (int i = 0; i <= SIZE_M; i++)
    {
        cout << "Enter a value for index " << i << ": ";
        cin >> list1[i];
    }
    cout << "Enter " << SIZE_N + 1 << " values to fill List 1" << endl;
    for (int i = 0; i <= SIZE_N; i++)
    {
        cout << "Enter a value for index " << i << ": ";
        cin >> list2[i];
    }

    SIZE_MN = extractOdd(list1, list2, list3, SIZE_M, SIZE_N);
    cout << "These are the odd values from both List 1 and List 2 put into List 3" << endl;
    display(list3, SIZE_MN);
    cout << " " << endl;

    SIZE_MN = extractEven(list1, list2, list3, SIZE_M, SIZE_N);
    cout << "These are the Even values from both List 1 and List 2 put into List 3" << endl;
    display(list3, SIZE_MN);
    cout << " " << endl;

    SIZE_MN = merge(list1, list2, list3, SIZE_M, SIZE_N);
    cout << "List 1 and List 2 have now been merged into List 3" << endl;
    display(list3, SIZE_MN);
    cout << " " << endl;

    SIZE_MN = mergeSort(list1, list2, list3, SIZE_M, SIZE_N);
    cout << "List 3 has now been bubble sorted" << endl;
    display(list3, SIZE_MN);
    cout << " " << endl;

    return 0;
}

int extractOdd(int list1[], int list2[], int list3[], int SIZE_M, int SIZE_N)
{
    int counter = 0;
    for (int i = 0; i <= SIZE_M; i++)
    {
        if (list1[i] % 2 != 0)
        {
            list3[counter++] = list1[i];
        }
    }

    for (int k = 0; k <= SIZE_N; k++)
    {
        if (list2[k] % 2 != 0)
        {
            list3[counter++] = list2[k];
        }
    }

    return counter;
}

int extractEven(int list1[], int list2[], int list3[], int SIZE_M, int SIZE_N)
{
    int counter = 0;
    for (int i = 0; i <= SIZE_M; i++)
    {
        if (list1[i] % 2 == 0)
        {
            list3[counter++] = list1[i];
        }
    }

    for (int k = 0; k <= SIZE_N; k++)
    {
        if (list2[k] % 2 == 0)
        {
            list3[counter++] = list2[k];
        }
    }

    return counter;
}
int merge(int list1[], int list2[], int list3[], int SIZE_M, int SIZE_N)
{
    int counter = 0;
    for (int i = 0; i <= SIZE_M; i++)
    {

        list3[counter++] = list1[i];
    }

    for (int k = 0; k <= SIZE_N; k++)
    {

        list3[counter++] = list2[k];
    }

    return counter;
}

int mergeSort(int list1[], int list2[], int list3[], int SIZE_M, int SIZE_N)
{
    int SIZE_MN = merge(list1, list2, list3, SIZE_M, SIZE_N);
    for (int i = 0; i < SIZE_MN; i++)
    {
        int min = i;
        for (int j = i; j < SIZE_MN; j++)
        {
            if (list3[j] < list3[min])
            {
                min = j;
            }
        }
        int temp = list3[i];
        list3[i] = list3[min];
        list3[min] = temp;
    }

    return SIZE_MN;
}

int display(int list3[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << list3[i] << " ";
    }
}