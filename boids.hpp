#ifndef BOIDS_HPP
#define BOIDS_HPP


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

  // modifico i nomi
 public:
  Boid(Vector2d pos, Vector2d vel, Vector2d acc)
      : position_{pos}, velocity_{vel} {}
  // per accedere a posizione e velocità dall'esterno
  Vector2d GetPosition(Boid const&);
  Vector2d GetVelocity(Boid const&);
  // dichiaro la distanza tra due boids

  double Distance(Boid const& b1, Boid const& b2);
};
#endif