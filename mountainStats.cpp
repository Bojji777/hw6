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
    int size = 3;
    char separator = '|';
    string tempArr[2];
    string mountains[size];
    int heights[size];

    int max = heights[0];
    int min = heights[0]; 
    int counter = 0; 
    int indexMax = -1;
    int indexMin = -1;
    
    ifstream in_file;
    in_file.open(filename);

    if(in_file.fail())
    {
        cout << "Could not open file." << endl;
        return;
    }
    else
    {    
        while(!in_file.eof())
        {
            // reading one line at a time
            getline(in_file, line);

            split(line, separator, tempArr, size); 

            string mountain_names = tempArr[0]; 
            int mountain_height = stoi(tempArr[1]);

            mountains[counter] = mountain_names;
            heights[counter] = mountain_height;

            mountain_names = "";
            mountain_height = 0;
            counter++;            

        }        
    }
    
    for(int i = 0; i < size ; i++)
    {
        if(max < heights[i])
        {
            max = heights[i];
            indexMax = i; // telling us the index where that max is at
        }
        if(min > heights[i])
        {
            min = heights[i];
            indexMin = i;
        }
    }

    cout << "Number of lines read: " << counter  << "." << endl;  
    cout << "Tallest mountain: " << mountains[indexMax] << " at " << heights[indexMax] << " feet." << endl;
    cout << "Smallest mountain: " << mountains[indexMin] << " at " << heights[indexMin] << " feet." << endl;

    return;

}

int main()
{
    string filename = "mountain_data.txt";

    printMountainStats(filename);

}