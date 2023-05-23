#ifndef BOIDS_HPP
#define BOIDS_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

/* 
namespace V2 {
class Vector {
 public:
  double x{};
  double y{};

  sf::Vector2d operator+=(Vector2d const&);  // somma tra vettori
  Vector2d operator*(double const&);     // prodotto per scalare
  double length(Vector2d const&);        // ritorna la lunghezza del vettore
};
double length(Vector2d const&);
}  // namespace Vector2d


*/


namespace bd {
class Boid {
  sf::Vector2d position_{};
  sf::Vector2d velocity_{};
  sf::ConvexShape shape_;
  double rotation_speed_;

 public:
  Boid(sf::Vector2d const& pos, sf::Vector2d const& vel,
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
