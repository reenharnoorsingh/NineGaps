import java.util.Random;
import java.util.Scanner;

public class NineGaps {
    public static int calculate(int a, char x, int b, char y, int c) {
        int result = 0;
        if (x == '+') {
            if (y == '+')
                result = a + b + c;
            else if (y == '-')
                result = a + b - c;
            else if (y == '*')
                result = a + b * c;
        } else if (x == '-') {
            if (y == '+')
                result = a - b + c;
            else if (y == '-')
                result = a - b - c;
            else if (y == '*')
                result = a - b * c;
        } else if (x == '*') {
            if (y == '+')
                result = a * b + c;
            else if (y == '-')
                result = a * b - c;
            else if (y == '*')
                result = a * b * c;
        } else {
            System.out.println("Something went wrong");
        }
        return result;
    }

    public static void main(String[] args) {
        int[] mainBoard = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int[] missingArray = new int[9];
        int[] gameBoard = new int[9];
        int[] tempBoard = new int[9];
        int[] rowResults = new int[3];
        int[] columnResults = new int[3];
        char[] operatorsArray = new char[12];
        int i, j;
        int randNum, temp1;
        int level;
        char checkGame;
        int playAgain;
        int missingCount;
        do {
            checkGame = 1;
            level = 0;
            System.out.println("Welcome to Nine-Gaps game! By Harnoor Singh Reen \n");
            System.out.println("*****************************\n");
            System.out.println("      *****************      \n");
            System.out.println("            *****            \n");
            System.out.println("              *              \n");
            do {
                System.out.println("Choose the level of difficulty (1-Beginner, 2-Intermediate, 3-Advanced, 4-Expert):");
                Scanner sc = new Scanner(System.in);
                level = sc.nextInt();
                if ((level < 1) || (level > 4)) {
                    System.out.println("The entered value is not valid");
                } else {
                    switch (level) {
                        case 1:
                            System.out.println("Beginner Level");
                            break;
                        case 2:
                            System.out.println("Intermediate Level");
                            break;
                        case 3:
                            System.out.println("Advanced Level");
                            break;
                        case 4:
                            System.out.println("Expert Level");
                            break;
                        default:
                            break;
                    }
                    // break;
                }
                break;
            } while (true);
            //Generation of a random main board by shuffling the mainBoard
            for (i = 0; i < 9; i++) {
                int temp = mainBoard[i];
                Random rand = new Random();
                int randomIndex = rand.nextInt(9) + 1;

                mainBoard[i] = mainBoard[randomIndex];
                mainBoard[randomIndex] = temp;
            }
            //Generation of random operators ( + , - , x ) with number 1,2,3 representing addition, subtraction and multiplication respectively
            int num;
            for (i = 0; i < 12; i++) {
                Random rand = new Random();
                num = rand.nextInt(3) + 1;
                if (num == 1)
                    operatorsArray[i] = '+';
                else if (num == 2)
                    operatorsArray[i] = '-';
                else if (num == 3)
                    operatorsArray[i] = '*';
            }
            //Calculate the results in columns and rows, the creation of the game board
            rowResults[0] = calculate(mainBoard[0], operatorsArray[0], mainBoard[1], operatorsArray[1], mainBoard[2]);
            rowResults[1] = calculate(mainBoard[3], operatorsArray[2], mainBoard[4], operatorsArray[3], mainBoard[5]);
            rowResults[2] = calculate(mainBoard[6], operatorsArray[4], mainBoard[7], operatorsArray[5], mainBoard[8]);
            columnResults[0] = calculate(mainBoard[0], operatorsArray[6], mainBoard[3], operatorsArray[9], mainBoard[6]);
            columnResults[1] = calculate(mainBoard[1], operatorsArray[7], mainBoard[4], operatorsArray[10], mainBoard[7]);
            columnResults[2] = calculate(mainBoard[2], operatorsArray[8], mainBoard[5], operatorsArray[11], mainBoard[8]);
            //Copying the mainBoard into gameBoard
            for (i = 0; i < 9; i++) {
                gameBoard[i] = mainBoard[i];
            }
            // Based on the selected level, 3 or 5 or 7 board values will be hidden.
            i = 0;
            while (i < level * 2 + 1) {
                Random rand = new Random();
                int r = rand.nextInt(3);
                int c = rand.nextInt(3);
                if (gameBoard[3 * r + c] != '?') {
                    missingArray[gameBoard[3 * r + c] - 1] = gameBoard[3 * r + c];
                    gameBoard[3 * r + c] = '?';
                    i++;
                }
            }
            //Copying game board to a temporary board
            for (i = 0; i < 9; i++) {
                tempBoard[i] = gameBoard[i];
            }
            //The inner loop to get values from the user
            do {
                // Display the game board after each update
                // Display the game board after each update
                System.out.println("Game Board:\n");
                System.out.println("---------------------------------------------------\n");
                for (i = 0; i < 3; i++) {
                    if (i > 0) { // show the column opertors
                        for (j = 0; j < 3; j++) {
                            System.out.printf(" %c\t\t", operatorsArray[3 * (i + 1) + j]);
                        }
                        System.out.println();
                    }
                    for (j = 0; j < 3; j++) { // show the rows
                        if (gameBoard[(i * 3) + j] != '?')
                            System.out.printf(" %d\t ", tempBoard[(i * 3) + j]);
                        else if (gameBoard[(i * 3) + j] != tempBoard[(i * 3) + j]) {
                            System.out.printf(" %d?\t ", tempBoard[(i * 3) + j]);
                        } else
                            System.out.print(" ?\t ");
                        if (j < 2)
                            System.out.printf(" %c\t", operatorsArray[(i * 2) + j]);
                        else
                            System.out.printf("= %d", rowResults[i]); // show the rows results
                    }
                    System.out.println();
                    if (i == 2)
                        System.out.println(" =\t\t =\t\t =\n");
                }
                for (i = 0; i < 3; i++) // show the columnar results
                    System.out.printf(" %d\t\t", columnResults[i]);
                System.out.println("\n---------------------------------------------------\n");
                ////////////////////////////////////////////////////////
                //Displaying the missing values and updating the missing_count variable      (COMPLETE THIS PART)
                missingCount = 0;
                for (i = 0; i < 9; i++) {
                    if (missingArray[i] != 0) {
                        System.out.printf("%d\t", missingArray[i]);
                        missingCount++;
                    }
                }
                System.out.println();
                /////////////////////////////////////////////////////////
                //Break if the missing values are empty      (COMPLETE THIS PART)
                if (missingCount == 0) {
                    break;
                }
                /////////////////////////////////////////////////////
                // Get user's guess (location and value) and check inputs' validity
                System.out.println("Enter a row number (1-3), column(1-3), value(One of the missing values):\n");
                Scanner scan = new Scanner(System.in);
                int r, v, c = scan.nextInt();
                if (r == 0 || c == 0 || v == 0)
                    break;
                if (r < 1 || r > 3 || c < 1 || c > 3) {
                    System.out.println("Invalid row and/or column numbers. Try again.");
                    continue;
                }
                if (v < 1 || v > 9) {
                    System.out.println("Invalid cell value. Try again.");
                    continue;
                }
                if (missingArray[v - 1] < 1) {
                    System.out.println("This value is already there. Try again.");
                    continue;
                }
                // If the selected cell is changeable, add the value into the cell and remove it from the missing values, in other case show an error and repeat the inner loop.
                //Also checking the values
                int ch = 0;
                switch (r) {
                    case 1:
                        for (i = 0; i < 3; i++) {
                            if (mainBoard[i] == v) {
                                if (c == i + 1) {
                                    tempBoard[i] = v;
                                    ch = 1;
                                }
                            }
                        }
                        if (ch == 0)
                            System.out.println("\nIncorrect. Re-enter value\n");
                        break;
                    case 2:
                        for (i = 3; i < 6; i++) {
                            if (mainBoard[i] == v) {
                                if (c == i - 2) {
                                    tempBoard[i] = v;
                                    ch = 1;
                                }
                            }
                        }
                        if (ch == 0)
                            System.out.println("\nIncorrect. Re-enter value\n");
                        break;
                    case 3:
                        for (i = 6; i < 9; i++) {
                            if (mainBoard[i] == v) {
                                if (c == i - 5) {
                                    tempBoard[i] = v;
                                    ch = 1;
                                }
                            }
                        }
                        if (ch == 0)
                            System.out.println("\nIncorrect. Re-enter value\n");
                        break;
                    default:
                        System.out.println("\nIncorrect. Re-enter value\n");
                }
                if (ch == 1) {
                    if (missingArray[v - 1] >= 1) {
                        missingArray[v - 1] = 0;
                    } else
                        System.out.println("\nPlease try again\n");
                    continue;
                }
                if (missingCount == 0)
                    return 1;
            } while (true);
            if (checkGame)
                System.out.println("You Won!");
        } while (true);
    }
}
