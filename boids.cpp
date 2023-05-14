#include "boids.hpp"

#include <cmath>


  //missing & in vector2d 
Vector2d operator+=(Vector2d& const& v) {
  return {this->x + v.x, this->y + v.y};



Vector2d operator*(double const& scalar) { 
  // missing this->
  return
  {this->x * scalar, this->y * scalar};}

double length(Vector2d const& v) { return {std::sqrt(v.x * v.x + v.y * v.y)}; }
}  // namespace Vector2d

namespace Boid_NS {
double Distance(Boid const& b1, Boid const& b2) {
  double dx = b1.position_.x - b2.position_.x;
  double dy = b1.position_.y - b2.position_.y;
  return std::sqrt(dx * dx + dy * dy);
}

// giving an alternative definition of Boid::Distance by using Vector2d methods
double Boid::Distance(Boid const& i, Boid const& j) {
  auto distance = i.position_ - j.position_;
  //misspel lenght
  return distance.length();
}

Vector2d GetPosition(Boid const& b) { return b.position_; }
Vector2d GetVelocity(Boid const& b) { return b.velocity_; }

void Draw(sf::RenderWindow& window) const { window.draw(shape_); }
}  // namespace Boid
