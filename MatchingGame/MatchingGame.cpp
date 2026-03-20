#include <iostream>   // for input and output
#include <cstdlib>    // for rand() and srand()
#include <ctime>      // to seed random number with time
#include <iomanip>    // to format board output with spacing
using namespace std;

// Constants to define board size and total matching pairs
const int SIZE = 4;
const int TOTAL_PAIRS = 8;

// Function declarations (define them later)
void shuffleBoard(char board[][SIZE]);
void showBoard(char board[][SIZE], bool revealed[][SIZE]);
bool isGameOver(bool revealed[][SIZE]);
void getCoordinates(int &row, int &col, string prompt);

int main() {
    srand(time(0));  // Seeds random generator to make board different every time

    char board[SIZE][SIZE];           // Holds the actual card values (like A, B, etc.)
    bool revealed[SIZE][SIZE] = {false};  // Tracks which cards are currently flipped face up

    shuffleBoard(board);  // Randomize card placements

    int moves = 0;  // Count how many turns the player takes

    cout << "Welcome to Memory Match! Try to find all matching pairs." << endl;

    // Main game loop
    while (!isGameOver(revealed)) {
        int r1, c1, r2, c2;

        showBoard(board, revealed);  // Display the current state of the board

        // Ask for first card
        getCoordinates(r1, c1, "Pick first card (row and column): ");
        revealed[r1][c1] = true;     // Temporarily flip the first card
        showBoard(board, revealed);  // Show board with first card flipped

        // Ask for second card
        getCoordinates(r2, c2, "Pick second card (row and column): ");
        revealed[r2][c2] = true;     // Temporarily flip the second card
        showBoard(board, revealed);  // Show board with both cards flipped

        moves++;  // Increase turn count

        // Check if the cards match
        if (board[r1][c1] != board[r2][c2]) {
            cout << "No match! Try again." << endl;

            // Flip them back down after a short pause (optional: add a sleep)
            revealed[r1][c1] = false;
            revealed[r2][c2] = false;
        } else {
            cout << "Nice! You found a match." << endl;
        }
    }

    // Game complete
    cout << "You matched all the pairs in " << moves << " moves!" << endl;

    return 0;
}

// This function fills the board with pairs of letters (A–H) and shuffles them randomly
void shuffleBoard(char board[][SIZE]) {
    char values[TOTAL_PAIRS * 2] = {
        'A','A','B','B','C','C','D','D',
        'E','E','F','F','G','G','H','H'
    };

    // Shuffle values using a basic swap method
    for (int i = 0; i < TOTAL_PAIRS * 2; i++) {
        int r = rand() % (TOTAL_PAIRS * 2);
        swap(values[i], values[r]);
    }

    // Fill the 4x4 board with the shuffled values
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = values[index++];
        }
    }
}

// This function prints the game board
// If a card is revealed, it shows the letter, otherwise it shows an asterisk (*)
void showBoard(char board[][SIZE], bool revealed[][SIZE]) {
    cout << "\n   ";
    for (int j = 0; j < SIZE; j++) {
        cout << setw(3) << j;  // print column headers
    }
    cout << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << setw(2) << i << " ";  // print row number
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                cout << setw(3) << board[i][j];  // show actual card
            } else {
                cout << setw(3) << '*';  // hide card
            }
        }
        cout << endl;
    }
}

// Checks if all cards are revealed (game over condition)
bool isGameOver(bool revealed[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!revealed[i][j]) return false;  // if any card is still hidden, keep playing
        }
    }
    return true;
}

// This function asks the player for a valid row and column input
void getCoordinates(int &row, int &col, string prompt) {
    cout << prompt;
    cin >> row >> col;

    // Make sure input is inside the board boundaries
    while (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        cout << "Invalid coordinates. Try again: ";
        cin >> row >> col;
    }
}
