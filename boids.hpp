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
       Vector2d::Vector2d const& acc);          // constructor

  Vector2d::Vector2d GetPosition(Boid const&);  // ritorna la posizione del boid
  Vector2d::Vector2d GetVelocity(Boid const&);  // ritorna la velocità del boid

  double Distance(Boid const& b1,
                  Boid const& b2);  // ritorna la distanza tra due boid

  void Draw(sf::RenderWindow& window) const;  // draw boid

  void UpdatePosition(); //update boids

  void UpdateRotation(); //trying rotation
};
}  // namespace Boid
#endif
