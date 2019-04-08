#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    ofstream file("dataset.txt");
    if (file.fail() || argc != 2) {
        cout << "Unable to write\n";
        return -1;
    }

    int numOfIters = atoi(argv[1]);

    file << numOfIters << endl;

    srand(time(NULL));

    int a, b, c, d, e, f, g, h, i, j = 0;

    for (int x = 0; x < numOfIters; x++) {
        a = rand() % 100;
        b = rand() % (100 - a);
        c = rand() % (100 - a - b);
        d = rand() % (100 - a - b - c);
        e = rand() % (100 - a - b - c - d);
        f = rand() % (100 - a - b - c - d - e);
        g = rand() % (100 - a - b - c - d - e - f);
        h = rand() % (100 - a - b - c - d - e - f - g);
        i = rand() % (100 - a - b - c - d - e - f - g - h);
        j = 100 - a - b - c - d - e - f - g - h - i;
        int sum = a+b+c+d+e+f+g+h+i+j;
        file << i << " " << g << " " << e << " " << c << " " << a << " " << b << " " << d << " " << f << " " << h << " " << j << " " << sum << endl;
    }
    
    cout << "Wrote to \"dataset.txt\"\n";

    return 0;
}