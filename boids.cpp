#include "boids.hpp"

#include <cmath>

Vector2d::Vector2d Vector2d::Vector2d::operator+=(const Vector2d& v) {
  x += v.x;
  y += v.y;
  return *this;
}

Vector2d::Vector2d Vector2d::Vector2d::operator*(double const& scalar) {
  return {this->x * scalar, this->y * scalar};
}

double Vector2d::length(Vector2d const& v) {
  return {std::sqrt(v.x * v.x + v.y * v.y)};
}

Boid::Boid::Boid(Vector2d::Vector2d const& pos, Vector2d::Vector2d const& vel,
                 Vector2d::Vector2d const& acc)  // constructor
    : position_{pos}, velocity_{vel} {
  // create boid triangle shape so that we know where they're pointing

  shape_.setPointCount(3);
  shape_.setPoint(0, sf::Vector2f(0, -10));
  shape_.setPoint(1, sf::Vector2f(-5, 5));
  shape_.setPoint(2, sf::Vector2f(5, 5));
  shape_.setPosition(position_.x, position_.y);
  shape_.setFillColor(sf::Color::White);  // White color
}

double Boid::Boid::Distance(Boid const& b1, Boid const& b2) {
  double dx = b1.position_.x - b2.position_.x;
  double dy = b1.position_.y - b2.position_.y;
  return std::sqrt(dx * dx + dy * dy);
}

Vector2d::Vector2d Boid::Boid::GetPosition(Boid const& b) {
  return b.position_;
}

Vector2d::Vector2d Boid::Boid::GetVelocity(Boid const& b) {
  return b.velocity_;
}

void Boid::Boid::Draw(sf::RenderWindow& window) const { window.draw(shape_); }

void Boid::Boid::UpdatePosition() {
  position_ += velocity_;
  shape_.setPosition(position_.x, position_.y);
}
