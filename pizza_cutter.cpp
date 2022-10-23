/*
The only thing I can think of that may be the cause of
the last two test not working is that maybe it is a 
constraint.
*/

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

//This function counts the number of non-repeated slices 
//and returns the number of pizza pieces
int count_slices(int data[ROW][COL], int iteration) {
    int slices = data[iteration][0];
    int pieces = 0;
    
    if (data[0][0] == 0) {
        pieces = 0;
    }
    else if (slices == 0) {
        pieces = 1;
    }
    else if (slices > 0) {
        
        for (int m = 0; (data[iteration][0] - m) > 0; m++) {
            
            if (data[iteration][m+1] < 0) {
                while (data[iteration][m+1] < 0) {
                    data[iteration][m+1] += 180;
                }
            }
            else if (data[iteration][m+1] > 0) {
                while (data[iteration][m+1] > 180) {
                    data[iteration][m+1] -= 180;
                }
            }
        }
        for (int n = 0; (data[iteration][0] - n) > 0; n++) {
            
            int m = 0;
            
            for (m = (n+1); (data[iteration][0] - m) > 0; m++) {
                if (data[iteration][n+1] == data[iteration][m+1]) {
                    slices--;
                    break;
                }
            }
        }
        pieces = slices + slices;
    }

    return pieces;
}

//This function calls the count_slices function 
//and prints the number of pizza pieces
void print_slices(int data[ROW][COL]) {

    for (int n = 0; (data[0][0] - n) > 0 ; n++) {
        int pieces = 0;

        pieces = count_slices(data, (n+1));
        if (pieces < 0) {
            pieces = 0;
        }
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