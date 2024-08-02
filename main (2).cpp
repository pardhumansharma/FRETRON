//first solution : No accident please
#include<bits/stdc++.h>
#include <SFML/Graphics.hpp>//simple and fast multimedia library used to print Graphics or Visualizations to print the desired output   
#include <vector>
#include <iostream>

using namespace std;
using namespace sf;

struct Flight {
    vector<Vector2f> points; // vectors for two dimensional floating precision 
    Color color;
};

void drawFlightPath(RenderWindow& window, const Flight& flight) {
    for (size_t i = 0; i < flight.points.size() - 1; ++i) {
        Vertex line[] = {
            Vertex(flight.points[i], flight.color),
            Vertex(flight.points[i + 1], flight.color)
        };
        window.draw(line, 2, Lines);
    }
}

int main() {
    // Creating a window
    RenderWindow window(VideoMode(8, 8), "Flight Paths");
    Flight flight1 = {{{1, 1}, {2, 2}, {3, 3}}, Color::Red};
    Flight flight2 = {{{1, 1}, {2, 4}, {3, 2}}, Color::Green};
    Flight flight3 = {{{1, 1}, {4, 2}, {3, 4}}, Color::Blue};

    // Main loop
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White);

        // Draw the flight paths
        drawFlightPath(window, flight1);
        drawFlightPath(window, flight2);
        drawFlightPath(window, flight3);

        window.display();
    }

    return 0;
}

/*Learnings and some important things from this question 
1.Here in this question i got an opportunity to work with the some extended stl libraries like sfml/graphics which is most probably used in games and game engines as well as for graphics and Visualizations part.
2.using namespace std; and using namespace sf;: These lines allow you to use the standard library and SFML without prefixing their components with std:: and sf::, making the code cleaner.
Struct Definition:
struct Flight: This defines a structure named Flight, which will hold the data for each flight path.
Inside Flight:
vector<Vector2f> points: This is a dynamic array that stores points in 2D space (each point has x and y coordinates).
Color color: This represents the color of the flight path when drawn.
In summary, this code creates a graphical window and visualizes three different flight paths using lines in various colors. It utilizes the SFML library to handle graphics rendering and simplifies handling dynamic arrays with vector. The program runs in a loop until the user closes the window.
References :https://www.geeksforgeeks.org/sfml-graphics-library-quick-tutorial
