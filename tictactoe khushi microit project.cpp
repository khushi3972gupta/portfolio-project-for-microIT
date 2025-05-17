#include <iostream>
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;

class TicTacToe {
private:
    vector<vector<char> > board;
    char currentPlayer;

public:
    // Constructor to initialize the game
    TicTacToe() {
        board.resize(3, vector<char>(3, ' '));  // Initialize 3x3 board with spaces
        currentPlayer = 'X';  // Human starts
    }

    // Display the game board
    void displayBoard() {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << " " << board[i][j] << " ";
                if (j < 2) cout << "|";
            }
            cout << "\n";
            if (i < 2) cout << "---|---|---\n";
        }
        cout << "\n";
    }

    // Check for a win
    bool checkWin() {
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }
        return false;
    }

    // Check for draw
    bool isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;
    }
}
}
return true;
}

    // Switch current player
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Make a move
    bool makeMove(int row, int col) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            return true;
        }
        return false;
    }

    // Computer makes a random move
    void computerMove() {
        srand(time(0));
        int row, col;
        do {
            row = rand() % 3;
            col = rand() % 3;
        } while (board[row][col] != ' ');
        board[row][col] = currentPlayer;
        cout << "Computer (O) chose row " << row << " and column " << col << ".\n";
    }

    // Main game loop
    void playGame() {
        int row, col;
        while (true) {
            displayBoard();
            if (currentPlayer == 'X') {
                cout << "Player (X), enter row (0-2) and column (0-2): ";
                cin >> row >> col;
                if (!makeMove(row, col)) {
                    cout << "Invalid move! Try again.\n";
                    continue;
                }
            } else {
                computerMove();
            }

            if (checkWin()) {
                displayBoard();
                cout << (currentPlayer == 'X' ? "Player (X)" : "Computer (O)") << " wins!\n";
                break;
            }

            if (isBoardFull()) {
                displayBoard();
                cout << "It's a draw!\n";
                break;
            }

            switchPlayer();
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}

