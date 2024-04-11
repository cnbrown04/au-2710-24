/* Name: Caleb Brown
 Auburn ID: cnb0063
 Filename: project3_Brown_cnb0063.cpp
 To compile on JetBrains: Use the compile button in the top right of the window.
 To compile using Auburn Server: Login to the auburn server after uploading the file
    and then use the command g++ project3_Brown_cnb0063.cpp -o project3 and then
    use the command ./project3 to execute the compiled program.

 Sources: cplusplus.com (https://cplusplus.com/reference/) (https://cplusplus.com/reference/iomanip/)*/

# include <fstream>
# include <iostream>
# include <string>
# include <unistd.h>
using namespace std;

// Maximum size of the arrays.
const int MAX_SIZE = 100;

// Initialize the functions.
int readFile(int inputArray[], ifstream& instream);
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);
void writeFile(int outputArray[], int outputArray_size, string name);

int readFile(int inputArray[], ifstream& instream) {
    if (instream.fail()) { // If the file failed to open.
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    int i = 0;
    instream >> inputArray[i];
    while (!instream.eof()) {
        i++;
        instream >> inputArray[i];
    }
    return i;
}
// Sorts the array into the final order using the example provided.
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
    int arr1 = 0, arr2 = 0, i = 0, k = 0;
    while (arr1 < inputArray1_size && arr2 < inputArray2_size) {
        if (inputArray1[arr1] <= inputArray2[arr2]) {
            outputArray[i] = inputArray1[arr1];
            arr1++;
        }
        else {
            outputArray[i] = inputArray2[arr2];
            arr2++;
        }
        i++;
    }

    if ( arr1 < inputArray1_size ) {
        for ( k = arr1; k < inputArray1_size; k++) {
            outputArray[i] = inputArray1[k];
            i++;
        }
    }
    else {
        for ( k = arr2; k < inputArray2_size; k++) {
            outputArray[i] = inputArray2[k];
            i++;
        }
    }
    return i;
}

// Writes the sorted output from the sort function to a output file.
void writeFile(int outputArray[], int outputArray_size, string name) {
    ofstream output; // Initialize an output stream.
    output.open(name.c_str());
    for (int i = 0; i < outputArray_size; i++) { // Loop each line and add to the file.
        output << outputArray[i] << endl;
    }
    output.close(); // Close the file.
}

// Main
int main() {
    // Using the example provided on the project form you flesh it out with the functions.
    int arraySize1 = 0, arraySize2 = 0;
    int ARRAY1[MAX_SIZE], ARRAY2[MAX_SIZE], outArray[MAX_SIZE];
    string file1, file2, outFile;

    cout << "*** Welcome to Caleb's sorting program ***" << endl;
    cout << "Enter the first input file name: ";
    cin >> file1;
    
    ifstream Stream;
    Stream.open(file1.c_str());
    arraySize1 = readFile(ARRAY1, Stream);
    if (arraySize1 < 0) {
        exit(1);
    }
    cout << endl << "The list of " << arraySize1 << " numbers in file " << file1 << " is: " << endl;
    for (int i = 0; i < arraySize1; i++) {
        cout << ARRAY1[i] << endl;
    }
    Stream.close();
    
    
    cout << endl << "Enter the second input file name: ";
    cin >> file2;
    
    ifstream Stream2;
    Stream2.open(file2.c_str());
    arraySize2 = readFile(ARRAY2, Stream2);
    if (arraySize2 < 0) {
        exit(1);
    }
    cout << endl << "The list of " << arraySize2 << " numbers in file " << file2 << " is: " << endl;
    for (int i = 0; i < arraySize2; i++) {
        cout << ARRAY2[i] << endl;
    }
    Stream2.close();
    
    
    int outSize = sort(ARRAY1, arraySize1, ARRAY2, arraySize2, outArray);
    cout << endl << "The sorted list of " << outSize << " numbers is: ";
    for (int i = 0; i < outSize; i++) {
        cout << outArray[i] << " ";
    }
    
    cout << endl << "Enter the output file name: ";
    cin >> outFile;
    writeFile(outArray, outSize, outFile);
    cout << endl << "*** Please check the new file - " << outFile << " ***" << endl;
    cout << "*** Goodbye. ***" << endl;

    Stream.close();
    Stream2.close();
    return 0;
}