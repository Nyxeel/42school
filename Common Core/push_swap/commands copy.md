---

## **Push Swap: Mechanical Turk – Präzise Schritt-für-Schritt-Anleitung**

---

### **1. Vorbereitung & Initialisierung**

* Zwei Stacks:

  * **Stack A**: Enthält alle Eingabewerte, unsortiert.
  * **Stack B**: Ist am Anfang leer.
* Ziel: Am Ende ist **Stack A aufsteigend sortiert**, **Stack B ist leer**.
* Nur die vorgegebenen Push-Swap-Befehle sind erlaubt (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).

---

### **2. Spezialfälle für kleine Listen**

* **Stack A mit 2 Elementen:**

  * Prüfen und ggf. mit einem Swap (`sa`) sortieren.
* **Stack A mit 3 Elementen:**

  * Mit gezielten Befehlen (`sa`, `ra`, `rra`) sortieren.

---

### **3. Push-Phase: Elemente von A nach B verschieben (Hauptlogik)**

* **Beginne damit, die ersten beiden Elemente von A nach B zu pushen** (`pb`, `pb`).
* Nun enthält Stack B zwei Werte.

---

#### **Wichtigster Schritt – Auswahl des „günstigsten“ Elements**

* **Für alle verbleibenden Elemente in Stack A:**

  1. **Berechne für jedes Element:**

     * **Wie viele Rotationen in Stack A** wären nötig, damit dieses Element oben liegt?
     * **Wie viele Rotationen in Stack B** wären nötig, damit dieses Element optimal einsortiert werden kann (richtige Position/intervall, Maximum, Minimum)?
     * **Gesamtkosten**: Addiere die Rotationen für Stack A und Stack B.
  2. **Vergleiche für alle Elemente in Stack A diese Gesamtkosten.**
  3. **Wähle das Element mit den niedrigsten Gesamtkosten** (also: das, welches mit den wenigsten Befehlen in B eingefügt werden kann).
  4. **Führe die notwendigen Rotationen in Stack A und Stack B aus,** damit das gewünschte Element oben auf A und die Zielposition oben auf B liegt.
  5. **Pushe das Element von A nach B** (`pb`).

* **Wiederhole diesen Prozess, bis in Stack A nur noch 3 Werte übrig sind!**

---

### **4. Sortiere die letzten 3 Werte in Stack A**

* Sortiere die 3 verbleibenden Elemente in Stack A mit einer festen, kleinen Logik (`sa`, `ra`, `rra`), bis sie aufsteigend stehen.

---

### **5. Rückführ-Phase: Werte aus Stack B zurück nach Stack A**

* **Solange Stack B nicht leer ist:**

  * **Finde das größte Element in B.**
  * Rotiere Stack B (`rb` oder `rrb`), bis das größte Element oben liegt.
  * **Push das Element von B nach A** (`pa`).
    So landet jeweils das größte Element wieder oben in Stack A.
  * Wiederholen, bis Stack B leer ist.

---

### **6. Feinschliff (optional):**

* Prüfe, ob das Minimum in Stack A ganz oben steht.
* Wenn nicht: Rotiere A (`ra` oder `rra`), bis das Minimum ganz oben ist.
* Jetzt ist Stack A endgültig sortiert.

---

## **Check- und Entscheidungsregeln im Mechanical Turk-Ansatz**

* Prüfe für jedes Element in Stack A:

  * Wie viele Schritte sind notwendig, um es oben auf A zu bekommen?
  * Wie viele Schritte, um die korrekte Einfügeposition in B zu erreichen?
  * Wo ist die günstigste Stelle (zwischen zwei Werten, Maximum, Minimum)?
  * Welche Rotationsrichtung (`ra`/`rra` bzw. `rb`/`rrb`) ist jeweils optimal?
* Verschiebe immer das Element, das insgesamt die wenigsten Schritte braucht.

---

## **Warum ist dieses Vorgehen sinnvoll?**

* Stack B bleibt immer „geordnet“ – so ist das Rücksortieren nach A besonders effizient.
* Das gezielte Verschieben der „günstigsten“ Zahl minimiert die Gesamtzahl der Operationen und verhindert ineffizientes Hin- und Herschieben.
* Durch das finale Nachsortieren ist Stack A garantiert aufsteigend sortiert.

---

## **Kurzfassung der Gesamtschritte für deine Umsetzung:**

1. **Spezialfall prüfen:** Kleine Listen direkt sortieren.
2. **Zwei Elemente von A nach B schieben.**
3. **Solange mehr als 3 Werte in A:**

   * Für jedes Element in A alle Kosten berechnen.
   * Günstigstes Element wählen.
   * Beide Stacks passend rotieren.
   * Element nach B pushen.
4. **Drei Werte in A sortieren.**
5. **Alle Werte aus B nach A zurückschieben (immer das größte zuerst).**
6. **A ggf. so rotieren, dass das Minimum oben steht.**

---

**Damit hast du die präzise Mechanical Turk Strategie, inklusive der cleveren Wahl des günstigsten Elements, wie sie im Artikel beschrieben ist.**

Wenn du zu einzelnen Abschnitten (z.B. Kostenberechnung, Rotationsentscheidung, Intervallfindung) eine noch genauere Schrittanleitung oder ein Beispiel brauchst, sag Bescheid!
