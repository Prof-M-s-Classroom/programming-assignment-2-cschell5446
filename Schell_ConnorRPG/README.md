[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `[Connor Schell]`  
### **Student ID:** `[827745107]`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)
For my RPG game, a player with continue to make choices that will navigate them through an ancient jungle temple. This is done using a binary search tree and 
each decision made by the player being marked by a node. The different paths the player takes is determined by their choice of either path 1 or path 2 with 
many different combinations and end results.
 

Example:
> This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The storyline is loaded from an external text file (`story.txt`), which is parsed to construct the decision tree. The game ends when a leaf node (with `-1` as left and right children) is reached.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `[Describe its function]`- The purpose of the main.cpp is to load the specific story into the code and allow the player to begin playing the game.  
- **`GameDecisionTree.h`** → `[Explain what this file contains]` - The GameDecisionTree.h is responsible for loading, building and running the story using a binary tree. It contains the loadStoryFromFile() function with reads events from the story.txt file, creates story objects and builds a binary tree. It also includes the playGame() function which starts the game for the player and displays the different paths they can take. 
- **`Node.h`** → `[Explain what this file contains]`  - Node.h is simply the structure of the decision tree. It links choices together and traverses the story.
- **`Story.h`** → `[Explain what this file contains] - Story.h stores the data for each decision available in the story
- **`story.txt`** → `[Explain how the game loads story events from this file]` - The story.txt is the file where the individual situations and paths are written. The loadStoryFromFile() function takes these situation or nodes and creates story objects. It then builds a binary tree by linking each node based on the decisions made. 

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file? - Each line of story.txt is creates a story object. The the story is wrapped into a node. The nodes are then stored into nodeMap and after all are stored, the tree in lined based on the left and right event numbers.
- How are nodes linked based on left and right event numbers?  Each part of the story contains a description, event number and left/right event number or choices. Once each node is stored in a map, the game commences and uses the left/right numbers to match child nodes.
- What happens if an event has `-1` as left or right children?  If an event has -1 as a left or right child, this means that there is no further path to take and the game will end.

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken? The user can either input a 1 or a 2. This represents with child node the game will move to with each child node having two choices as well until a leaf node is reached and the game ends. 
- What happens when the player reaches a leaf node?  When a player reaches a leaf node, -1 event number, that represents no more choices or events after and symbolizes reaching the end of the game.
- Explain the special case where multiple events lead to the same outcome. If multiple events lead to the same outcome, they lead to the same noad allows paths to merge. This is done through shared pointers within nodeMap  

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?  The story.txt file is read line by line. The delimiter " | " splits the description from the event numbers, which helps organize the data into nodes.
- How do you ensure nodes are properly linked?  Nodes are properly linked by creating each node and storing it in a map using eventNum. Then, linking each nodes left and right pointer based on child event numbers within the map.
- Any challenges faced while handling file input?  My biggest challenged faced with file input was having the incorrect format which caused my game to be stuck in an endless loop and not moving through the story.

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)
One problem i faced, which was my biggest and most frustrating problem was when i ran the code, it would get stuck in an endless loop of "Choose path 1 or 2" and would not continue with the story. After looking through the code line by line, i finally found the issue being that my story.txt format didnt match the one created in the code. Just by simply rearraging the description and the event numbers the code final ran through and the story was created.
Another problem i had was with my code reading the story.txt. This one was annoying because i tried changing a bunch of things to make it work just to realize the file wasn't even in the right spot.

Example:
> Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)
You wake up at the entrance of an ancient jungle temple. Two tunnels lie ahead. | 1 2 3 (Player chooses 1)
You take the left tunnel, dimly lit by glowing moss. | 2 4 5 (Player chooses 1)
You stumble upon a wall puzzle containing ancient symbols. | 4 8 9 (Player chooses 1)
You solve the puzzle and a hidden door opens. | 8 16 -1 (Player chooses 1)
You find the hidden treasure. | 16 -1 -1
Game ends
---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(?)`  O(n)
- **Searching for an event in the tree** → `O(?)`  O(1)
- **Game traversal efficiency** → `O(?)`  The time complexity of game traversal is dependent on the path the player takes

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)
In one of the paths of my game, the player can potentially fall into a pit. I tried out this scenario to make sure that if this happens, the game ends and no further decisions can be made.

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
