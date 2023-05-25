#include "boids.hpp"

int main() {
  // create window

  sf::RenderWindow window(sf::VideoMode(1600, 1400), "Boids Simulation");

  // create a vector of boids
  //std::vector<bd::Boid> boids;

//create two types of boids
  std::vector<bd::Boid> bird1Boids;
std::vector<bd::Boid> bird2Boids;

  // separation parameters
  float separation_radius = 25.0f;  // Adjust the value as per your requirement



  // generate boids
  /*for (int i = 0; i < 50; ++i) {
    // added static cast

    sf::Vector2<float> pos = {static_cast<float>(rand() % 1600),
                              static_cast<float>(rand() % 1400)};
    sf::Vector2<float> vel = {static_cast<float>(((rand() % 5) - 2.5) / 100),
                              static_cast<float>(((rand() % 5) - 2.5) / 100)};

    // adding rotation speed
    double rotation_speed = static_cast<double>(1.0);

    // create bird1 type boids
    bd::Boid boid(pos, vel, rotation_speed, bd::Boid::BoidBehavior::Bird1);
    boids.push_back(boid);
  }*/

for (int i = 0; i < 50; ++i) {
  // Genera i boid di tipo "bird1"
  sf::Vector2<float> pos = {static_cast<float>(rand() % 1600),
                            static_cast<float>(rand() % 1400)};
  sf::Vector2<float> vel = {static_cast<float>(((rand() % 5) - 2.5) / 100),
                            static_cast<float>(((rand() % 5) - 2.5) / 100)};
  bd::Boid bird1(pos, vel, 1.0, bd::Boid::BoidBehavior::Bird1);
  bird1Boids.push_back(bird1);

  // Genera i boid di tipo "bird2"
  pos = {static_cast<float>(rand() % 1600), static_cast<float>(rand() % 1400)};
  vel = {static_cast<float>(((rand() % 5) - 2.5) / 100),
         static_cast<float>(((rand() % 5) - 2.5) / 100)};
  bd::Boid bird2(pos, vel, 1.0, bd::Boid::BoidBehavior::Bird2);
  bird2Boids.push_back(bird2);
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

    /*for (auto& boid : boids) {
      boid.UpdatePosition(windowSize, boids, separation_radius);
      boid.UpdateRotation();
    }
*/


for (auto& bird1 : bird1Boids) {
  bird1.UpdatePosition(windowSize, bird1Boids, separation_radius);
  bird1.UpdateRotation();
}

for (auto& bird2 : bird2Boids) {
  bird2.UpdatePosition(windowSize, bird2Boids, separation_radius);
  bird2.UpdateRotation();
}



// Disegna i boid di tipo "bird1"
for (auto const& boid : bird1Boids) {
  boid.Draw(window);
}

// Disegna i boid di tipo "bird2"
for (auto const& boid : bird2Boids) {
  boid.Draw(window);
}



  /* // draw boids
    for (auto const& boid : boids) {
      boid.Draw(window);
    }
*/
    window.display();
  }

  return 0;
}