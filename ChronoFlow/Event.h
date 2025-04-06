#pragma once


#include <string>

struct Event {
    std::string title;    
    std::string theme;    
    std::string location;
    int month;            
    int year;            

    Event(std::string t, std::string th, std::string loc, int m, int y)
        : title(t), theme(th), location(loc), month(m), year(y) {
    }
};