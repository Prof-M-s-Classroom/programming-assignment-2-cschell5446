#ifndef STORY_H
#define STORY_H

#include <string>
using namespace std;
class Story {
public:
    string description;
    int eventNumber;
    int leftEventNumber;
    int rightEventNumber;

    // Default constructor
    Story();

    // Parameterized constructor
    Story(string desc, int num, int leftNum, int rightNum);

    string getDescription() const;
    int getEventNumber() const;
    int getLeftEventNumber() const;
    int getRightEventNumber() const;

    void setDescription(string desc);
    void setEventNumber(int num);
    void setLeftEventNumber(int leftNum);
    void setRightEventNumber(int rightNum);
};

#endif // STORY_H