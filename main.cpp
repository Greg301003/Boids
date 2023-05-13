#include "boids.hpp"
int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Boids Simulation");

  while (window.isOpen())  // loop
  {
    sf::Event event;
    while (window.pollEvent(event))        
    {
      if (event.type == sf::Event::Closed) // close clicking 
      {
        window.close();
      }
    }
    window.clear();
    window.display();
  }

  return 0;
}