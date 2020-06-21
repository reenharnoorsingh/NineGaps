#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;


int calculate(int a, char x, int b, char y, int c)
{
    int result;
    if (x == '+')
    {
        if (y == '+')
            result = a + b + c;
        else if (y == '-')
            result = a + b - c;
        else if (y == '*')
            result = a + b * c;
    }
    else if (x == '-')
    {
        if (y == '+')
            result = a - b + c;
        else if (y == '-')
            result = a - b - c;
        else if (y == '*')
            result = a - b * c;
    }
    else if (x == '*')
    {
        if (y == '+')
            result = a * b + c;
        else if (y == '-')
            result = a * b - c;
        else if (y == '*')
            result = a * b * c;
    }
    else
    {
        cout << ("Something went wrong");
    }
    return result;
}
int main()
{
    int main_board[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // It defines the main board to store all the values from 1-9
    int missing_array[9];                            // This line generates an array of size 9 to keep track of missing values
    int game_board[9];                               // It defines an array to form the actual game board with random numbers and hidden values
    int temp_board[9];                               // It defines an array which is a copy of the game_board and will be displayed to the user and will be updated in each iteration
    int row_results[3];                              // this is an array that stores the results of calculation of each row
    int column_results[3];                           // this is an array that stores the results of calculation of each column
    char operators_array[12];                        // this is an array that stores random operations
    int i, j;                                        // these variables will be used for loop indexes
    int rand_num, temp1;                             // rand_num will be used to store the result of random number generations, temp1 will be used as a temporary variable
    int level;                                       // this variable stores the level of difficulty
    char check_game;                                 // this is a flag variable to determine if the user solves the game correctly
    int play_again;                                  // this is a flag variable to determine if the user wants to play again or not
    int missing_count;                               // this is a variable that keep track of the number of missing values in the game board.
    srand(time(NULL)); // It generates a seed, using current time, for the random generator
    do
    {
        check_game =1;
        level =0;
        cout << ("Welcome to NineGaps the game! By Harnoor Singh Reen\n");
        
    } while (1);
    
}