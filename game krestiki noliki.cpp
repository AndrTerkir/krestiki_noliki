#include <iostream>
#include <cstdlib>
#include <clocale>

using namespace std;

void risovat_pole(char p[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << p[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool pobeda(char p[3][3], char ig) {
    for (int i = 0; i < 3; i++) {
        if (p[i][0] == ig && p[i][1] == ig && p[i][2] == ig) return true;
        if (p[0][i] == ig && p[1][i] == ig && p[2][i] == ig) return true;
    }
    if (p[0][0] == ig && p[1][1] == ig && p[2][2] == ig) return true;
    if (p[0][2] == ig && p[1][1] == ig && p[2][0] == ig) return true;
    return false;
}

bool hod(char p[3][3], int n, char ig) {
    int r = (n - 1) / 3;
    int c = (n - 1) % 3;
    if (p[r][c] != 'X' && p[r][c] != 'O') {
        p[r][c] = ig;
        return true;
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "Russian");
    char pole[3][3];
    int num = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            pole[i][j] = '0' + num++;

    char igrok = 'X';
    bool konec = false;

    while (!konec) {
        system("cls");
        risovat_pole(pole);
        int v;
        cout << "Игрок " << igrok << ", выберите клетку (1-9): ";
        cin >> v;
        if (v < 1 || v > 9) {
            cout << "Неверный номер!\n";
            system("pause");
            continue;
        }
        if (!hod(pole, v, igrok)) {
            cout << "Клетка занята!\n";
            system("pause");
            continue;
        }
        if (pobeda(pole, igrok)) {
            system("cls");
            risovat_pole(pole);
            cout << "Игрок " << igrok << " победил!\n";
            konec = true;
        }
        else {
            bool nichya = true;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (pole[i][j] != 'X' && pole[i][j] != 'O')
                        nichya = false;
            if (nichya) {
                system("cls");
                risovat_pole(pole);
                cout << "Ничья!\n";
                konec = true;
            }
            else {
                igrok = (igrok == 'X') ? 'O' : 'X';
            }
        }
    }
    cout << "\nНажмите Enter для выхода...";
    int _;
    cin >> _;
    return 0;
}