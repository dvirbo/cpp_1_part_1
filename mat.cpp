#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <array>
#include "mat.hpp"

using namespace std;
using namespace ariel;

string check_validity(int col, int row, char a, char b)
{
    if (col < 0)
    {
        return "column num is negetive-must be positive";
    }

    if (row < 0)
    {
        return "row num is negetive-must be positive";
    }
    if (a != '@' || b != '-')
    {
        return "char isn't valid";
    }
    return  a;
}



void fill(int row, int col)
{

    int i; // iterator
    int sRow = 0; // starting row index
    int sCol = 0; // starting column index

    // Store given number of rows and columns for the printing:
    int tRow = row, tCol = col;

    char mat [row][col]; //need to fill it
    char sigh = '@'; // init the char 
    
 
    while (sRow < row && sCol < col)
    {
        // Fill the first row:
        for (i = sCol; i < col; i++)
            mat [sRow][i] = sigh;
        sRow++;

        // Fill the last column:
        for (i = sRow; i < row; i++)
            mat [i][col-1] = sigh;
        col--;

        // Fill the last row:
        if (sRow < row)
        {
            for (i = col-1; i >= sCol; i--)
                mat [row-1][i] = sigh;
            row--;
        }

        // Fill the first column:
        if (sCol < col)
        {
            for (i = row-1; i >= sRow; i--)
                mat [i][sCol] = sigh;
            sCol++;
        }

        // change the char for next iteration:

        if(sigh == '@')
            sigh == '-';
        else
            sigh == '@';
    }

    // Print the filled matrix
    for (i = 0; i < tRow; i++)
    {
        for (int j = 0; j < tCol; j++)
            cout <<" "<< mat [i][j];
        cout <<"\n";
    }
}


namespace ariel
{

    string mat(int col, int row, char a, char b)
    {
        string ans = check_validity(int col, int row, char a, char b);
        if(ans != 'a')
            throw invalid_argument(ans);

        fill(row,col);


    }

}