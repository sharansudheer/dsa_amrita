#include <bits/stdc++.h>
using namespace std;

struct Node {

    int data;
    Node* next;

    Node(int new_data)
    {
        data = new_data;
        next = nullptr; 
    }
};