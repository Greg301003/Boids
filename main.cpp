#include "boids.hpp"

int main() {
  // create window

  sf::RenderWindow window(sf::VideoMode(1200, 1000), "Boids Simulation");

  // create a vector of boids
  std::vector<bd::Boid> boids;

  // generate boids
  for (int i = 0; i < 30; ++i) {
    // added static cast

    sf::Vector2<float> pos = {static_cast<float>(rand() % 1200),
                              static_cast<float>(rand() % 1000)};
    sf::Vector2<float> vel = {static_cast<float>( ((rand() % 5)-2.5)/100 ),
                              static_cast<float>(((rand() % 5)-2.5)/100)};

    //adding rotation speed
    double rotation_speed = static_cast<double>(1.0); 
    bd::Boid boid(pos, vel, rotation_speed);
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
    boid.UpdateRotation();
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