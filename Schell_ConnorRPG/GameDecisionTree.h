#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;
    std::unordered_map<int, Node<T>*> nodeMap;


public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}


    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Could not open file" <<filename << std::endl;
            return;
        }

        std::string line;
        while (std:: getline (file, line)) {
            std::stringstream ss(line);
            std:: string desc;
            int eventNum, leftNum, rightNum;

            std:: getline(ss, desc, delimiter);
            ss >> eventNum >> leftNum >> rightNum;

            if (nodeMap.find(eventNum) == nodeMap.end()) {
                nodeMap[eventNum] = new Node<T>(T(desc, eventNum, leftNum, rightNum));
            } else {
                nodeMap[eventNum]->data = T(desc, eventNum, leftNum, rightNum);
            }

            if (!root) {
                root = nodeMap[eventNum];
            }
        }

        for (auto& pair : nodeMap) {
            T& story = pair.second->data;

            if (story.getLeftEventNumber() != -1) {
                if (nodeMap.find(story.getLeftEventNumber()) == nodeMap.end()) {
                    nodeMap[story.getLeftEventNumber()] = new Node<T>(T("Placeholder", story.getLeftEventNumber(), -1, -1));
                }
                pair.second->left = nodeMap[story.getLeftEventNumber()];
            }

            if (story.getRightEventNumber() != -1) {
                if (nodeMap.find(story.getRightEventNumber()) == nodeMap.end()) {
                    nodeMap[story.getRightEventNumber()] = new Node<T>(T("Placeholder", story.getRightEventNumber(), -1, -1));
                }
                pair.second->right = nodeMap[story.getRightEventNumber()];
            }
        }

        file.close();
    }




    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        Node<T>* currentNode = root;
        if (!currentNode) {
            std::cerr << "No story loaded" << std::endl;
            return;
        }

        while (currentNode) {
            std:: cout << currentNode->data.getDescription() << "\n";

            if (!currentNode->left && !currentNode->right) {
                std:: cout << "GAME OVER!";
                break;
            }

            std:: cout<< "Choose path 1 or path 2:";
            int choice;
            std::cin >> choice;

            if (choice == 1) {
                if (currentNode->left) {
                    currentNode = currentNode->left;
                } else{
                    std::cout<<"No path exists. GAME OVER!"<< std:: endl;
                    break;
                }
            } else if (choice == 2) {
                if (currentNode->right) {
                    currentNode = currentNode->right;
                } else {
                    std:: cout<< "No path exists. GAME OVER!" << std::endl;
                    break;
                }
            }else {
                std:: cout<< "Invalid choice, please enter 1 or 2" <<std:: endl;
            }
        }
    }
};




#endif // GAMEDECISIONTREE_H