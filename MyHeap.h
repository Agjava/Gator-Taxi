#include<iostream>        // to initalize header file and to insert data into a stream (output) or extract data from a stream (input) in c++
#include<math.h>
using namespace std;    //  It is the declarative part where the scope of identifiers like functions, the name of types, classes, variables, etc., are declared.
class RBTNode;            // declaration of the class RBTNode, which is used later in the code.
class HeapNode {           //initialization of HeapNode with default values
public :
    RBTNode *rbtNode;
    int index, rideNumber, rideCost, tripDuration;
    HeapNode() {
        index = -1;
        rideNumber = 0;
        rideCost = 0;
        tripDuration = 0;
        rbtNode = nullptr;
    }

    HeapNode(RBTNode *rbtNode, int rideNumber, int rideCost, int tripDuration) {             //assigning values to the variables using keyword  this
        this -> index = -1;
        this -> rbtNode = rbtNode;
        this -> rideNumber = rideNumber;
        this -> rideCost = rideCost;
        this -> tripDuration = tripDuration;
    }

    void printHeapNode() {                            // printing output of index , rideNumber
        cout << "(" << this -> index << ", " << this -> rideNumber << ", " << this -> rideCost << ", " << this -> tripDuration << ")";
    }

    void printHeapNode(string &output) {                           // for printing output in of rideNumber , rideCost , tripDuration           
       output += "(" + to_string(this -> rideNumber) + "," + to_string(this -> rideCost) + "," +  to_string(this -> tripDuration) + ")\n";
    }
};

class Heap {                 // defining heap class
int back;
HeapNode* heap[2000];    // defining array of fixed size 2000 as constraint mentioned in project
public:
    Heap() {          // it has a default constructor that initializes the "back" data member to 0
    back = 0;
    }
    
int getSize() {          //back returns the size
return back;
    }

    void push(HeapNode *heapNode) {        // for operation push
        heap[back] = heapNode;
        heap[back] -> index = back;
        heapifyUp(back);
        back++;
    }

    void getTopNode () {                  // to the top most element in node
        heap[0] -> printHeapNode();
    }
    
    HeapNode* top () {              // this function returns top
        return heap[0];
    }
 
    HeapNode* pop() {             // to delete an element in headnode
        back--;
        HeapNode *deletedNode = heap[0];
        heap[0] = heap[back];
        heap[0] -> index = 0;
        heapifyDown(0);
        return deletedNode;
    }

    void heapifyUp(int childIndex) {               //function is used to maintain the heap property of a binary heap data structure and uses childIndex
        if(childIndex == 0) return ;
        int parent = childIndex % 2 ? (childIndex - 1)/2 : (childIndex - 1)/2;    //this is done to calculate the parent node in heap
        int prc = heap[parent] -> rideCost, crc = heap[childIndex] -> rideCost;
        int ptd = heap[parent] -> tripDuration, ctd = heap[childIndex] -> tripDuration;
        
        if(prc < crc) return;
        
        else if(prc > crc) {
         swap(heap[parent] -> index, heap[childIndex] -> index);
         swap(heap[parent], heap[childIndex]);
        }
        else if(ptd > ctd) {
            swap(heap[parent] -> index, heap[childIndex] -> index);
            swap(heap[parent], heap[childIndex]);
        } 
        else return ;
        heapifyUp(parent);
    }

    void heapifyDown(int parent) {
        int leftChild = parent * 2 + 1, rightChild = parent * 2 + 2;
        if(leftChild >= back && rightChild >= back) return;

        int prc = heap[parent] -> rideCost, 
            lcrc = heap[leftChild] -> rideCost;
        int ptd = heap[parent] -> tripDuration, 
            lctd = heap[leftChild] -> tripDuration;
        int childToSwap = rightChild;

        // If only leftchild exists
        if(rightChild == back) {
            if(prc > lcrc || ptd > lctd) childToSwap = leftChild;
        } 
        else {
            int rcrc = heap[rightChild] -> rideCost, 
                rctd = heap[rightChild] -> tripDuration;

            if(prc < lcrc && prc < rcrc) return;

            if(prc > lcrc || ptd > lctd) childToSwap = leftChild;
            else if(prc > rcrc || ptd > rctd) childToSwap = rightChild;
        }
        
        swap(heap[parent] -> index, heap[childToSwap] -> index);
        swap(heap[parent], heap[childToSwap]);
        heapifyDown(childToSwap);
    }

    void update(HeapNode* heapNode, int newRideCost, int newTripDuration) {
        if(newRideCost > heapNode -> rideCost) {
            heapNode -> rideCost = newRideCost;
            heapifyDown(heapNode -> index);
        } else if(newTripDuration <= heapNode -> tripDuration) {
            heapNode -> tripDuration = newTripDuration;
            heapifyUp(heapNode -> index);
        } else if(newTripDuration > heapNode -> tripDuration) {
            heapNode -> tripDuration = newTripDuration;
            heapifyDown(heapNode -> index);
        }
    }
     void remove(HeapNode* heapNode) {
        int index = heapNode -> index;
        back--;
        heap[index] = heap[back];
        heap[index] -> index = index;
        heapifyDown(index);
    }
       void printHeap() {
        int level = 0, limit = 0;
        for(int i = 0; i < back; i++) {
            heap[i] -> printHeapNode();
            cout << ", ";
            if(i == limit) {
                limit += pow(2, ++level);
                cout << endl;
            }
        }
        cout << endl;
    }
};
