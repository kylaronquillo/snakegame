#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

bool gameOver = false; //  to know if game is done or not
const int width = 35; // for the square
const int height = 15; // for the square
int score = 0; // score tally
int level;

//create a structure to store the (int) coordinates of where the snake is
struct Snake {
    int x, y;

    Snake(int x, int y) {
        this->x = x;
        this->y = y;
    }
};


class SnakeGame{
private:
    char direction;
    char border[height][width];
    list<Snake> body;
    queue<Snake> food;
    stack<Snake> move;
public:
    SnakeGame(){
        srand(0);

        // spawn head of snake
        int startX = rand() % (width -2);
        int startY = rand() % (height -2);
        body.push_front(Snake(startX, startY));

        // spawn a snack
        spawnSnack();
    }

    // assign characters to the game box
    void createGameBox(){
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                    border[i][j] = '#';
                } else {
                    border[i][j] = ' ';
                }
            }
        }
    }

    // display the characters in the game box + score + level
    void dispGameBox(){
        system("cls");
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << border[i][j];
            }
            cout << endl;
        }
        cout << "SCORE: " << score << endl;
        cout << "LEVEL: " << level << endl;
    }

    // push snack random coordinates to the queue
    void spawnSnack(){
        int x, y;
        srand(0);
        do {
            x = 1 + rand() % (width - 2); y = 1 + rand() % (height - 2);
        }while(border[y][x] != ' ');
        food.push(Snake(x, y)); 
    }

    // get input from user for direction
    void getDirection(){
        if (_kbhit()){
            switch(_getch()){
                case 72: direction = 'u'; break;
                case 75: direction = 'l'; break;
                case 80: direction = 'd'; break;
                case 77: direction = 'r'; break;
            }
        }
    }
    
    // moves snake based on input
    void moveSnake(){
        Snake head = body.front();
        int frontX = head.x;
        int frontY = head.y;

        switch (direction) {
            case 'u': 
                frontY = head.y - 1; break;
            case 'd': 
                frontY = head.y + 1; break;
            case 'l': 
                frontX = head.x - 1; break;
            case 'r':  
                frontX = head.x + 1; break;
        }

        move.push({frontX, frontY});

        /*if (border[frontY][frontX] == '*') { // if it encounters a snack, add a body part and spawn a new snack
            body.push_front({frontX, frontY});
            food.pop();
            spawnSnack();
            score++;
        } else { // if no snack encountered, move the snake by updating the head coordinates
            body.pop_back();
            body.push_front({frontX, frontY});
        }*/
    }

    void processMovements() {
        if (!move.empty()) {
            Snake newHead = move.top();
            move.pop();

            if (border[newHead.y][newHead.x] == '*') {
                body.push_front(newHead);
                food.pop();
                spawnSnack();
                score++;
            } 
            else {
                body.pop_back();
                body.push_front(newHead);
            }
        }
    }
    void updateBorder() {
        createGameBox();

        for (const auto &part : body) {
            border[part.y][part.x] = 'O';
        }
        if (!food.empty()) {
            Snake foodPos = food.front();
            border[foodPos.y][foodPos.x] = '*';
        }
    }

};

int main(){
    SnakeGame s;
    s.createGameBox();
    while(!gameOver){
        s.dispGameBox();
        s.getDirection();
        s.moveSnake();
        s.processMovements();
        s.updateBorder();
        Sleep(300);
    }
    return 0;
}