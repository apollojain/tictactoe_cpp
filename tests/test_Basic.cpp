#include "doctest.h"

#include <unistd.h>

SCENARIO("trivial check") {

  GIVEN("a one second sleep duration") {
    unsigned int duration =1 ;

    CHECK(duration == 1);
  }
} 
