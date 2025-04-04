// Definicija pinov
const int tipkaA = 2;          // Ključ za vžig (simuliran s tipko)
const int skrivnoStikaloB = 3; // Skrivno stikalo B
const int senzorM = 4;         // Senzor za zaznavanje delovanja motorja
const int zaganjalnik = 5;     // Izhod za zaganjalnik (npr. LED)

void setup() {
    pinMode(tipkaA, INPUT);
    pinMode(skrivnoStikaloB, INPUT);
    pinMode(senzorM, INPUT);
    pinMode(zaganjalnik, OUTPUT);
    digitalWrite(zaganjalnik, LOW); // Začetno stanje izklopljeno
}

void loop() {
    // Branje stanj vhodov
    bool aAktivno = digitalRead(tipkaA);
    bool bVklopljeno = digitalRead(skrivnoStikaloB);
    bool motorTece = digitalRead(senzorM);

    // Pogoji za aktivacijo zaganjalnika:
    // 1. Tipka A je pritisnjena (ključ obrnjen v desno)
    // 2. Skrivno stikalo B je vklopljeno
    // 3. Motor NE teče (senzor M je izklapljen)
    if (aAktivno && bVklopljeno && !motorTece) {
        digitalWrite(zaganjalnik, HIGH); // Vklopi zaganjalnik
    } else {
        digitalWrite(zaganjalnik, LOW); // Izklopi zaganjalnik
    }
}