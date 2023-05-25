#include "boids.hpp"

#include <cmath>

// adding a max velocity

float maxVelocity = 0.1f;

// and a damping factor to mitigate the vel

float dampingFactor = 0.99999f;

bd::Boid::Boid(sf::Vector2<float> const& pos, sf::Vector2<float> const& vel,
               double rotation_speed, BoidBehavior behavior)  // constructor
    : position_{pos},
      velocity_{vel},
      rotation_speed_{rotation_speed},
      behavior_{behavior} {
  // create boid triangle shape so that we know where they're pointing

  shape_.setPointCount(4);
  shape_.setPoint(0, sf::Vector2<float>(20, 0));
  shape_.setPoint(1, sf::Vector2<float>(0, -8));
  shape_.setPoint(2, sf::Vector2<float>(5, 0));
  shape_.setPoint(3, sf::Vector2<float>(0, 8));
  shape_.setPosition(position_.x, position_.y);
 // sf::Color color(60, 60, 255, 180);  // light blue
 // shape_.setFillColor(color);




    switch (behavior_) {
    case BoidBehavior::Bird1:
      color_ = sf::Color(60, 60, 255, 180);  // Rosso
      break;
    case BoidBehavior::Bird2:
      color_ = sf::Color(0, 255, 0);  // Verde
      break;

  }

  shape_.setFillColor(color_);

  // trying to fix rotation
  // shape_.setOrigin(position_.x, position_.y);
}

double bd::Boid::Distance(Boid const& b1, Boid const& b2) {
  double dx = b1.position_.x - b2.position_.x;
  double dy = b1.position_.y - b2.position_.y;
  return std::sqrt(dx * dx + dy * dy);
}

////sf::Vector2<float> bd::Boid::GetPosition(Boid const& b) { return
/// b.position_; }

sf::Vector2<float> bd::Boid::GetPosition() const { return position_; }

sf::Vector2<float> bd::Boid::GetVelocity() const { return velocity_; }

void bd::Boid::Draw(sf::RenderWindow& window) const { window.draw(shape_); }

void bd::Boid::UpdatePosition(sf::Vector2<float> windowSize,
                              std::vector<Boid> const& boids,
                              float separation_radius) {


 sf::Vector2<float> cohesionDirection = Cohesion(boids);

   sf::Vector2<float> alignmentDirection = Alignment(boids);

   sf::Vector2<float> separationDirection = Separation(boids, separation_radius);

//boid type

  switch (behavior_) {
    case BoidBehavior::Bird1:
      // Comportamento specifico per bird1

  // adding cohesion
 
  velocity_ += cohesionDirection * /*cohesion_strength*/ (0.0001f);

  // adding align

  velocity_ += alignmentDirection * /*alignment_strength*/ (0.0005f);

  // adding sep

  
  velocity_ += separationDirection * /*separation_strength*/ (0.01f);

  // Controlla se il boid ha superato i bordi della finestra
  if (position_.x < 0) {
    position_.x += windowSize.x;
  } else if (position_.x > windowSize.x) {
    position_.x -= windowSize.x;
  }

  if (position_.y < 0) {
    position_.y += windowSize.y;
  } else if (position_.y > windowSize.y) {
    position_.y -= windowSize.y;
  }

  shape_.setPosition(position_.x, position_.y);

  // cap velocity
  if (std::hypot(velocity_.x, velocity_.y) > maxVelocity) {
    velocity_ = bd::Boid::Normalize(velocity_) * maxVelocity;
  }

  // mitigate vel
  velocity_ *= dampingFactor;

  position_ += velocity_;


      break;

   case BoidBehavior::Bird2:
      // Comportamento specifico per bird2
  // adding cohesion
  //sf::Vector2<float> cohesionDirection = Cohesion(boids);
  velocity_ += cohesionDirection * /*cohesion_strength*/ (0.0001f);

  // adding align
  //sf::Vector2<float> alignmentDirection = Alignment(boids);
  velocity_ += alignmentDirection * /*alignment_strength*/ (0.0005f);

  // adding sep

  //sf::Vector2<float> separationDirection = Separation(boids, separation_radius);
  velocity_ += separationDirection * /*separation_strength*/ (0.01f);

  // Controlla se il boid ha superato i bordi della finestra
  if (position_.x < 0) {
    position_.x += windowSize.x;
  } else if (position_.x > windowSize.x) {
    position_.x -= windowSize.x;
  }

  if (position_.y < 0) {
    position_.y += windowSize.y;
  } else if (position_.y > windowSize.y) {
    position_.y -= windowSize.y;
  }

  shape_.setPosition(position_.x, position_.y);

  // cap velocity
  if (std::hypot(velocity_.x, velocity_.y) > maxVelocity) {
    velocity_ = bd::Boid::Normalize(velocity_) * maxVelocity;
  }

  // mitigate vel
  velocity_ *= dampingFactor;

  position_ += velocity_;





      break;
  }





}

void bd::Boid::UpdateRotation() {
  double angle = std::atan2(velocity_.y, velocity_.x);
  // adding rotation speed
  shape_.setRotation((static_cast<float>(angle * 180.0 / M_PI) +
                      static_cast<float>(rotation_speed_)));
}

// try cohesion

sf::Vector2<float> bd::Boid::Cohesion(std::vector<Boid> const& boids) {
  // CM center of mass
  sf::Vector2<float> CM(0.0f, 0.0f);

  // counts boids
  int count = 0;

  // Sum of boids positions

  for (auto const& boid : boids) {
    // Ignore himself obv

    if (&boid != this) {
      CM += boid.GetPosition();
      count++;
    }
  }
  // calculate CM

  if (count > 0) {
    CM /= static_cast<float>(count);
  }

  // calculate boids direction???

  sf::Vector2<float> cohesionDirection = CM - position_;
  cohesionDirection = bd::Boid::Normalize(cohesionDirection);

  return cohesionDirection;
}

// def align

sf::Vector2<float> bd::Boid::Alignment(std::vector<Boid> const& boids) {
  sf::Vector2<float> averageVelocity(0.0f, 0.0f);
  int count = 0;

  for (auto const& boid : boids) {
    if (&boid != this) {
      averageVelocity += boid.GetVelocity();
      count++;
    }
  }

  if (count > 0) {
    averageVelocity /= static_cast<float>(count);
  }

  return averageVelocity;
}

// defining normalize funct

sf::Vector2<float> bd::Boid::Normalize(sf::Vector2<float> const& vector) {
  float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
  if (length > 0.0f) {
    return vector / length;
  } else {
    return vector;
  }
}

// def sep
sf::Vector2<float> bd::Boid::Separation(std::vector<Boid> const& boids,
                                        float separationRadius) {
  sf::Vector2<float> separationDirection(0.0f, 0.0f);

  for (auto const& boid : boids) {
    if (&boid != this) {
      double distance = Distance(*this, boid);
      if (distance < separationRadius) {
        sf::Vector2<float> direction = position_ - boid.GetPosition();
        direction = Normalize(direction);
        separationDirection += direction;
      }
    }
  }

  return separationDirection;
}
