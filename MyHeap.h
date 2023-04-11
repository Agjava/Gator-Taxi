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
    
void HeapNodeprint() {                            // printing output of index , rideNumber
cout << "(" << this -> index << ", " << this -> rideNumber << ", " << this -> rideCost << ", " << this -> tripDuration << ")";
}
void HeapNodeprint(string &output) {                           // for printing output in of rideNumber , rideCost , tripDuration           
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
    
int size() {              //back returns the size
return back;
}
    
void push(HeapNode *heapNode) {        // for operation push
heap[back] = heapNode;
heap[back] -> index = back;
heapifyUp(back);
back = back + 1;
}

void TopNodeget () {                  // to the top most element in node
heap[0] -> HeapNodeprint();
}
    
HeapNode* top () {              // this function returns top value in node
return heap[0];
}
 
HeapNode* pop() {             // to delete an element in headnode
back = back - 1;
HeapNode *deletedNode = heap[0];
heap[0] = heap[back];
heap[0] -> index = 0;
heapifyDown(0);
return deletedNode;
}

void heapifyUp(int childIndex) {               //function is used to maintain the heap property of a binary heap data structure and uses childIndex
if(childIndex == 0) return ;
int parent = childIndex % 2 ? (childIndex - 1)/2 : (childIndex - 1)/2;    //this is done to calculate the index of parent node in heap
int rcp = heap[parent] -> rideCost, rcc = heap[childIndex] -> rideCost;   //we initalize ridecost of parent and ridecost of children
int tdp = heap[parent] -> tripDuration, tdc = heap[childIndex] -> tripDuration; // we then intialize the trip duration of parent and trip duration of child
        
if( rcp < rcc) return;       //checks if the rideCost of the parent node is less than that of the child node. If it is, the function returns immediately.
else if(rcp > rcc) {           // checks if the rideCost of the parent node is greater than that of the child node. If it is,  swap the values of the index and heap members for the parent and child nodes.
swap(heap[parent] -> index, heap[childIndex] -> index);
swap(heap[parent], heap[childIndex]);
 }
else if(ptd > ctd) {          //checks if the tripDuration of the parent node is greater than that of the child node. If it is, swap the values of the index and heap members for the parent and child nodes.
swap(heap[parent] -> index, heap[childIndex] -> index);
swap(heap[parent], heap[childIndex]);
} 
else return ;         //return if none of the above is true
heapifyUp(parent);
}

void heapifyDown(int parent) {                                   //defines the function heapifyDown that takes an integer argument parent and returns nothing (void).
int leftChild =  (parent * 2) + 1, rightChild = (parent * 2) + 2;  //calculates the indices of the left and right children of the parent node in the heap.    
if(leftChild >= back && rightChild >= back) return;   //checks if both children are beyond the last element in the heap (back). If so, the function returns immediately
int rcp = heap[parent] -> rideCost,               //retrieves the rideCost values of the parent and leftChild nodes from the heap.
rclc = heap[leftChild] -> rideCost;
int tdp = heap[parent] -> tripDuration,       //retrieves the tripDuration values of the parent and leftChild nodes from the heap
tdlc = heap[leftChild] -> tripDuration;
int swapchild = rightChild;

if(rightChild == back) {            // If only leftchild exists
if(rcp > rclc || tdp > tdlc )    //checks if either the rideCost or tripDuration of the parent is greater than that of the left child. If so, it sets swapchild to be the left child.
swapchild = leftChild;
 } 
 else {
int rcrc = heap[rightChild] -> rideCost, 
int tdrc = heap[rightChild] -> tripDuration;       //initalizing variables
if(prc < lcrc && prc < rcrc) return;          // checks if both children have a smaller ride cost and trip duration than their parent. If so, it means that no swap is needed and returns immediately.
if(prc > lcrc || ptd > lctd) swapchild = leftChild;    //checks if either ride cost or trip duration of parent is greater than that of left child. If so, it sets childToSwap to be left child.
else if(prc > rcrc || ptd > rctd) swapchild = rightChild;    //checks if either ride cost or trip duration of parent is greater than that of right child. If so, it sets childToSwap to be right child.
 }
swap(heap[parent] -> index, heap[swapchild] -> index);     //swapping
swap(heap[parent], heap[swapchild]);
heapifyDown(swapchild);
}

void update(HeapNode* heapNode, int newRideCost, int newTripDuration) {
if(newRideCost > heapNode -> rideCost) {
heapNode -> rideCost = newRideCost;
heapifyDown(heapNode -> index);
} 
else if(newTripDuration <= heapNode -> tripDuration) {
heapNode -> tripDuration = newTripDuration;
heapifyUp(heapNode -> index);
} 
else if(newTripDuration > heapNode -> tripDuration) {
heapNode -> tripDuration = newTripDuration;
heapifyDown(heapNode -> index);
}
}
void remove(HeapNode* heapNode) {
int index = heapNode -> index;
back = back -1;
heap[index] = heap[back];
heap[index] -> index = index;
heapifyDown(index);
}
void print() {
int level = 0, limit = 0;
for(int i = 0; i < back; i++) {
heap[i] -> HeapNodeprint();
cout << ", ";
if(i == limit) {
limit = limit + pow(2, ++level);
cout << endl;
}
}
cout << endl;
}
};
