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

    int player1[100] = {0};
    int player1Count[10] = {0};
    int player1Score = 0;
    int player2[100] = {0};
    int player2Count[10] = {0};
    int player2Score = 0;

    for (int i = 0; i < 100; i++) {
        int temp;
        player1File >> temp;
        player1[i] = temp;
        player1Count[temp]++;
        player2File >> temp;
        player2[i] = temp;
        player2Count[temp]++;
    }

    for (int i = 0; i < 10; i++) {
        if (player2Count[i] > player1Count[i]) {
            cout << "Player 2 won " << i << "\n";
            player2Score += i;
        } else if (player1Count[i] > player2Count[i]) {
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
