#include "source.h"

source::source() {
  value = phasor();
  frequency = 0.0;
}

source::source(double magnitude, double freq) {
  value = phasor(rectPhasor(magnitude, 0.0));
  frequency = freq;
}

source::source(double magnitude, double freq, double offset) {
  value = phasor(rectPhasor(magnitude, offset));
  frequency = freq;
}