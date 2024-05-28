#include <iostream>
#include <vector>
#include <cctype>
#include <stdexcept> 
using namespace std;


bool checkWin(const vector<vector<char>>& board, char player) {
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

int main() {
    setlocale(LC_ALL, "Ukrainian");
    vector<vector<char>> board(3, vector<char>(3, ' '));
    string move;
    char currentPlayer = 'X';
    bool gameWon = false;

    while (!gameWon) {
        drawBoard(board);
        cout << "гравець " << currentPlayer << ", введіть свій хід (e.g., 1A, 2B): ";
        cin >> move;

        try {
            pair<int, int> coordinates = convertMove(move);
            int row = coordinates.first;
            int col = coordinates.second;

            if (board[row][col] != ' ') {
                cout << "Клітинка вже зайнята. Спробуйте знову.\n";
                continue;
            }

            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                drawBoard(board);
                cout << "Гравець " << currentPlayer << " переміг!\n";
                gameWon = true;
            }
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
        catch (const exception& e) {
            cout << e.what() << " Спробуйте знову.\n";
        }
    }

    return 0;
}