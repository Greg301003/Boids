#ifndef BOIDS_HPP
#define BOIDS_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

class Vector2d {
 public:
  double x{};
  double y{};

  Vector2d operator+=(Vector2d const&);     //somma tra vettori
  Vector2d operator*(double const&);      //prodotto per scalare
  double length(Vector2d const&);     //ritorna la lunghezza del vettore
};

class Boid {
  Vector2d position_{};
  Vector2d velocity_{};
  sf::ConvexShape shape_;

 public:
  Boid(Vector2d const& pos, Vector2d const& vel, Vector2d const& acc)     //constructor
      : position_{pos}, velocity_{vel} {
        //create boid shape (choice: triangle)
      }

  Vector2d GetPosition(Boid const&);      //ritorna la posizione del boid
  Vector2d GetVelocity(Boid const&);      //ritorna la velocità del boid

  double Distance(Boid const& b1, Boid const& b2);      //ritorna la distanza tra due boid

  void Draw(sf::RenderWindow& window) const;      //draw boid
};

#endif
