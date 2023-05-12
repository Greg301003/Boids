#ifndef BOIDS_HPP
#define BOIDS_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Vector2d {
 public:
  double x{};
  double y{};

  Vector2d operator+=(Vector2d const&);
  Vector2d operator*(double const&);
  double length(Vector2d const&);
};

class Boid {
  Vector2d position_{};
  Vector2d velocity_{};
  sf::ConvexShape shape_;

  // modifico i nomi
 public:
// constructor
  Boid(Vector2d const& pos, Vector2d const& vel, Vector2d const& acc);

  // per accedere a posizione e velocità dall'esterno
  Vector2d GetPosition(Boid const&);
  Vector2d GetVelocity(Boid const&);
  // dichiaro la distanza tra due boids

  double Distance(Boid const& b1, Boid const& b2);

    // draw boid
  void Draw(sf::RenderWindow& window) const;
};
#endif