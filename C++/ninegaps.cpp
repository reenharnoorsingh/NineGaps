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
        cout << "Something went wrong";
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
    srand(time(NULL));                               // It generates a seed, using current time, for the random generator
    do
    {
        check_game = 1;
        level = 0;
        cout << "Welcome to NineGaps the game! By Harnoor Singh Reen\n";
        cout << "*****************************\n";
        cout << "      *****************      \n";
        cout << "            *****            \n";
        cout << "              *              \n";
        do
        {
            cout << "Choose the level of difficulty\n";
            cout << "1- Beginner\n";
            cout << "2- Intermediate\n";
            cout << "3- Advanced\n";
            cout << "4- Expert\n";
            cin >> level;
            if ((level < 1) || (level > 4))
            {
                cout << "Invalid Value";
            }
            else
            {
                switch (level)
                {
                case 1:
                    cout << "Beginner Level";
                    break;
                case 2:
                    cout << "Intermediate Level";
                    break;
                case 3:
                    cout << "Advanced Level";
                    break;

                case 4:
                    cout << "Expert Level";
                    break;
                }
                break;
            }
        } while (1);
        for (i = 0; i < 9; i++)
        {
            int temp = main_board[i];
            int randomIndex = rand() % 9;

            main_board[i] = main_board[randomIndex];
            main_board[randomIndex] = temp;
        }
        int num;
        for (i = 0; i < 12; i++)
        {
            num = (rand() % 3) + 1;
            if (num == 1)
                operators_array[i] = '+';
            else if (num == 2)
                operators_array[i] = '-';
            else if (num == 3)
                operators_array[i] = '*';
        }
        row_results[0] = calculate(main_board[0], operators_array[0], main_board[1], operators_array[1], main_board[2]);
        row_results[1] = calculate(main_board[3], operators_array[2], main_board[4], operators_array[3], main_board[5]);
        row_results[2] = calculate(main_board[6], operators_array[4], main_board[7], operators_array[5], main_board[8]);
        column_results[0] = calculate(main_board[0], operators_array[6], main_board[3], operators_array[9], main_board[6]);
        column_results[1] = calculate(main_board[1], operators_array[7], main_board[4], operators_array[10], main_board[7]);
        column_results[2] = calculate(main_board[2], operators_array[8], main_board[5], operators_array[11], main_board[8]);

        for (i = 0; i < 9; i++)
        {
            missing_array[i] = 0;
        }
        for (i = 0; i < 9; i++)
        {
            game_board[i] = main_board[i];
        }
        i = 0;
        while (i < level * 2 + 1)
        {
            int r = rand() % 3;
            int c = rand() % 3;
            if (game_board[3 * r + c] != '?')
            {
                missing_array[game_board[3 * r + c] - 1] = game_board[3 * r + c];
                game_board[3 * r + c] = '?';
                i++;
            }
        }

    } while (1);
}