char cmd; // The Bluetooth Command

// تعريف الأرجل الخاصة بالمحرك الأول (Motor A)
const int motorAForward = 6;  // IN1
const int motorABackward = 7; // IN2
const int enableA = 9;        // ENA (PWM)

// تعريف الأرجل الخاصة بالمحرك الثاني (Motor B)
const int motorBForward = 5;  // IN3
const int motorBBackward = 12; // IN4
const int enableB = 10;       // ENB (PWM)

// تعريف الأرجل الخاصة بالمحرك الثالث (Motor C)
const int motorCForward = 11;  // IN5
const int motorCBackward = 8;  // IN6
const int enableC = 13;        // ENC (PWM)

// تعريف الأرجل الخاصة بالمحرك الرابع (Motor D)
const int motorDForward = 14;  // IN7
const int motorDBackward = 15; // IN8
const int enableD = 16;        // END (PWM)

void setup() {
  // إعداد الأرجل الخاصة بالمحركات
  pinMode(motorAForward, OUTPUT);
  pinMode(motorABackward, OUTPUT);
  pinMode(enableA, OUTPUT);

  pinMode(motorBForward, OUTPUT);
  pinMode(motorBBackward, OUTPUT);
  pinMode(enableB, OUTPUT);

  pinMode(motorCForward, OUTPUT);
  pinMode(motorCBackward, OUTPUT);
  pinMode(enableC, OUTPUT);

  pinMode(motorDForward, OUTPUT);
  pinMode(motorDBackward, OUTPUT);
  pinMode(enableD, OUTPUT);

  // إعداد التواصل التسلسلي مع البلوتوث
  Serial.begin(9600);  // سرعة الاتصال 9600 baud
}

void loop() {
  // التحقق إذا كان هناك بيانات متاحة من البلوتوث
  if (Serial.available()) {
    cmd = Serial.read(); // قراءة الأمر المرسل عبر البلوتوث
  }

  // إذا كان الأمر هو "F"، تشغيل جميع المحركات للأمام بسرعة ثابتة 100%
  if (cmd == 'F') {
    analogWrite(enableA, 255); // سرعة 100% (أقصى سرعة)
    analogWrite(enableB, 255); // سرعة 100% (أقصى سرعة)
    analogWrite(enableC, 255); // سرعة 100% (أقصى سرعة)
    analogWrite(enableD, 255); // سرعة 100% (أقصى سرعة)
    
    // تشغيل جميع المحركات للأمام
    digitalWrite(motorAForward, HIGH);
    digitalWrite(motorABackward, LOW);
    digitalWrite(motorBForward, HIGH);
    digitalWrite(motorBBackward, LOW);
    digitalWrite(motorCForward, HIGH);
    digitalWrite(motorCBackward, LOW);
    digitalWrite(motorDForward, HIGH);
    digitalWrite(motorDBackward, LOW);
  }
  // إذا كان الأمر هو "B"، تشغيل جميع المحركات للخلف بسرعة ثابتة 100%
  else if (cmd == 'B') {
    analogWrite(enableA, 255); // سرعة 100%
    analogWrite(enableB, 255); // سرعة 100%
    analogWrite(enableC, 255); // سرعة 100%
    analogWrite(enableD, 255); // سرعة 100%

    // تشغيل جميع المحركات للخلف
    digitalWrite(motorAForward, LOW);
    digitalWrite(motorABackward, HIGH);
    digitalWrite(motorBForward, LOW);
    digitalWrite(motorBBackward, HIGH);
    digitalWrite(motorCForward, LOW);
    digitalWrite(motorCBackward, HIGH);
    digitalWrite(motorDForward, LOW);
    digitalWrite(motorDBackward, HIGH);
  }
  // إذا كان الأمر هو "L"، تحريك السيارة لليسار
  else if (cmd == 'L') {
    analogWrite(enableA, 255); // سرعة 100%
    analogWrite(enableB, 255); // سرعة 100%
    analogWrite(enableC, 255); // سرعة 100%
    analogWrite(enableD, 255); // سرعة 100%

    // تحريك السيارة لليسار
    digitalWrite(motorAForward, LOW);  // المحرك A للخلف
    digitalWrite(motorABackward, HIGH);

    digitalWrite(motorBForward, HIGH); // المحرك B للأمام
    digitalWrite(motorBBackward, LOW);

    digitalWrite(motorCForward, LOW);  // المحرك C للخلف
    digitalWrite(motorCBackward, HIGH);

    digitalWrite(motorDForward, HIGH); // المحرك D للأمام
    digitalWrite(motorDBackward, LOW);
  }
  // إذا كان الأمر هو "R"، تحريك السيارة لليمين
  else if (cmd == 'R') {
    analogWrite(enableA, 255); // سرعة 100%
    analogWrite(enableB, 255); // سرعة 100%
    analogWrite(enableC, 255); // سرعة 100%
    analogWrite(enableD, 255); // سرعة 100%

    // تحريك السيارة لليمين
    digitalWrite(motorAForward, HIGH);  // المحرك A للأمام
    digitalWrite(motorABackward, LOW);

    digitalWrite(motorBForward, LOW);   // المحرك B للخلف
    digitalWrite(motorBBackward, HIGH);

    digitalWrite(motorCForward, HIGH);  // المحرك C للأمام
    digitalWrite(motorCBackward, LOW);

    digitalWrite(motorDForward, LOW);   // المحرك D للخلف
    digitalWrite(motorDBackward, HIGH);
  }
  // إذا لم يكن هناك أمر، توقف المحركات
  else {
    digitalWrite(motorAForward, LOW);
    digitalWrite(motorABackward, LOW);
    digitalWrite(motorBForward, LOW);
    digitalWrite(motorBBackward, LOW);
    digitalWrite(motorCForward, LOW);
    digitalWrite(motorCBackward, LOW);
    digitalWrite(motorDForward, LOW);
    digitalWrite(motorDBackward, LOW);
  }

  delay(50); // تأخير صغير
}
  
