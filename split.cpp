// CSCI 1300 Fall 2022
// Author: Alejandro Chumil
// Recitation: 304 – Nikhith Sannidhi
// Homework 5 - Problem # 4

#include <iostream>

using namespace std;

int split(string input_string, char separator, string arr[],int arr_size)
{
    int len = input_string.length();
    int indexArr = 0;
    int oldSeperator = -1;
    // "RST,UVW,XYZ"; 
                 

    for( int indexStr = 0; indexStr < len; indexStr++)
    {
        if(input_string[indexStr] == separator)
        {
            if(indexArr < arr_size) // make sure we only store the asked amount of arrays
            {   
                arr[indexArr] = input_string.substr(oldSeperator + 1, indexStr - (oldSeperator + 1));
                indexArr++; // the string array index

            } else
            {
                return -1;
            }

            oldSeperator = indexStr;
        }
    }
    arr[indexArr] = input_string.substr(oldSeperator + 1, input_string.length() - (oldSeperator + 1)); 
    indexArr++;

    if(indexArr > arr_size)
    {
        return -1;
    }

    return indexArr;
}

int main()
{
    string testcase = "Bangkok,Berlin,Birmingham,Bogota,Busan,Baton Rouge,Beaumont,Boise,Budapest";
    char separator = ',';
    int arr_size = 5;
    string arr[arr_size];
    // num_splits is the value returned by split
    int num_splits = split(testcase, separator, arr, arr_size);
    cout << "Function returned value: " << num_splits << endl;
    for (int i=0; i < arr_size; i++){
    cout << "arr["<< i << "]:" << arr[i] << endl;
    }


}