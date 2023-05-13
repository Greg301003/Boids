#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "boids.hpp"

#include "doctest.h"

TEST_CASE("Testing Vector2d methods") {
  SUBCASE("Testing operator+=") {
    Vector2d i{1., 2.};
    Vector2d j{2., 1.};
    Vector2d sum = i + j;
    CHECK(sum.x == 3.);
    CHECK(sum.y == 3.);

    Vector2d i{1., 2.};
    Vector2d j{0., 0.};
    Vector2d sum = i + j;
    CHECK(sum.x == 1.);
    CHECK(sum.y == 2.);

    Vector2d i{1., 2.};
    Vector2d j{-5., -2.};
    CHECK(sum.x == -4.);
    CHECK(sum.y == 0.);
  }

  SUBCASE("Testing operator*")
}

TEST_CASE("Testing Boid methods"){
    SUBCASE("Testing GetPosition")
    SUBCASE("Testing GetVelocity")
    SUBCASE("Testing Distance")
}
