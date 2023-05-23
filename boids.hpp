#ifndef BOIDS_HPP
#define BOIDS_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

namespace bd {
class Boid {
  sf::Vector2<float> position_{};
  sf::Vector2f velocity_{};
  sf::ConvexShape shape_;
  double rotation_speed_;

 public:
  Boid(sf::Vector2f const& pos, sf::Vector2f const& vel,
       sf::Vector2d const& acc, double rotation_speed);          // constructor

  sf::Vector2d GetPosition(Boid const&);  // ritorna la posizione del boid
  sf::Vector2d GetVelocity(Boid const&);  // ritorna la velocità del boid

  double Distance(Boid const& b1,
                  Boid const& b2);  // ritorna la distanza tra due boid

  void Draw(sf::RenderWindow& window) const;  // draw boid

  void UpdatePosition(); //update boids

  void UpdateRotation(); //trying rotation
};
}  // namespace Boid

#endif
