#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int roundRobin(string input, string output);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "Must include dataset and output file\n";
        return -1;
    }

    string input = argv[1];
    string output = argv[2];

    ifstream file(input);
    if (file.fail()) {
        cout << "Unable to read file";
        return -1;
    }
    file.close();

    if (argc == 4) {
        int rounds = atoi(argv[3]);
        cout << "Only running " << rounds << " round(s)\n";
        for (int i = 0; i < rounds; i++) {
            int ret = roundRobin(input, output);

            input = output;
            output[0]--;
            if (rounds % 2)
                output[0] += 2;

            if (ret == 1) {
                output[0]++;
                if (rounds % 2)
                    output[0] -= 2;
                cout << "Finished after " << rounds << " round(s)\n";
                return 0;
            }
            if (ret == -1) {
                output[0]++;
                if (rounds % 2)
                    output[0] -= 2;
                cout << "Unable to write to " << output << endl;
                return -1;
            }

            if (ret == 0) {
                cout << "Uhh not entirely sure what happened here? Try fewer "
                        "rounds\n";
                return 1;
            }
        }
        return 0;
    }

    bool keepOn = true;
    int rounds = 0;
    while (keepOn) {
        rounds++;
        int ret = roundRobin(input, output);

        input = output;

        output[0]--;
        if (rounds % 2)
            output[0] += 2;

        if (ret == 1) {
            keepOn = false;
            output[0]++;
            if (rounds % 2)
                output[0] -= 2;
        }
        if (ret == -1) {
            keepOn = false;
            output[0]++;
            if (rounds % 2)
                output[0] -= 2;
            cout << "Unable to write to " << output << endl;
            return -1;
        }

        if (ret == 0) {
            keepOn = false;
            cout << "Too many iterations, try starting from the second to last "
                    "file and run with 1 operation.\n";
            return 0;
        }
    }

    cout << "Successfully wrote to " << output << endl;
    return 0;
}

int roundRobin(string input, string output) {
    ifstream player1File(input);
    ofstream oFile(output);

    if (player1File.fail() || oFile.fail()) {
        cout << "Invalid files\n";
        return -1;
    }

    int numOfWins = 0;

    int count;
    player1File >> count;
    oFile << count << endl;
    player1File.ignore();

    for (int num1 = 0; num1 < count; num1++) {
        ifstream file(input);
        file >> count;
        file.ignore();

        int WL = 0;

        string player1S;
        getline(player1File, player1S);
        stringstream player1SS(player1S);

        int player1[10] = {0};

        int player1T = 0;
        for (int i = 0; i < 10; i++) {
            player1SS >> player1[i];
            player1T += player1[i];
        }
        if (player1T != 100) {
            cout << "Player 1 does not add up to 100\n";
            return -1;
        }

        for (int num = 0; num < count; num++) {
            int player2[10] = {0};
            int player1Score = 0;
            int player2Score = 0;
            int player2T = 0;

            string player2S;
            getline(file, player2S);
            stringstream player2SS(player2S);

            for (int i = 0; i < 10; i++) {
                player2SS >> player2[i];
                player2T += player2[i];
            }

            if (player2T != 100) {
                cout << "Must place down 100 soldiers for P2, invalid file\n";
                return -1;
            }

            for (int i = 0; i < 10; i++) {
                if (player2[i] > player1[i]) {
                    player2Score += (i + 1);
                } else if (player1[i] > player2[i]) {
                    player1Score += (i + 1);
                }

                if (player2Score >= 20) {
                    WL--;
                    break;
                }
                if (player1Score >= 20) {
                    WL++;
                    break;
                }
            }
        }

        file.close();

        if (WL > 0) {
            // that is, print out the line IFF it wins more than it loses
            // against the test set (all posibilities)
            for (int i = 0; i < 10; i++) {
                oFile << player1[i] << " ";
            }
            oFile << 100 << endl;
            numOfWins++;
        }
    }
    player1File.close();
    oFile.close();

    ifstream newFile(output);
    string *arr = new string[numOfWins + 1];
    for (int i = 0; i <= numOfWins; i++) {
        getline(newFile, arr[i]);
    }
    arr[0] = to_string(numOfWins);

    newFile.close();

    ofstream overwrite(output);

    for (int i = 0; i <= numOfWins; i++) {
        overwrite << arr[i] << endl;
    }

    overwrite.close();

    delete[] arr;

    return numOfWins;
}
