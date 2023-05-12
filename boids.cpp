#include "boids.hpp"

#include <cmath>

Vector2d Vector2d::operator+=(Vector2d const& v) {
  return {this->x + v.x, this->y + v.y}; 
  
   //si potrebbe cambiare con 
   //x += other.x;
   //y += other.y;
   //return *this;
   //?



}

//sostituisco l con scalar

Vector2d Vector2d::operator*(double const& scalar) { return {x * scalar, y * scalar}; }

double Vector2d::length(Vector2d const& v) {
  return {std::sqrt(v.x * v.x + v.y * v.y)};
}

Vector2d Boid::GetPosition(Boid const& b) { return b.position_; }

Vector2d Boid::GetVelocity(Boid const& b) { return b.velocity_; }