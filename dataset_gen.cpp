#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    ofstream file("dataset.txt");
    if (file.fail() || argc != 2) {
        cout << "Unable to write\n";
        return -1;
    }

    int numOfIters = atoi(argv[1]);

    file << numOfIters << endl;

    srand(time(NULL));

    for (int x = 0; x < numOfIters; x++) {
        int numsoldiers[10] = {0};

        for (int j = 0; j < 100; j++) {
            numsoldiers[rand() % 10]++;
        }
        int sum = 0;
        for (int j = 0; j < 10; j++) {
            file << numsoldiers[j] << " ";
            sum += numsoldiers[j];
        }
        file << sum << endl;
    }

    cout << "Wrote to \"dataset.txt\"\n";

    return 0;
}