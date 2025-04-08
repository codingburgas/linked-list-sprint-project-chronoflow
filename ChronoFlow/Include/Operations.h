#pragma once

#include "../Include/Event.h" 
#include "../Include/Node.h" 

void addEvent(Node*& head);
void displayAllEvents(Node* head);
void searchEvents(Node* head);
void deleteEvent(Node*& head);
void swapEvents(Event& a, Event& b);
void sortEvents(Node* head, bool ascending);