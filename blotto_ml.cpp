#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Must include dataset and output file\n";
        return -1;
    }

    ifstream file(argv[1]);
    ofstream oFile(argv[2]);

    if (file.fail()) {
        cout << "Invalid files\n";
        return -1;
    }

    int winner = 0;

    int count;
    file >> count;
    file.ignore();
    int player1[10] = {0};
    int player2[10] = {0};

    for (int num = 0; num < count; num++) {
        int player1Score = 0;
        int player2Score = 0;
        int player1T = 0;
        int player2T = 0;

        string player1S, player2S;
        if (winner == 2 || num == 0 || winner == 0) {
            getline(file, player1S);
            //cout << "Read player 1\n";
        }
        if (winner == 1 || num == 0) {
            getline(file, player2S);
            //cout << "Read player 2\n";
        }

        stringstream player1SS(player1S);
        stringstream player2SS(player2S);

        for (int i = 0; i < 10; i++) {
            if (winner == 2 || num == 0 || winner == 0)
                player1SS >> player1[i];
            if (winner == 1 || num == 0)
                player2SS >> player2[i];

            player1T += player1[i];
            player2T += player2[i];
        }

        if (player1T != 100 || player2T != 100) {
            cout << "Must place down 100 soldiers, invalid file\n";
            return -1;
        }

        winner = 0;

        for (int i = 0; i < 10; i++) {
            if (player2[i] > player1[i]) {
                //cout << "Player 2 won " << i << "\n";
                player2Score += i;
            } else if (player1[i] > player2[i]) {
                //cout << "Player 1 won " << i << "\n";
                player1Score += i;
            } else {
                //cout << "It was a tie! No points assigned\n";
            }

            //cout << "Score: Player 1: " << player1Score << "\tPlayer 2: " << player2Score << "\n";

            if (player2Score >= 20) {
                oFile << "Winning nums: ";
                for (int j = 0; j < 10; j++) {
                    oFile << player2[j] << " ";
                }
                oFile << endl;
                //cout << "\nPlayer 2 won!\n\n";
                winner = 2;
                break;
            } else if (player1Score >= 20) {
                oFile << "Winning nums: ";
                for (int j = 0; j < 10; j++) {
                    oFile << player1[j] << " ";
                }
                oFile << endl;
                //cout << "\nPlayer 1 won!\n\n";
                winner = 1;
                break;
            }
        }
        if (!winner) {
            oFile << "Not enough values were different, so it's a tie!\n\n";
            winner = 0;
        }
    }

    oFile << "Finished!\n";
}