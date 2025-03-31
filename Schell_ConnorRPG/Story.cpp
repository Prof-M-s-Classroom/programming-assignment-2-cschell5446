#include "Story.h"

// TODO: Default constructor
Story::Story() : description(""), eventNumber(0), leftEventNumber(-1), rightEventNumber(-1) {}

// TODO: Parameterized constructor
Story::Story(std::string desc, int num, int leftNum, int rightNum)
        : description(desc), eventNumber(num), leftEventNumber(leftNum), rightEventNumber(rightNum) {}

string Story :: getDescription() const{
        return description;
}

int Story :: getEventNumber() const{
        return eventNumber;
}

int Story :: getLeftEventNumber() const{
        return leftEventNumber;
}

int Story :: getRightEventNumber() const{
        return rightEventNumber;
}

void Story :: setDescription(std :: string desc) {
        description = desc;
}

void Story :: setEventNumber(int num) {
        eventNumber = num;
}

void Story :: setLeftEventNumber(int leftNum) {
        leftEventNumber = leftNum;
}

void Story :: setRightEventNumber(int rightNum) {
        rightEventNumber = rightNum;
}