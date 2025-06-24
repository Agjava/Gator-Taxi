# GatorTaxi

The Gator-Taxi project is a ride sharing management system implemented for my computer science project for the Advanced Data Structures course at the University of Florida. This system is designed to efficiently handle multiple ride requests using System Architecture as mentioned below :- 

The GatorTaxi system utilizes a dual data structure approach to optimize different types of operations:

Red-Black Tree (RBT): Stores ride information ordered by ride number, enabling efficient searching and range queries

Min-Heap: Stores ride information ordered by estimated cost and trip duration, with the lowest cost rides prioritized at the root

The system maintains synchronized pointers between corresponding nodes in both data structures to ensure consistency across operations.

