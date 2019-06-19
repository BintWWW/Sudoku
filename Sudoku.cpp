/*
Programmer: Bintao Wang

Program: wangP4.cpp
Purpose: Get a sudoku and print it out while checking if it plays by the rule. And the rule is in a 9x9 matrix, you put numbers in.
-There should no be same numbers in each row, column, and 3x3 Boxes.

Input: Get a large 9x9 sudoku from a file.
Output: Print out the sudoku and check if this sudoku is played by rules. The rule is there is no two same numbers in each row,
-in each column, and in each 3x3 square.
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<algorithm>

using namespace std;
const int Max = 9;          //Number of rows that this matrix has
//const int columnMax = 9;       //Number of columns that this matrix has.

ifstream inFP;
class sudoku                //class name
{
    char array[Max][Max];   //build an array


public:
    void getData();                 //getting data from current file
    void print();                   //print the matrix out
    void checkRow();                //check if there's no error row by row
    void checkColumn();             //check if there's no error column by column
    void checkBox();                //check if there's no error box by box
};

int main ()
{
    sudoku myList;
    char fileName[20];
    cout << "Enter the filename: ";
    cin >> fileName;
    inFP.open(fileName);                            //open file
    while(inFP.fail()){                             //check if the file exist
        cout << "no file exist!" << endl;
        return 0;

    }

    myList.getData();                               //get data from a file
    myList.print();                                 //print the matrix out
    myList.checkRow();                              //check rows
    myList.checkColumn();                           //check columns
    myList.checkBox();                              //check boxes

    inFP.close();                                   //close file
    cout << endl;
    cout << "I have abided the honor code." << endl;
    cout << "          ---signed by Bintao" << endl;
    return 0;
}

void sudoku::getData()             //open the file and read it
{

    for(int c=0; c<Max; c++){       //fill the matrix
        for(int r=0; r<Max; r++){
            inFP>>array[r][c];
            }
        }


}
void sudoku::print()                //print
{
    cout << "+-------+-------+-------+" << endl;
    cout << "| " << array[0][0] << " " << array[1][0] << " " <<  array[2][0] << " | " << array[3][0] << " " <<  array[4][0] << " " <<  array[5][0] << " | " << array[6][0] << " " <<  array[7][0] << " " <<  array[8][0] << " |" << endl;
    cout << "| " << array[0][1] << " " << array[1][1] << " " <<  array[2][1] << " | " << array[3][1] << " " <<  array[4][1] << " " <<  array[5][1] << " | " << array[6][1] << " " <<  array[7][1] << " " <<  array[8][1] << " |" << endl;
    cout << "| " << array[0][2] << " " << array[1][2] << " " <<  array[2][2] << " | " << array[3][2] << " " <<  array[4][2] << " " <<  array[5][2] << " | " << array[6][2] << " " <<  array[7][2] << " " <<  array[8][2] << " |" << endl;
    cout << "+-------+-------+-------+" << endl;
    cout << "| " << array[0][3] << " " << array[1][3] << " " <<  array[2][3] << " | " << array[3][3] << " " <<  array[4][3] << " " <<  array[5][3] << " | " << array[6][3] << " " <<  array[7][3] << " " <<  array[8][3] << " |" << endl;
    cout << "| " << array[0][4] << " " << array[1][4] << " " <<  array[2][4] << " | " << array[3][4] << " " <<  array[4][4] << " " <<  array[5][4] << " | " << array[6][4] << " " <<  array[7][4] << " " <<  array[8][4] << " |" << endl;
    cout << "| " << array[0][5] << " " << array[1][5] << " " <<  array[2][5] << " | " << array[3][5] << " " <<  array[4][5] << " " <<  array[5][5] << " | " << array[6][5] << " " <<  array[7][5] << " " <<  array[8][5] << " |" << endl;
    cout << "+-------+-------+-------+" << endl;
    cout << "| " << array[0][6] << " " << array[1][6] << " " <<  array[2][6] << " | " << array[3][6] << " " <<  array[4][6] << " " <<  array[5][6] << " | " << array[6][6] << " " <<  array[7][7] << " " <<  array[8][6] << " |" << endl;
    cout << "| " << array[0][7] << " " << array[1][7] << " " <<  array[2][7] << " | " << array[3][7] << " " <<  array[4][7] << " " <<  array[5][7] << " | " << array[6][7] << " " <<  array[7][8] << " " <<  array[8][7] << " |" << endl;
    cout << "| " << array[0][8] << " " << array[1][8] << " " <<  array[2][8] << " | " << array[3][8] << " " <<  array[4][8] << " " <<  array[5][8] << " | " << array[6][8] << " " <<  array[7][9] << " " <<  array[8][8] << " |" << endl;
    cout << "+-------+-------+-------+" << endl;
    cout << "This program is complete through Step 1." << endl << endl;
}

void sudoku::checkRow(){            //check rows
    int row;                        //row number orinted
    int r2;
    int checkR;                      //is all row correct?
    for(int c=0; c<Max; c++){       //loop to check rows
        row = c+1;
        for(int r=0; r<Max; r++)
        {
            for(int r2=r+1; r2<Max; r2++){
                if(array[r][c]==array[r2][c]){
                    cout << "Row " << row << " breaks the rule." << endl;
                    checkR = 0;
                    break;
                    }
            }
        }
    }
    if(checkR != 0)
        cout << "Congratulation! You have no error with rows!" << endl;



}

void sudoku::checkColumn(){         //check column
    int column;                     //row number orinted
    int c2;
    int checkC;                      //is all row correct?
    for(int r=0; r<Max; r++){       //loop to check rows
        column = r+1;
        for(int c=0; c<Max; c++)
        {
            for(int c2=c+1; c2<Max; c2++){
                if(array[r][c]==array[r][c2]){
                    cout << "Column " << column << " breaks the rule." << endl;
                    checkC = 0;
                    break;
                    }

            }
        }
    }
    if(checkC != 0)
        cout << "Congratulation! You have no error with columns!" << endl;
    cout << "This program is complete through Step 2." << endl << endl;
}

void sudoku::checkBox(){
    int rB,rowN,cB,columnN,num1,num2,num3,num4,num5,num6,num7,num8,num9,checkB;      //nums for each 3x3 boxes, check, etc.
    for(int rB=0; rB<Max; rB+=3){           //there's 9 boxes in a sudoku
        rowN=rB/3+1;
        for(int cB=0; cB<Max; cB+=3){       //well, this is the only way I can come up with
            columnN=cB/3+1;
            num1=array[cB+0][rB+0];
            num2=array[cB+0][rB+1];
            num3=array[cB+0][rB+2];
            num4=array[cB+1][rB+0];
            num5=array[cB+1][rB+1];
            num6=array[cB+1][rB+2];
            num7=array[cB+2][rB+0];
            num8=array[cB+2][rB+1];
            num9=array[cB+2][rB+2];
            if(num1!=num2&&num1!=num3&&num1!=num4&&num1!=num5&&num1!=num6&&num1!=num7&&num1!=num8&&num1!=num9&&num2!=num3&&num2!=num4&&num2!=num5&&num2!=num6&&num2!=num7&&num2!=num8&&num2!=num9&&num3!=num4&&num3!=num5&&num3!=num6&&num3!=num7&&num3!=num8&&num3!=num9&&num4!=num5&&num4!=num6&&num4!=num7&&num4!=num8&&num4!=num9&&num5!=num6&&num5!=num7&&num5!=num8&&num5!=num9&&num6!=num7&&num6!=num8&&num6!=num9&&num7!=num8&&num7!=num9&&num8!=num9)
                cout << "You are good with box (" << columnN << " , " << rowN << ")" << endl;
            else
                {cout << "You are wrong with box (" << columnN << " , " << rowN << ")" << endl;
                checkB = 0;
                }
        }
    }
    if(checkB != 0)
        cout << "Congratulation! You have no error with boxes!" << endl;
    cout << "This program is complete through Step 3." << endl << endl;
}
