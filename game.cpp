#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std; 
bool gameOver;
const int width = 20;
const int height = 20;
//introducing variables x and y for head positions and variables fruitX and fruitY for our fruit positions 
int x , y, fruitX, fruitY, score;
// to track the direction of the snake [eg. snake will go left constantly when we press the keys]
enum eDirection{ STOP =0,LEFT , RIGHT, UP , DOWN }; //initializing stop to 0
eDirection dir; // it holds the diection of snake
void SetUp(){
    gameOver= false ;
    dir = STOP; // this ensures snake will now move until we start moving it 
    x = width/ 2; //setting positions of the head, setting it to the middle 
    y = height/2; //setting the snakehead to center on the map
    fruitX = rand() % width; //setting fruitX to random position on the map from 0 to width-1
    fruitY = rand() % height;
    score = 0;
    //basic set up made
}
void Draw(){
    //first we need to clear the screen since we are making the game on the Console window so we use the system and callthe CLS command that will clear the screen
    system("cls") ; // for Linux users type system("clear")
    //displaying top border of our map
    for (int i = 0; i< width +2; i++ )
        cout<< "^^" ;//character for the top map wall
        
    cout<<endl;
    for(int i = 0; i < height; i++){ 
        for(int j = 0; j<width; j++){
            //this prints the map 
            if (j==0) //checking if its the first field
                cout<<"^^";
            if (i == y && j == x )
                cout<< "@ "; //printing head 
            else if (i == fruitY && j == fruitX)
                cout<< "$"; //printing fruit
            else 
                cout<< " ";
            
                cout<< " "; //when not 0 , printing blank space
            if (j== width -1 )
                cout<< "^^"; //printing wall on the next side
            }
            cout<< endl;
    }


    for (int i = 0; i< width + 2 ; i++ )
        cout<< "^^"; //character for the bottom map wall

    cout<< endl;
    cout<< "Score: "<<score << endl;
    
    
}

void Input(){
    // using 2 functions of header file conio.h that are asynchronous functions that dosen't block the program and helps getting a character  from a console window
    //checking if keyboard key is pressed
    if (_kbhit()) //returns in bool positive is a charcter on the keyboard is pressed and zero when noting is pressed
    {
        switch (_getch()) // gives ASCII code of key pressed 
        {
            //u is up , l is left , r is right , d is down and z is game over
            case 'l':
                dir = LEFT;
                break;
            case 'r':
                dir = RIGHT;
                break; 
            case 'u':
                dir = UP;
                break; 
            case 'd':
                dir = DOWN;
                break; 
            case 'z':
            gameOver= true;
            break;
            //it handels all the controls 
        }


    }
}

void Logic(){
    //switching directions 
    switch (dir)
    {
    case LEFT: 
        x--; //decreasing x coordinate of the snake 
        break;
    case RIGHT:
        x++;  
        break;
    case UP: 
        y--; 
        break;
     case DOWN:
        y++;  
        break;
    default:
        break;
    }
    if (x > width || x < 0 || y> height || y< 0 )
        gameOver = true; //game terminates when we try to go out of the boundaries 
    if (x== fruitX && y == fruitY ){
        score += 1; //incresing the score as we successfully eat the fruit
        fruitX = rand() % width; 
        fruitY = rand() % height; 
    }
}


int main()
{
    SetUp();
    while (!gameOver){
        Draw();
        Input();
        Logic();
        

    }
     return 0;
}