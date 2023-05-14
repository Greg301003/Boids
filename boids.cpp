#include "boids.hpp"

#include <cmath>

// missing & in vector2d
Vector2d::Vector2d Vector2d::Vector2d::operator+=(Vector2d const& v) {
  x+=v.x;
  y+=v.y;

  return *this;}

  Vector2d::Vector2d Vector2d::Vector2d::operator*(double const& scalar) {
    // missing this->
    return {this->x * scalar, this->y * scalar};
  }

  double length(Vector2d const& v) {
    return {std::sqrt(v.x * v.x + v.y * v.y)};
  }


double Distance(Boid::Boid const& b1, Boid::Boid const& b2) {
  double dx = b1.position_.x - b2.position_.x;
  double dy = b1.position_.y - b2.position_.y;
  return std::sqrt(dx * dx + dy * dy);
}

// giving an alternative definition of Boid::Distance by using Vector2d methods
double Boid::Distance(Boid::Boid const& i, Boid::Boid const& j) {
  auto distance = i.position_ - j.position_;
  // misspel lenght
  return distance.length();
}

Vector2d::Vector2d GetPosition(Boid::Boid const& b) { return b.position_; }
Vector2d::Vector2d GetVelocity(Boid::Boid const& b) { return b.velocity_; }

void Draw(sf::RenderWindow& window) const { window.draw(shape_); }
