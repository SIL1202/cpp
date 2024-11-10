#include <iostream>
#include <sstream>
using namespace std;
class Gate {
public:
  Gate *input[2];
  virtual bool output() = 0;
  void setValue(Gate *gate, int pin);
  void setValue(bool val, int pin);
};

class TRUE : public Gate {
public:
  virtual bool output() { return true; }
  void setValue(Gate *, int) {}
  void setValue(bool, int) {}
};

class FALSE : public Gate {
public:
  virtual bool output() { return false; }
  void setValue(Gate *, int) {}
  void setValue(bool, int) {}
};

TRUE t;
FALSE f;

void Gate::setValue(bool val, int pin) {
  if (val)
    this->input[pin] = &t;
  else
    this->input[pin] = &f;
}

void Gate::setValue(Gate *gate, int pin) { this->input[pin] = gate; }

class NOT : public Gate {
public:
  virtual bool output() { return !(this->input[0]->output()); }
  void setValue(bool val, int pin = 0) {
    if (val)
      this->input[0] = &t;
    else
      this->input[0] = &f;
  }
  void setValue(Gate *gate, int pin = 0) { this->input[0] = gate; }
};

class NAND : public Gate {
public:
  virtual bool output() {
    return !(this->input[0]->output() && this->input[1]->output());
  }
};

class NOR : public Gate {
public:
  virtual bool output() {
    return !(this->input[0]->output() || this->input[1]->output());
  }
};

class AND : public Gate {
public:
  AND() {
    component[0] = new NAND();
    component[1] = new NOT();
  }

  virtual bool output() {
    component[0]->input[0] = this->input[0];
    component[0]->input[1] = this->input[1];
    component[1]->input[0] = component[0];
    return component[1]->output();
  }

private:
  Gate *component[2];
};

class OR : public Gate {
public:
  OR() {
    component[0] = new NOR();
    component[1] = new NOT();
  }

  virtual bool output() {
    component[0]->input[0] = this->input[0];
    component[0]->input[1] = this->input[1];
    component[1]->input[0] = component[0];
    return component[1]->output();
  }

private:
  Gate *component[2];
};

class XOR : public Gate {
public:
  XOR() {
    component[0] = new AND();
    component[1] = new AND();
    component[2] = new NOT();
    component[3] = new NOT();
    component[4] = new OR();
  }

  virtual bool output() {
    component[2]->input[0] = this->input[0]; // NOT gate for input[0]
    component[3]->input[0] = this->input[1]; // NOT gate for input[1]

    component[0]->input[0] =
        component[2]; // AND gate: NOT input[0] and input[1]
    component[0]->input[1] = this->input[1];

    component[1]->input[0] =
        this->input[0]; // AND gate: input[0] and NOT input[1]
    component[1]->input[1] = component[3];

    component[4]->input[0] =
        component[0]; // OR gate combining the two AND gates
    component[4]->input[1] = component[1];

    return component[4]->output();
  }

private:
  Gate *component[5];
};

class Adder {
public:
  virtual void setValue(bool, int) = 0;
  virtual void setValue(Gate *, int) = 0;
  virtual Gate *sum() = 0;
  virtual Gate *carryOut() = 0;
};

class OneBitHalfAdder : public Adder {
public:
  OneBitHalfAdder() {
    component[0] = new AND();
    component[1] = new XOR();
  }

  virtual void setValue(bool val, int pin) {
    component[0]->setValue(val, pin);
    component[1]->setValue(val, pin);
  }

  virtual void setValue(Gate *gate, int pin) {
    component[0]->setValue(gate, pin);
    component[1]->setValue(gate, pin);
  }

  virtual Gate *sum() { return component[1]; }

  virtual Gate *carryOut() { return component[0]; }

private:
  Gate *component[2]; // component[0] is AND, component[1] is XOR
};

class OneBitFullAdder : public Adder {
public:
  OneBitFullAdder() {
    a[0] = new OneBitHalfAdder(); // 表示第一個半加器
    a[1] = new OneBitHalfAdder(); // 表示第二個半加器
    carry = new OR();
  }

  virtual void setValue(bool val, int pin) {
    if (pin < 2) {
      a[0]->setValue(val, pin);
    } else {
      a[1]->setValue(val, 0);
    }
  }

  virtual void setValue(Gate *gate, int pin) {
    if (pin < 2) {
      a[0]->setValue(gate, pin);
    } else {
      a[1]->setValue(gate, 0);
    }
  }

  virtual Gate *sum() {
    a[1]->setValue(a[0]->sum(),
                   1); // 第一個半加器的sum進入到第二個半加器的第一個腳位
    return a[1]->sum(); // 回傳第二個半加器的sum。
  }

  virtual Gate *carryOut() {
    carry->setValue(a[0]->carryOut(),
                    0); // 第一個半加器的carryout進到OR的第一個腳位。
    carry->setValue(a[1]->carryOut(),
                    1); // 第二個半加器的carryout進到OR的第二個腳位。
    return carry;
  }

private:
  Adder *a[2]; // Two half adders
  Gate *carry; // OR gate for final carry out
};

class Decoder {
public:
  virtual void setValue(bool, int) = 0;
  virtual void setValue(Gate *, int) = 0;
  virtual void setEnable(bool) = 0;
  virtual void setEnable(Gate *) = 0;
  virtual int output() = 0;
  virtual Gate *operator[](int) = 0;

protected:
  Gate *enable;
};

class Decoder2_4 : public Decoder {
public:
  Decoder2_4() : Decoder2_4(0) {}
  Decoder2_4(bool val) {
    if (val)
      this->enable = &t;
    else
      this->enable = &f;
    for (int i = 0; i < 2; i++)
      component[i] = new NOT;
    for (int i = 2; i < 6; i++)
      component[i] = new AND;
    for (int i = 0; i < 4; i++)
      enables[i] = new AND;
  }
  virtual void setEnable(bool val) {
    if (val)
      this->enable = &t;
    else
      this->enable = &f;
  }
  virtual void setEnable(Gate *gate) { this->enable = gate; }
  virtual void setValue(Gate *gate, int i) {
    component[i % 2]->input[0] = gate;
  }
  virtual void setValue(bool val, int i) {
    if (val)
      component[i % 2]->input[0] = &t;
    else
      component[i % 2]->input[0] = &f;
  }
  virtual Gate *operator[](int n) {
    _out();
    switch (n) {
    case 0:
      return enables[0];
    case 1:
      return enables[1];
    case 2:
      return enables[2];
    case 3:
      return enables[3];
    default:
      return nullptr;
    }
  }
  friend ostream &operator<<(ostream &out, Decoder2_4 dec) {
    for (int i = 3; i >= 0; i--)
      out << dec[i]->output() << " ";
    return out;
  }
  virtual int output() {
    for (int i = 0; i < 4; i++)
      if (enables[i]->output())
        return i;
  }

private:
  Gate *component[6];
  Gate *enables[4];

  void _out() {
    component[2]->input[0] = component[0];
    component[2]->input[1] = component[1];

    component[3]->input[0] = component[0]->input[0];
    component[3]->input[1] = component[1];

    component[4]->input[0] = component[0];
    component[4]->input[1] = component[1]->input[0];

    component[5]->input[0] = component[0]->input[0];
    component[5]->input[1] = component[1]->input[0];

    for (int i = 0; i < 4; i++) {
      enables[i]->input[0] = this->enable;
      enables[i]->input[1] = component[i + 2];
    }
  }
};

class Decoder4_16 : public Decoder {
public:
  Decoder4_16() {
    for (int i = 0; i < 5; i++)
      dec2_4[i] = new Decoder2_4;
  }

  Decoder4_16(bool val) {
    for (int i = 0; i < 5; i++)
      dec2_4[i] = new Decoder2_4(val);
  }

  virtual void setEnable(bool val) {
    if (val)
      dec2_4[0]->setEnable(&t);
    else
      dec2_4[0]->setEnable(&f);
  }

  virtual void setEnable(Gate *gate) { dec2_4[0]->setEnable(gate); }

  virtual void setValue(bool val, int pin) {
    if (pin == 0)
      for (int i = 1; i < 5; i++)
        dec2_4[i]->setValue(val, 0);
    else if (pin == 1)
      for (int i = 1; i < 5; i++)
        dec2_4[i]->setValue(val, 1);
    else {
      if (pin == 2)
        dec2_4[0]->setValue(val, 0);
      else if (pin == 3)
        dec2_4[0]->setValue(val, 1);
    }
    for (int i = 1; i < 5; i++)
      dec2_4[i]->setEnable((*dec2_4[0])[i - 1]);
  }

  virtual void setValue(Gate *gate, int pin) {
    if (pin == 0)
      for (int i = 1; i < 5; i++)
        dec2_4[i]->setValue(gate, 0);
    else if (pin == 1)
      for (int i = 1; i < 5; i++)
        dec2_4[i]->setValue(gate, 1);
    else {
      if (pin == 2)
        dec2_4[0]->setValue(gate, 0);
      else if (pin == 3)
        dec2_4[0]->setValue(gate, 1);
    }
    for (int i = 1; i < 5; i++)
      dec2_4[i]->setEnable((*dec2_4[0])[i - 1]);
  }

  virtual Gate *operator[](int n) {
    switch (n) {
    case 0 ... 15:
      return (*dec2_4[(n / 4) + 1])[n % 4]; // return dec2_4[which decoder is
                                            // it][which output is it]
    default:
      return nullptr;
    }
  }

  friend ostream &operator<<(ostream &out, Decoder4_16 dec) {
    for (int i = 15; i >= 0; i--)
      out << dec[i]->output() << " ";
    return out;
  }

  int output() {
    for (int i = 0; i < 16; i++)
      if ((*this)[i]->output())
        return i;
    return -1;
  }

private:
  Decoder *dec2_4[5];
};
