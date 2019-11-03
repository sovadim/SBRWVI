int pinA = 2; // Пины прерываний
int pinB = 3; // Пины прерываний

volatile long pause    = 1;  // Пауза для борьбы с дребезгом
volatile long lastTurn = 0;   // Переменная для хранения времени последнего изменения

volatile int count = 0;       // Счетчик оборотов
int actualcount    = 0;       // Временная переменная определяющая изменение основного счетчика

volatile int state = 0;       // Статус одного шага - от 0 до 4 в одну сторону, от 0 до -4 - в другую

volatile int pinAValue = 0;   // Переменные хранящие состояние пина, для экономии времени
volatile int pinBValue = 0;   // Переменные хранящие состояние пина, для экономии времени


void setup()
{
  pinMode(pinA, INPUT);           // Пины в режим приема INPUT
  pinMode(pinB, INPUT);           // Пины в режим приема INPUT

  attachInterrupt(0, A, CHANGE);  // Настраиваем обработчик прерываний по изменению сигнала
  attachInterrupt(1, B, CHANGE);  // Настраиваем обработчик прерываний по изменению сигнала

  Serial.begin(9600);             // Включаем Serial
}

void loop()
{
  if (actualcount != count) {     // Чтобы не загружать ненужным выводом в Serial, выводим состояние
    actualcount = count;          // счетчика только в момент изменения
    Serial.println(actualcount);
  }
}

void A()
{
  if (micros() - lastTurn < pause) return;  // Если с момента последнего изменения состояния не прошло
  // достаточно времени - выходим из прерывания
  pinAValue = digitalRead(pinA);            // Получаем состояние пинов A и B
  pinBValue = digitalRead(pinB);

  cli();    // Запрещаем обработку прерываний, чтобы не отвлекаться
  if (state == 0  && !pinAValue &&  pinBValue || state == 2  && pinAValue && !pinBValue) {
    state += 1; // Если выполняется условие, наращиваем переменную state
    lastTurn = micros();
  }
  if (state == -1 && !pinAValue && !pinBValue || state == -3 && pinAValue &&  pinBValue) {
    state -= 1; // Если выполняется условие, наращиваем в минус переменную state
    lastTurn = micros();
  }
  setCount(state); // Проверяем не было ли полного шага из 4 изменений сигналов (2 импульсов)
  sei(); // Разрешаем обработку прерываний

  if (pinAValue && pinBValue && state != 0) state = 0; // Если что-то пошло не так, возвращаем статус в исходное состояние
}

void B()
{
  if (micros() - lastTurn < pause) return;
  pinAValue = digitalRead(pinA);
  pinBValue = digitalRead(pinB);

  cli();
  if (state == 1 && !pinAValue && !pinBValue || state == 3 && pinAValue && pinBValue) {
    state += 1; // Если выполняется условие, наращиваем переменную state
    lastTurn = micros();
  }
  if (state == 0 && pinAValue && !pinBValue || state == -2 && !pinAValue && pinBValue) {
    state -= 1; // Если выполняется условие, наращиваем в минус переменную state
    lastTurn = micros();
  }
  setCount(state); // Проверяем не было ли полного шага из 4 изменений сигналов (2 импульсов)
  sei();
  
  if (pinAValue && pinBValue && state != 0) state = 0; // Если что-то пошло не так, возвращаем статус в исходное состояние
}

void setCount(int state) {          // Устанавливаем значение счетчика
  if (state == 4 || state == -4) {  // Если переменная state приняла заданное значение приращения
    count += (int)(state / 4);      // Увеличиваем/уменьшаем счетчик
    lastTurn = micros();            // Запоминаем последнее изменение
  }
}
