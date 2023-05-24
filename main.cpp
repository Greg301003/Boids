#include "boids.hpp"

int main() {
  // create window

  sf::RenderWindow window(sf::VideoMode(1600, 1400), "Boids Simulation");

  // create a vector of boids
  std::vector<bd::Boid> boids;

  // separation parameters
  float separation_radius = 20.0f;  // Adjust the value as per your requirement

  // generate boids
  for (int i = 0; i < 150; ++i) {
    // added static cast

    sf::Vector2<float> pos = {static_cast<float>(rand() % 1600),
                              static_cast<float>(rand() % 1400)};
    sf::Vector2<float> vel = {static_cast<float>(((rand() % 5) - 2.5) / 100),
                              static_cast<float>(((rand() % 5) - 2.5) / 100)};

    // adding rotation speed
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

    sf::Color color(240, 240, 240);
    window.clear(color);  // to set background color

    sf::Vector2f windowSize(static_cast<float>(window.getSize().x),
                            static_cast<float>(window.getSize().y));

    for (auto& boid : boids) {
      boid.UpdatePosition(windowSize, boids, separation_radius);
      boid.UpdateRotation();
    }

    // draw boids
    for (auto const& boid : boids) {
      boid.Draw(window);
    }

    window.display();
  }

  return 0;
}