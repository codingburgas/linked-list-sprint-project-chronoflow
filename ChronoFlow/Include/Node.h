#pragma once
#include "event.h"  


struct Node {
    Event event;    
    Node* next;      

    Node(Event e) : event(e), next(nullptr) {}
};
