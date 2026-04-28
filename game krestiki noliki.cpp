#include <iostream>
#include <cstdlib>
#include <clocale>

using namespace std;


void displayBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}


bool checkWin(char board[3][3], char player) {
    
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}


bool makeMove(char board[3][3], int cell, char player) {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
        return true;
    }
    return false;
}


bool isDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");

    char board[3][3];
    int cellNum = 1;


    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = '0' + cellNum++;
        }
    }

    char currentPlayer = 'X';

    cout << "Добро пожаловать в Крестики-Нолики!\n";

    while (true) {
        system("cls");
        displayBoard(board);

        int choice;
        cout << "Игрок " << currentPlayer << ", выберите клетку (1–9): ";
        cin >> choice;

        if (choice < 1 || choice > 9) {
            cout << "Ошибка: введите число от 1 до 9!\n";
            system("pause");
            continue;
        }


        if (!makeMove(board, choice, currentPlayer)) {
            cout << "Эта клетка уже занята!\n";
            system("pause");
            continue;
        }


        if (checkWin(board, currentPlayer)) {
            system("cls");
            displayBoard(board);
            cout << "Поздравляем! Игрок " << currentPlayer << " победил!\n";
            break;
        }


        if (isDraw(board)) {
            system("cls");
            displayBoard(board);
            cout << "Ничья! Все клетки заполнены.\n";
            break;
        }


        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "\nИгра завершена. Нажмите Enter для выхода...\n";
    cin.ignore();
    cin.get();
    return 0;
}
