#ifndef COMP_H_
#define COMP_H_

#include "phasor.h"

class component {
public:
  phasor values;
  phasor imp;
  double frequency;

  virtual phasor calcImp() = 0;
  void displayImp() { imp.display(); }
  void displayValue() { values.display(); }
};

class resistor : public component {
public:
  virtual phasor calcImp();
  resistor();
  resistor(double);
  resistor(double, double);
  resistor(double, double, double);
};

class capacitor : public component {
public:
  virtual phasor calcImp();
  capacitor();
  capacitor(double);  // imp
  capacitor(double, double);  // mag, freq
  capacitor(double, double, double);  // mag, freq, offset
};

class inductor : public component {
public:
  virtual phasor calcImp();
  inductor();
  inductor(double);
  inductor(double, double);
  inductor(double, double, double);
};

#endif  //COMP_H_