#ifndef BOIDS_HPP
#define BOIDS_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

namespace bd {
class Boid {
  sf::Vector2<float> position_{};
  sf::Vector2<float> velocity_{};
  sf::ConvexShape shape_;
  double rotation_speed_;

 public:
  Boid(sf::Vector2<float> const& pos, sf::Vector2<float> const& vel, double rotation_speed);    // constructor

  ////sf::Vector2<float> GetPosition(Boid const&);  // ritorna la posizione del boid

  sf::Vector2<float> GetPosition() const;


  sf::Vector2<float> GetVelocity(Boid const&);  // ritorna la velocità del boid

  double Distance(Boid const& b1,
                  Boid const& b2);  // ritorna la distanza tra due boid

  void Draw(sf::RenderWindow& window) const;  // draw boid

  void UpdatePosition(sf::Vector2<float> windowSize, std::vector<Boid> const& boids); //update boids

  void UpdateRotation(); //trying rotation

  sf::Vector2<float> Cohesion(std::vector<Boid> const& boids);
 //first try cohesion


  sf::Vector2<float> Normalize(sf::Vector2<float> const& vector); //used to sustain cohesion
  

  //decl alignment first try
  sf::Vector2<float> Alignment(std::vector<Boid> const& boids);



};
}  // namespace bd

#endif
