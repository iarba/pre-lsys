#ifndef LSYS_REST_V

  #include "config.hpp"
  #include "decrement.hpp"
  #define LSYS_REST_V 4
  #include "lsys.hpp"

#elif LSYS_REST_V == 0

  #undef LSYS_REST_V
  #define LSYS_REST_V axion

#else

  #define AUX_V dec(LSYS_REST_V)
  #undef LSYS_REST_V
  #define LSYS_REST_V AUX_V
  #undef AUX_V
  #include "lsys.hpp"

#endif
