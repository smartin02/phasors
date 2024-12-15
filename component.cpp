#include "component.h"
/*
Unfortunately, this code is mostly duplicate code.
Someone should figure out a way to reduce the duplication and increase the
  readability.
*/


// RESISTOR
resistor::resistor() {
  values = phasor();
  imp = phasor();
  frequency = 0.0;
}

resistor::resistor(double impedance) {
  values = phasor(rectPhasor(impedance, 0.0));
  frequency = 0.0;
  imp = calcImp();
}

resistor::resistor(double magnitude, double freq) {
  values = phasor(rectPhasor(magnitude, 0.0));
  frequency = freq;
  imp = calcImp();
}

resistor::resistor(double magnitude, double freq, double offset) {
  values = phasor(polPhasor(magnitude, offset));
  frequency = freq;
  imp = calcImp();
}

phasor resistor::calcImp() {
  return values;
}


// CAPACITOR
capacitor::capacitor() {
  values = phasor();
  imp = phasor();
  frequency = 0.0;
}

capacitor::capacitor(double impedance) {
  imp = phasor(rectPhasor(0.0, impedance));
  frequency = 0.0;
  values = phasor(rectPhasor(0.0, impedance));
}
// The impedance being equal to calcImp() before the constructor is finished
// may cause some unforseen issues...
capacitor::capacitor(double magnitude, double freq) {
  values = phasor(rectPhasor(magnitude, 0.0));
  frequency = freq;
  imp = calcImp();
}

capacitor::capacitor(double magnitude, double freq, double offset) {
  values = phasor(polPhasor(magnitude, offset));
  frequency = freq;
  imp = calcImp();
}

phasor capacitor::calcImp() {
  double m = -1.0 / (values.getMag() * frequency);

  return phasor(rectPhasor(0.0, m));
}


// INDUCTOR
inductor::inductor() {
  values = phasor();
  imp = phasor();
  frequency = 0.0;
}

inductor::inductor(double impedance) {
  imp = phasor(rectPhasor(0.0, impedance));
  frequency = 0.0;
  values = phasor(rectPhasor(0.0, impedance)); 
}

inductor::inductor(double magnitude, double freq) {
  values = phasor(rectPhasor(magnitude, 0.0));
  frequency = freq;
  imp = calcImp();
}

inductor::inductor(double magnitude, double freq, double offset) {
  values = phasor(polPhasor(magnitude, offset));
  frequency = freq;
  imp = calcImp();
}

phasor inductor::calcImp() {
  double m = values.getMag() * frequency;

  return phasor(rectPhasor(0.0, m));
}