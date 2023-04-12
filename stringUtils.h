#include<string>    //initializing 2 libraries string and iostream
#include<iostream>

// Forward declaration of the operations
void print(RBT *rbt, Heap *heap, int *args, string &output);       //declares a function named print that takes a pointer to an RBT object, a pointer to a Heap object, a pointer to an integer array args, and a reference to a string output as arguments and returns nothing (void).
void printRange(RBT *rbt, Heap *heap, int *args, string &output);  //declares a function named printRange that takes a pointer to an RBT object, a pointer to a Heap object, a pointer to an integer array args, and a reference to a string output as arguments and returns nothing (void).
void insertRide(RBT *rbt, Heap *heap, int* args, string &output);  // declares a function named insertRide that takes a pointer to an RBT object, a pointer to a Heap object, a pointer to an integer array args, and a reference to a string output as arguments and returns nothing (void).
void getNextRide(RBT *rbt, Heap *heap, string &output);            //declares a function named getNextRide that takes a pointer to an RBT object, a pointer to a Heap object, and a reference to a string output as arguments and returns nothing (void).
void cancelRide(RBT *rbt, Heap *heap, int* args, string &output);  //declares a function named cancelRide that takes a pointer to an RBT object, a pointer to a Heap object, a pointer to an integer array args, and a reference to a string output as arguments and returns nothing (void).
void updateTrip(RBT *rbt, Heap *heap, int* args, string &output);  //declares a function named updateTrip that takes a pointer to an RBT object, a pointer to a Heap object, a pointer to an integer array args, and a reference to a string output as arguments and returns nothing (void).
void parseInput(RBT *rbt, Heap *heap, int argc, char **argv, string &output);  //same just its for parse input


void parseargs3(int *args, string line) {
    int i = line.find_first_of("(") + 1, len = line.size() - i;
    string stragr = line.substr(i, len - 1);

    int firstComma = stragr.find_first_of(",");
    args[0] = stoi(stragr.substr(0, firstComma));

    int secondComma = stragr.find_last_of(",");
    if(secondComma == string::npos) return;
    args[1] = stoi(stragr.substr(firstComma + 1, secondComma - firstComma));
    args[2] = stoi(stragr.substr(secondComma + 1));
}

void parseargs2(int *args, string line) {
    int i = line.find_first_of("(") + 1, len = line.size() - i;
    string stragr = line.substr(i, len - 1);

    int firstComma = stragr.find_first_of(",");
    args[0] = stoi(stragr.substr(0, firstComma));
    args[1] = stoi(stragr.substr(firstComma + 1));    
}

void parseargs1(int *args, string line) {
    int i = line.find_first_of("(") + 1, len = line.size() - i;
    args[0] = stoi(line.substr(i, len - 1)); 
}

// this function process inputs given to parse parameter and calls operation functions  as required 
void processOperation(RBT *rbt, Heap *heap, string line, string operationPrefix, string &output) {
    int args[3];
    if(operationPrefix == "Pri") {
        if(line.find(",") != string::npos) {
            parseargs2(args, line);
            printRange(rbt, heap, args, output);
        } else {
            parseargs1(args, line);
            print(rbt, heap, args, output);
        }
    } else if(operationPrefix == "Ins") {
        parseargs3(args, line);
        insertRide(rbt, heap, args, output);
    } else if(operationPrefix == "Upd") {
        parseargs2(args, line);
        updateTrip(rbt, heap, args, output);
    } else if(operationPrefix == "Can") {
        parseargs1(args, line);
        cancelRide(rbt, heap, args, output);
    } else if(operationPrefix == "Get") {
        getNextRide(rbt, heap, output);
    }
}
