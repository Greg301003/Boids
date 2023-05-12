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

 public:
  Boid(Vector2d p, Vector2d v, Vector2d a) : position_{p}, velocity_{v} {}

  Vector2d GetPosition(Boid const&);
  Vector2d GetVelocity(Boid const&);
};

#endif