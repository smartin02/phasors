#ifndef SOURCE_H_
#define SOURCE_H_

#include "phasor.h"

class source {
public:
  phasor value;
  double frequency;
  source();
  source(double, double);
  source(double, double, double);
};

#endif //SOURCE_H_
