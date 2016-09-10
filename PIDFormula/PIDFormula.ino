float calcError(float setValue, float currValue) {
  return setValue - currValue;
  }

float calcP(float error, float kp) {
  return error * kp;
  }

float accuError(float error, float lastError) {
  return error + lastError;
  }

float calcI(float accuError, float ki) {
  return accuError * ki;
  }

float rateofC(float error, float lastError) {
  return error - lastError;
  }

float calcD(float error, float lastError, float kd) {
  return rateofC(error, lastError) * kd;
  }
