#include <iostream>
#include <iomanip>
using namespace std;

void getScores(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        double score = -1;
        while (score < 0) {
            cout << "Enter score " << i + 1 << ": " << endl;
            cin >> score;
            if (score < 0) {
                cout << "Please enter a positive score(no negative)!" << endl;
            }
            else {
                arr[i] = score;
            }
        }
    }
}

void sortScores(double* arr, int size) {
    // for (int i = 0; i < size; i++) {
    //     int temp = arr[i];
    //     if (arr[i] > arr[i + 1]) {
    //         arr[i] = arr[i + 1];
    //         arr[i + 1] = temp;
    //     }
    // }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            double temp = arr[j];
            if (arr[j] > arr[j + 1]) {
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

double calculateAverage(const double* arr, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

void printScores(double* arr, int size) {
    cout << fixed << setprecision(2) << "The sorted scores are: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {


    int size = -1;
    while(size < 1) {
        cout << "How many test scores would you like to enter? " << endl;
        cin >> size;
        if (size < 1) {
            cout << "That's not a valid size please try again!" << endl;
        }
    }

    double *scoresPtr = nullptr;
    scoresPtr = new double[size];

    //double * scoresPtr = new double[size];

    //call
    getScores(scoresPtr, size);

    sortScores(scoresPtr, size);

    double average = calculateAverage(scoresPtr, size);

    printScores(scoresPtr, size);
    cout << fixed << setprecision(2) << "The average score is: " << average << endl;

    delete [] scoresPtr;
    scoresPtr = nullptr;

    return 0;
}