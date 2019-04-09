#include <cstdlib>
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
    oFile << count << endl;
    file.ignore();
    int player1[10] = {0};
    int player2[10] = {0};
    int num = 0;

    while (!file.fail()) {
        int player1Score = 0;
        int player2Score = 0;
        int player1T = 0;
        int player2T = 0;

        string player1S, player2S;
        if (winner == 2 || num == 0 || winner == 0) {
            getline(file, player1S);
        }
        if (winner == 1 || num == 0) {
            getline(file, player2S);
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
                player2Score += i;
            } else if (player1[i] > player2[i]) {
                player1Score += i;
            }

            if (player2Score >= 20) {
                for (int j = 0; j < 10; j++) {
                    oFile << player2[j] << " ";
                }
                oFile << 100 << endl;
                winner = 2;
                break;
            } else if (player1Score >= 20) {
                for (int j = 0; j < 10; j++) {
                    oFile << player1[j] << " ";
                }
                oFile << 100 << endl;
                winner = 1;
                break;
            }
        }
        if (!winner) {
            if (player2Score > player1Score)
                winner = 2;

            if (player1Score > player2Score)
                winner = 1;
        }
        num++;
    }
}