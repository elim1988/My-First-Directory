#include <iostream>

#define ROW (31)
#define COL (10001)

//This function collects the input data for Pizza Cutter program
void save_input(int data[ROW][COL]) {
        std::cin >> data[0][0];
    for (int n = 0; (data[0][0] - n) > 0 ; n++) {
        std::cin >> data[n+1][0];
        for (int m = 0; (data[n+1][0] - m) > 0; m++) {
            std::cin >> data[n+1][m+1];
        }
    }
}

int count_slices(int data[ROW][COL], int iteration) {
    int D[COL] = {};
    int slices = data[iteration][0];
    int pieces = 0;
    
    if (slices == 0) {
        pieces = 1;
    }
    else {
        
        for (int m = 0; (data[iteration][0] - m) > 0; m++) {
            D[m] = data[iteration][m+1];
            
            while (D[m] < 0) {
                D[m] = -D[m];
            }
            while (D[m] > 180) {
                D[m] -= 180;
            }
        }
        for (int n = 0; (slices - n) > 0; n++) {
            for (int m = 0; (slices - m) > 0; m++) {
                if ((D[n] == D[m]) && (n != m)) {
                    slices--;
                    for (int i = m; (slices - i); i++) {
                        D[i] = D[i+1];
                    }
                }
            }
        }
        pieces = slices + slices;
    }
    
    return pieces;
}

//This function takes the slicing offsets and prints number of pizza slices
void print_slices(int data[ROW][COL]) {

    for (int n = 0; (data[0][0] - n) > 0 ; ++n) {
        int pieces = 0;

        pieces = count_slices(data, (n+1));
        
        if (n == 0) {
            std::cout << pieces;
        }
        else {
            std::cout << std::endl << pieces;
        }
    }
}

//This is main
int main() {
    int data[ROW][COL] = {};
    save_input(data);
    print_slices(data);

    return 0;
}
