#include "boids.hpp"
int main() {
  // create window

  sf::RenderWindow window(sf::VideoMode(800, 600), "Boids Simulation");

  // create a vector of boids
  std::vector<Boid> boids;

    // generate boids
  for (int i = 0; i < 40; ++i) {
    Vector2d pos = {rand() % 800, rand() % 600};
    Vector2d vel = {rand() % 7, rand() % 7};
    Vector2d acc = {0, 0};
    Boid boid(pos, vel, acc);
    boids.push_back(boid);
  }


  while (window.isOpen())  // loop
  {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)  // close clicking
      {
        window.close();
      }
    }
    window.clear();
    // draw boids
    for (auto const& boid : boids) {
      boid.Draw(window);
    }

    window.display();
  }

  return 0;
}