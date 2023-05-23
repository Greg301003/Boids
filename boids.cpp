#include "boids.hpp"

#include <cmath>


double Vector2d::length(Vector2d const& v) {
  return {std::sqrt(v.x * v.x + v.y * v.y)};
}

Boid::Boid::Boid(Vector2d::Vector2d const& pos, Vector2d::Vector2d const& vel,
                 Vector2d::Vector2d const& acc, double rotation_speed)  // constructor
    : position_{pos}, velocity_{vel}, rotation_speed_{rotation_speed} {
  // create boid triangle shape so that we know where they're pointing

  shape_.setPointCount(3);
  shape_.setPoint(0, sf::Vector2f(15, 0));
  shape_.setPoint(1, sf::Vector2f(0, -8));
  shape_.setPoint(2, sf::Vector2f(0, 8));
  shape_.setPosition(position_.x, position_.y);
  shape_.setFillColor(sf::Color::White);  // White color


  //trying to fix rotation 
  //shape_.setOrigin(position_.x, position_.y);
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


void Boid::Boid::UpdateRotation() {
  double angle = std::atan2(velocity_.y, velocity_.x);
  //adding rotation speed
  shape_.setRotation(static_cast<float>(angle * 180.0 / M_PI)+ static_cast<float>(rotation_speed_));
}
