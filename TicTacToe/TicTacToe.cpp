#include <iostream>
char board[3][3]{
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}};

void displayboard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << board[i][j];
            if (j < 2)
                std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 2)
            std::cout << "----------" << std::endl;
    }
}

bool winner(char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool draw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void Play()
{
    char CurrentPlayer = 'X';
    int row, col;
    bool condition = true;
    while (condition)
    {
        displayboard();
        std::cout << "Player " << CurrentPlayer << " Pick your move 0-2" << std::endl;;
        std::cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
        {
            std::cout << "Invalid Move, Try Again" << std::endl;
            continue;
        }

        board[row][col] = CurrentPlayer;

        if (winner(CurrentPlayer))
        {
            displayboard();
            std::cout << "Player " << CurrentPlayer << " Wins" << std::endl;
            break;
        }
        if (draw())
        {
            displayboard();
            std::cout << "It's a draw!\n";
            condition = false;
            break;
        }

        // Switch player
        CurrentPlayer = (CurrentPlayer == 'X') ? 'O' : 'X';
    }
}


int main()
{
    Play();
    return 0;
}
