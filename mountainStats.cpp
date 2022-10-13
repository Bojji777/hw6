// CSCI 1300 Fall 2022
// Author: Alejandro Chumil
// Recitation: 304 – Nikhith Sannidhi
// Homework 6 - Problem # 2

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std; 


int split(string input_string, char separator, string arr[],int arr_size)
{
    int len = input_string.length();
    int indexArr = 0;
    int oldSeperator = -1;
    
    for(int indexStr = 0; indexStr < len; indexStr++)
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

void printMountainStats(string filename)
{
    // reference - int split(string input_string, char separator, string arr[],int arr_size)
    string line;
    
    ifstream filename;
    
    my_file.open()


    cout << "Number of lines read: " <<  << "." << endl;
    cout << "Tallest mountain: "  << << " at " << << " feet." << endl;
    cout << "Shortest mountain: "  << << " at " << << " feet." << endl;

    return;

}

int main()
{


}