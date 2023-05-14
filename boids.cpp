#include "boids.hpp"

#include <cmath>

namespace Vector2d {
  Vector2d Vector2d::operator+=(Vector2d const& v) {
    x += v.x;
    y += v.y;
    return *this;
  }

  Vector2d Vector2d::operator*(double const& scalar) {
    return {this->x * scalar, this->y * scalar};
  }

  double Vector2d::length(Vector2d const& v) {
    return {std::sqrt(v.x * v.x + v.y * v.y)};
  }
}

namespace Boid {
  double Boid::Distance(Boid const& b1, Boid const& b2) {
    double dx = b1.position_.x - b2.position_.x;
    double dy = b1.position_.y - b2.position_.y;
    return std::sqrt(dx * dx + dy * dy);
  }

 /* double Boid::Distance(Boid const& i, Boid const& j) {
    auto distance = i.position_ - j.position_;
    return distance.length();
  }*/

  Vector2d::Vector2d Boid::GetPosition(Boid const& b) {
    return b.position_;
  }

  Vector2d::Vector2d Boid::GetVelocity(Boid const& b) {
    return b.velocity_;
  }

  void Boid::Draw(sf::RenderWindow& window) const {
    window.draw(shape_);
  }
} 