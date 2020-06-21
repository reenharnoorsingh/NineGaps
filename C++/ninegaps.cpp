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
                    cout << "Beginner Level\n";
                    break;
                case 2:
                    cout << "Intermediate Level\n";
                    break;
                case 3:
                    cout << "Advanced Level\n";
                    break;

                case 4:
                   cout << "Expert Level\n";
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
        int temp_board[9];
        for (i = 0; i < 9; i++)
        {
            temp_board[i] = game_board[i];
        }
        do
        {
            printf("Game Board:\n");
            printf("---------------------------------------------------\n");
            for (i = 0; i < 3; i++)
            {
                if (i > 0)
                { // show the column opertors
                    for (j = 0; j < 3; j++)
                    {
                        printf(" %c\t\t", operators_array[3 * (i + 1) + j]);
                    }
                    printf("\n");
                }
                for (j = 0; j < 3; j++)
                { // show the rows
                    if (game_board[(i * 3) + j] != '?')
                        printf(" %d\t ", temp_board[(i * 3) + j]);
                    else if (game_board[(i * 3) + j] != temp_board[(i * 3) + j])
                    {
                        printf(" %d?\t ", temp_board[(i * 3) + j]);
                    }
                    else
                        printf(" ?\t ");
                    if (j < 2)
                        printf(" %c\t", operators_array[(i * 2) + j]);
                    else
                        printf("= %d", row_results[i]); // show the rows results
                }
                printf("\n");
                if (i == 2)
                    printf(" =\t\t =\t\t =\n");
            }
            for (i = 0; i < 3; i++) // show the columnar results
                printf(" %d\t\t", column_results[i]);
            printf("\n---------------------------------------------------\n");\
            missing_count = 0;
            for (i = 0; i < 9; i++)
            {
                if (missing_array[i] != 0)
                {
                    printf("%d\t", missing_array[i]);
                    missing_count++;
                }
            }
            cout << "\n";
            if (missing_count == 0)
            {
                break;
            }
            cout << "Enter a row number (1-3), column(1-3), value(One of the missing values):\n";
            int r, c, v;
            cin >> r >> c >> v;
            if (r == 0 || c == 0 || v == 0)
                break;
            if (r < 1 || r > 3 || c < 1 || c > 3)
            {
                cout << "Invalid row and/or column numbers. Try again.";
                continue;
            }
            if (v < 1 || v > 9)
            {
                cout << "Invalid cell value. Try again.";
                continue;
            }
            if (missing_array[v - 1] < 1)
            {
                cout << "This value is already there. Try again.";
                continue;
            }
            int ch = 0;
            switch (r)
            {
            case 1:
                for (i = 0; i < 3; i++)
                {
                    if (main_board[i] == v)
                    {
                        if (c == i + 1)
                        {
                            temp_board[i] = v;
                            ch = 1;
                        }
                    }
                }
                if (ch == 0)
                    cout << "\nIncorrect. Re-enter value\n";
                break;
            case 2:
                for (i = 3; i < 6; i++)
                {
                    if (main_board[i] == v)
                    {
                        if (c == i - 2)
                        {
                            temp_board[i] = v;
                            ch = 1;
                        }
                    }
                }
                if (ch == 0)
                    cout << "\nIncorrect. Re-enter value\n";
                break;
            case 3:
                for (i = 6; i < 9; i++)
                {
                    if (main_board[i] == v)
                    {
                        if (c == i - 5)
                        {
                            temp_board[i] = v;
                            ch = 1;
                        }
                    }
                }
                if (ch == 0)
                    cout << "\nIncorrect. Re-enter value\n";
                break;
            default:
                cout << "\nIncorrect. Re-enter value\n";
            }
            if(ch ==1)
            {
                if (missing_array[v - 1] >= 1)
                {
                    missing_array[v - 1] = 0;
                }
                else
                    cout<< "\nPlease try again\n";
                continue;
            }
            if(missing_count ==0)
                return 1;
        } while (1);
        if (check_game) //Displaying Winning/Losing Message
            cout<< "**** Congratulations!!!****\n ***You Won!!!!*** \n";
        else
        cout<<":( Sorry it is not correct :( \n";
        cout<<"#######################################\n";
        cout<<"   Do you want to play again? (Yes:1, No:0)\n"; //Asks the user to play again
        cout<<"#######################################\n";
        cin>> play_again;
        if (!play_again)
        {
            printf("Bye!");
            break;
        }
    } while (1);
}