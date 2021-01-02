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
        int [] mainBoard = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int [] missingArray;
        int [] gameBoard;
        int [] tempBoard;
        int [] rowResults;
        int [] columnResults;
        char [] operatorsArray;
        int i,j;
        int randNum, temp1;
        int level;
        int checkGame;
        int playAgain;
        int missingCount;
        do {
            checkGame=1;
            level=0;
            System.out.println("Welcome to Nine-Gaps game! By Harnoor Singh Reen \n");
            System.out.println("*****************************\n");
            System.out.println("      *****************      \n");
            System.out.println("            *****            \n");
            System.out.println("              *              \n");
            do {
                System.out.println("Choose the level of difficulty (1-Beginner, 2-Intermediate, 3-Advanced, 4-Expert):");
            }while (true);
        }while (true);
    }
}
