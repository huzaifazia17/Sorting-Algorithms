#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readTemp(double tempVals[], int numOfTempVals);
double sum(double tempVals[], int numOfTempVals);
double average(double tempVals[], int numOfTempVals);
int min(double tempVals[], int numOfTempVals);
int max(double tempVals[], int numOfTempVals);
int bSort(double tempVals[], int numOfTempVals);
int reverse(double tempVals[], int numOfTempVals);
int bSearch(double tempVals[], int numOfTempVals);
void display(double tempVals[], int numOfTempVals);

int main()
{
    const int numOfTempVals = 22;
    const int arrayVal = 21;
    double tempVals[arrayVal];

    readTemp(tempVals, numOfTempVals);
    cout << "These are the temperature values stored in the array" << endl;
    display(tempVals, numOfTempVals);
    cout << " " << endl;
    cout << "The sum of all the temperatures is " << sum(tempVals, numOfTempVals) << endl;
    cout << "The average is " << average(tempVals, numOfTempVals) << endl;
    cout << "The minimum temperature is " << min(tempVals, numOfTempVals) << endl;
    cout << "The maximum temperature is " << max(tempVals, numOfTempVals) << endl;
    reverse(tempVals, numOfTempVals);
    cout << "The array has now been reversed" << endl;
    display(tempVals, numOfTempVals);
    cout << " " << endl;
    bSort(tempVals, numOfTempVals);
    cout << "The array has now been bubble sorted" << endl;
    display(tempVals, numOfTempVals);
    cout << " " << endl;
    bSearch(tempVals, numOfTempVals);
    return 0;
}

void readTemp(double tempVals[], int numOfTempVals)
{
    int counter;
    string filename;
    ifstream listOfTemp;

    cout << "Enter the name of the input file: Note: The name is temperature.txt" << endl;
    cin >> filename;

    listOfTemp.open(filename.c_str(), ios::app);

    if (listOfTemp.fail())
    {
        cerr << "Error opening the file\n";
        exit(1);
    }
    else if (listOfTemp.is_open())
    {
        while (!listOfTemp.eof())
        {
            for (int i = 0; i < numOfTempVals; i++)
            {
                listOfTemp >> tempVals[i];
            }
            listOfTemp.close();
        }
    }
}

double sum(double tempVals[], int numOfTempVals)
{
    double getSum = 0;
    for (int i = 0; i < numOfTempVals; i++)
    {
        getSum = getSum + tempVals[i];
    }
    return getSum;
}
double average(double tempVals[], int numOfTempVals)
{
    double average;
    double getSum = 0;
    for (int i = 0; i < numOfTempVals; i++)
    {
        getSum = getSum + tempVals[i];
    }
    average = getSum / numOfTempVals;

    return average;
}
int min(double tempVals[], int numOfTempVals)
{
    double min = tempVals[0];

    for (int i = 0; i < numOfTempVals; i++)
    {
        if (tempVals[i] < min)
        {
            min = tempVals[i];
        }
    }

    return min;
}
int max(double tempVals[], int numOfTempVals)
{
    double max = tempVals[0];

    for (int i = 0; i < numOfTempVals; i++)
    {
        if (tempVals[i] > max)
        {
            max = tempVals[i];
        }
    }

    return max;
}
int bSort(double tempVals[], int numOfTempVals)
{
    double tempValue;

    for (int i = 0; i < numOfTempVals - 1; i++) // Finds where the smallest element of the array is beginning at i
    {
        for (int j = i + 1; j < numOfTempVals; j++)
        {
            if (tempVals[j] < tempVals[i])
            {
                tempValue = tempVals[i]; //exchange smallest value with value at k
                tempVals[i] = tempVals[j];
                tempVals[j] = tempValue;
            }
        }
    }
    return 0;
}
int reverse(double tempVals[], int numOfTempVals)
{
    double tempValue;
    for (int i = 0; i < numOfTempVals / 2; i++)
    {
        tempValue = tempVals[i];
        tempVals[i] = tempVals[numOfTempVals - i - 1];
        tempVals[numOfTempVals - i - 1] = tempValue;
    }
    return 0;
}

int bSearch(double tempVals[], int numOfTempVals)
{
    double findTemp;
    cout << "What temperature value would you like to find the index of: " << endl;
    cin >> findTemp;
    for (int i = 0; i < numOfTempVals; i++)
    {
        if (tempVals[i] == findTemp)
        {
            cout << "The temprature is present in index " << i << " of the array" << endl;
            return 0;
        }
    }
    cout << "That value does not exist in the array" << endl;
}
void display(double tempVals[], int numOfTempVals)
{
    for (int i = 0; i < numOfTempVals; i++)
    {
        cout << tempVals[i] << " ";
    }
}