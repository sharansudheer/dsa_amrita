#include <iostream>
#include <stdbool.h>
#include <stdio.h>

using namespace std;

//Struct node is our data type, there are 3 parts
//data, left and right pointer
struct node{

    int data;
    struct node *left, *right;

};
/*
it is going to return the address to the node created
pointer to node
*/
struct node *create(){

    //create a new node
    struct node *new_node;

    //dynamically allocate the memory for node
    //mallaoc is going to return a void pointer, 
    //type cast the data type struct node
//size of the user defined data type node
    new_node = (struct node*) malloc(sizeof(struct node)); 

}


void main(){

    struct node *root;
    //after creating the tree, we need store the pointer of the node created
    //root is going to store the address of create
    root = create();

} 