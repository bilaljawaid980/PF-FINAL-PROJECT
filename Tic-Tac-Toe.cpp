#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;

char slots[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int isComputer = 0;

int computerChoice();

int confirmChoice(int ch);
void printTicTacToe();
void resetSlots();

int checkwin();
void board();

int main()
{
    int player = 1, i, choice;
    char mark, continueGame = 'y';

    srand(time(0)); // Use for Generating Random Number Each Time.

    do
    {
        isComputer = 0;
        player = 1;
        resetSlots();
        system("cls");
        printTicTacToe();

        do
        {
            cout << "\nWho do you want to play with?";
            cout << "\n1- Computer\n2- 2nd Player";
            cout << "\nEnter your choice: ";
            cin >> isComputer;

            if (isComputer <= 0 || isComputer > 2)
            {
                cout << "\nPlease choose between 1 and 2";
            }
        } while (isComputer <= 0 || isComputer > 2);

        do
        {
            board();
            player = (player % 2) ? 1 : 2;

            if (isComputer == 1 && player != 1)
            {
                choice = computerChoice();
                cout << "Computer Choosed: " << choice;
                std::this_thread::sleep_for(2s);
            }
            else
            {
                do
                {
                    if (isComputer == 1)
                    {
                        cout << "Player enter a number:  ";
                    }
                    else
                    {
                        cout << "Player " << player << ", enter a number:  ";
                    }
                    cin >> choice;

                    if (confirmChoice(choice) == 0)
                    {
                        cout << "Please choose a differnt number " << choice << " is alreday marked with " << slots[choice] << endl;
                    }

                } while (confirmChoice(choice) == 0);
            }

            mark = (player == 1) ? 'X' : 'O';

            if (choice == 1 && slots[1] == '1')
                slots[1] = mark;

            else if (choice == 2 && slots[2] == '2')
                slots[2] = mark;

            else if (choice == 3 && slots[3] == '3')
                slots[3] = mark;

            else if (choice == 4 && slots[4] == '4')
                slots[4] = mark;

            else if (choice == 5 && slots[5] == '5')
                slots[5] = mark;

            else if (choice == 6 && slots[6] == '6')
                slots[6] = mark;

            else if (choice == 7 && slots[7] == '7')
                slots[7] = mark;

            else if (choice == 8 && slots[8] == '8')
                slots[8] = mark;

            else if (choice == 9 && slots[9] == '9')
                slots[9] = mark;

            else
            {
                player--;
            }

            i = checkwin();

            player++;
        } while (i == -1);

        board();

        if (i == 1)
        {

            if (isComputer == 1 && --player != 1)
            {
                cout << "\t\t\t\t\t\t     ======================\n";
                cout << "\t\t\t\t\t\t    |                      |\n";
                cout << "\t\t\t\t\t\t    |     Computer Wins    |\n";
                cout << "\t\t\t\t\t\t    |                      |\n";
                cout << "\t\t\t\t\t\t     ======================";
            }
            else
            {
                cout << "\t\t\t\t\t\t     ======================\n";
                cout << "\t\t\t\t\t\t    |                      |\n";
                if (isComputer == 1)
                {
                    cout << "\t\t\t\t\t\t    |     Player Wins      |\n";
                }
                else
                {
                    cout << "\t\t\t\t\t\t    |     Player " << --player << " Wins    |\n";
                }
                cout << "\t\t\t\t\t\t    |                      |\n";
                cout << "\t\t\t\t\t\t     ======================\n";
            }
        }
        else
        {
            cout << "==>\aGame draw";
        }

        // cin.ignore();
        // cin.get();

        cout << "\n\nDo you want to play again?\n";
        cout << "Enter y to continue: ";
        cin >> continueGame;

    } while (tolower(continueGame) == 'y');

    return 0;
}

int checkwin()
{
    if (slots[1] == slots[2] && slots[2] == slots[3])
        return 1;

    else if (slots[4] == slots[5] && slots[5] == slots[6])

        return 1;
    else if (slots[7] == slots[8] && slots[8] == slots[9])

        return 1;
    else if (slots[1] == slots[4] && slots[4] == slots[7])

        return 1;
    else if (slots[2] == slots[5] && slots[5] == slots[8])

        return 1;
    else if (slots[3] == slots[6] && slots[6] == slots[9])

        return 1;
    else if (slots[1] == slots[5] && slots[5] == slots[9])

        return 1;
    else if (slots[3] == slots[5] && slots[5] == slots[7])

        return 1;
    else if (slots[1] != '1' && slots[2] != '2' && slots[3] != '3' && slots[4] != '4' && slots[5] != '5' && slots[6] != '6' && slots[7] != '7' && slots[8] != '8' && slots[9] != '9')

        return 0;
    else
        return -1;
}

void board()
{
    system("cls");
    cout << "\t\t\t\t====================================================================";
    cout << "\n\n\t\t\t\t\t\t\t   Tic Tac Toe\n\n";
    cout << "\t\t\t\t====================================================================";

    if (isComputer == 1)
    {
        cout
            << "\n\t\t\t\t\t\t\tYou (X)  -  Computer (O)" << endl
            << endl;
    }
    else
    {
        cout
            << "\n\t\t\t\t\t\t\tPlayer 1 (X)  -  Player 2 (O)" << endl
            << endl;
    }

    cout << "\t\t\t\t\t\t\t     |     |     " << endl;
    cout << "\t\t\t\t\t\t\t  " << slots[1] << "  |  " << slots[2] << "  |  " << slots[3] << endl;

    cout << "\t\t\t\t\t\t\t_____|_____|_____" << endl;
    cout << "\t\t\t\t\t\t\t     |     |     " << endl;

    cout << "\t\t\t\t\t\t\t  " << slots[4] << "  |  " << slots[5] << "  |  " << slots[6] << endl;

    cout << "\t\t\t\t\t\t\t_____|_____|_____" << endl;
    cout << "\t\t\t\t\t\t\t     |     |     " << endl;

    cout << "\t\t\t\t\t\t\t  " << slots[7] << "  |  " << slots[8] << "  |  " << slots[9] << endl;

    cout << "\t\t\t\t\t\t\t     |     |     " << endl
         << endl;
}

void printTicTacToe()
{
    cout << "\t\t\t\t ====================================================================";
    cout << "\n\t\t\t\t|                                                                    |";
    cout << "\n\t\t\t\t|                                                                    |";
    cout << "\n\t\t\t\t|\t\t              Tic Tac Toe                            |";
    cout << "\n\t\t\t\t|                                                                    |";
    cout << "\n\t\t\t\t|                                                                    |";
    cout << "\n\t\t\t\t ====================================================================";
};

int computerChoice()
{
    int x;

    do
    {
        x = (rand() % 9) + 1;
    } while (slots[x] == 'X' || slots[x] == 'O');

    return x;
}

int confirmChoice(int ch)
{
    if (slots[ch] == 'X' || slots[ch] == 'O' || ch > 9 || ch <= 0)
    {
        return 0;
    }
    else
        return 1;
}

void resetSlots()
{
    char slotX[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (int i = 0; i < 10; i++)
    {
        slots[i] = slotX[i];
    }
};