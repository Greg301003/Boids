#ifndef BOIDS_HPP
#define BOIDS_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

namespace Vector2d {
class Vector2d {
 public:
  double x{};
  double y{};

  Vector2d operator+=(Vector2d const&);  // somma tra vettori
  Vector2d operator*(double const&);     // prodotto per scalare
  double length(Vector2d const&);        // ritorna la lunghezza del vettore
};
double length(Vector2d const&);
}  // namespace Vector2d
namespace Boid {
class Boid {
  Vector2d::Vector2d position_{};
  Vector2d::Vector2d velocity_{};
  sf::ConvexShape shape_;

 public:
  Boid(Vector2d::Vector2d const& pos, Vector2d::Vector2d const& vel,
       Vector2d::Vector2d const& acc)  // constructor
      : position_{pos}, velocity_{vel} {
     // create boid triangle shape so that we know where they're pointing
    shape_.setPointCount(3);
    shape_.setPoint(0, sf::Vector2f(0, -10));
    shape_.setPoint(1, sf::Vector2f(-5, 5));
    shape_.setPoint(2, sf::Vector2f(5, 5));
    shape_.setPosition(position_.x, position_.y);
    shape_.setFillColor(sf::Color::White); // White color
  }

  Vector2d::Vector2d GetPosition(Boid const&);  // ritorna la posizione del boid
  Vector2d::Vector2d GetVelocity(Boid const&);  // ritorna la velocità del boid

  double Distance(Boid const& b1,
                  Boid const& b2);  // ritorna la distanza tra due boid

  void Draw(sf::RenderWindow& window) const;  // draw boid
};
}  // namespace Boid
#endif
