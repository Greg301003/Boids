#include "boids.hpp"

#include <cmath>

bd::Boid::Boid(sf::Vector2<float> const& pos, sf::Vector2<float> const& vel,
               double rotation_speed)  // constructor
    : position_{pos}, velocity_{vel}, rotation_speed_{rotation_speed} {
  // create boid triangle shape so that we know where they're pointing

  shape_.setPointCount(4);
  shape_.setPoint(0, sf::Vector2<float>(20, 0));
  shape_.setPoint(1, sf::Vector2<float>(0, -8));
  shape_.setPoint(2, sf::Vector2<float>(5, 0));
  shape_.setPoint(3, sf::Vector2<float>(0, 8));
  shape_.setPosition(position_.x, position_.y);
  sf::Color color(60, 60, 255, 180);  //light blue
  shape_.setFillColor(color);

  // trying to fix rotation
  // shape_.setOrigin(position_.x, position_.y);
}

double bd::Boid::Distance(Boid const& b1, Boid const& b2) {
  double dx = b1.position_.x - b2.position_.x;
  double dy = b1.position_.y - b2.position_.y;
  return std::sqrt(dx * dx + dy * dy);
}

sf::Vector2<float> bd::Boid::GetPosition(Boid const& b) { return b.position_; }

sf::Vector2<float> bd::Boid::GetVelocity(Boid const& b) { return b.velocity_; }

void bd::Boid::Draw(sf::RenderWindow& window) const { window.draw(shape_); }

void bd::Boid::UpdatePosition(sf::Vector2<float> windowSize) {
  

position_ += velocity_;

    // Controlla se il boid ha superato i bordi della finestra
    if (position_.x < 0) {
        position_.x += windowSize.x;
    }
    else if (position_.x > windowSize.x) {
        position_.x -= windowSize.x;
    }

    if (position_.y < 0) {
        position_.y += windowSize.y;
    }
    else if (position_.y > windowSize.y) {
        position_.y -= windowSize.y;
    }




  shape_.setPosition(position_.x, position_.y);
}

void bd::Boid::UpdateRotation() {
  double angle = std::atan2(velocity_.y, velocity_.x);
  // adding rotation speed
  shape_.setRotation(static_cast<float>(angle * 180.0 / M_PI) +
                     static_cast<float>(rotation_speed_));
}



// try cohesion


sf::Vector2<float> bd::Boid::Cohesion(std::vector<Boid> const& boids) {

//CM center of mass
  sf::Vector2<float> CM(0.0f, 0.0f);

  //counts boids
  int count = 0;


  // Sum of boids positions


  for (auto const& boid : boids) {


    // Ignore himself obv


    if (&boid != this) {
      centerOfMass += boid.GetPosition();
      count++;
    }
    

//calculate CM

  if (count > 0) {
    centerOfMass /= static_cast<float>(count);
  }

//calculate boids direction???

  sf::Vector2<float> cohesionDirection = centerOfMass - position_;
  cohesionDirection = Normalize(cohesionDirection);


return cohesionDirection;

}


//defining normalize funct

sf::Vector2<float> Normalize(sf::Vector2<float> const& vector) {
  float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
  if (length > 0.0f) {
    return vector / length;
  } else {
    return vector;
  }
}