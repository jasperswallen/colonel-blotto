#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Must include 2 files with player moves\n";
        return -1;
    }

    ifstream player1File(argv[1]);
    ifstream player2File(argv[2]);

    if (player1File.fail() || player2File.fail()) {
        cout << "Invalid files\n";
        return -1;
    }

    int player1[10] = {0};
    int player2[10] = {0};
    int player1Score, player2Score = 0;

    for (int i = 0; i < 10; i++) {
        player1File >> player1[i];
        player2File >> player2[i];
    }

    int player1T, player2T = 0;
    for (int i = 0; i < 10; i ++) {
        player1T += player1[i];
        player2T += player2[i];
    }

    if (player1T != 100 || player2T != 100) {
        cout << "Must place down 100 soldiers\n";
        return -1;
    }

    for (int i = 0; i < 10; i++) {
        if (player2[i] > player1[i]) {
            cout << "Player 2 won " << i << "\n";
            player2Score += i;
        } else if (player1[i] > player2[i]) {
            cout << "Player 1 won " << i << "\n";
            player1Score += i;
        } else {
            cout << "It was a tie! No points assigned\n";
        }

        cout << "Score: Player 1: " << player1Score
             << "\tPlayer 2: " << player2Score << "\n";

        if (player2Score >= 20) {
            cout << "Player 2 won!\n";
            return 0;
        } else if (player1Score >= 20) {
            cout << "Player 1 won!\n";
            return 0;
        }
    }
    cout << "Not enough values were different, so it's a tie!\n";
    return 0;
}