
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cmath>
#include <math.h>


//scale value
const float decreaseFactor = 2.0/3;

//sum of the rest of the angles of a triangle without the right angle
const float degree = 90;

//angle measure you want
const float angle = 50;

//window x and y size
const float winX = 1000;
const float winY = 1000;

//initial x and y values
const float initX = 500;
const float initY = 0;

//length of branch
const float length = 400;

//smallest possible branch length
const float minLength = 1;

//divide by convertToRadian after multiplying degree by pi
const float convertToRadian = 180.0;

sf::RenderWindow window(sf::VideoMode(winX, winY), "Cindy's Fractal Tree");


void drawTree(float initX, float initY, float degree, int length);

int main(int argc, char ** argv)

{
    //while the window is open
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        
        window.clear();
        drawTree(initX, initY, degree, length);
        window.display();
        
    }

    return 0;
 
}


void drawTree(float initX, float initY, float degree, int length)
{
    //base case
    if(length < minLength)
    {
        return;
    }
    else
    {
        //decrease the length of the segment to be 2.0/3 that of the previous segment
        float newLength = decreaseFactor * length;
        
        //calculates new final x and y values
        float finalX = initX + newLength * cos(degree * M_PI / convertToRadian);
        float finalY = initY + newLength * sin(degree * M_PI / convertToRadian);
        
        //creates a line from initial point to final point
        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(initX, initY)),
            sf::Vertex(sf::Vector2f(finalX, finalY))
        };
        
        window.draw(line, 2, sf::Lines);
        
        //double tail recursion to draw both sides of the branches of the tree
        drawTree(finalX, finalY, degree - angle, newLength);
        
        drawTree(finalX, finalY, degree + angle, newLength);
        

    }
    
}
