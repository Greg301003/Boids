#include "boids.hpp"
int main() {
  // create window

  sf::RenderWindow window(sf::VideoMode(1200, 1000), "Boids Simulation");

  // create a vector of boids
  std::vector<Boid::Boid> boids;

  // generate boids
  for (int i = 0; i < 30; ++i) {
    // added static cast

    Vector2d::Vector2d pos = {static_cast<double>(rand() % 1200),
                              static_cast<double>(rand() % 1000)};
    Vector2d::Vector2d vel = {static_cast<double>( ((rand() % 5)-2.5)/100 ),
                              static_cast<double>(((rand() % 5)-2.5)/100)};
    Vector2d::Vector2d acc = {0, 0};
    Boid::Boid boid(pos, vel, acc);
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
      for (auto& boid : boids) {
    boid.UpdatePosition();
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