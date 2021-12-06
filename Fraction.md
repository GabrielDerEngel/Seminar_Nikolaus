# Beispiel Klasse `Fraction`

## Einführung

In dieser Übung wollen wir uns der Klasse `Fraction` in einer
zusammenfassenden Betrachtung annehmen.

---

Folgenden Eigenschaften sollen in Ihrer Realisierung der Klasse `Fraction` Berücksichtigung finden:

  * Objekte der Klasse `Fraction` sollen die von ihr verwaltete rationale Zahl immer in einer
    optimal gekürzten Form verwalteten. Schreiben Sie dazu eine Methode `reduce`, die den
    Bruch optimal kürzt.

  * Rationale Zahlen können sowohl positiv als auch negativ sein. Um die klasseninterne
    Arbeitsweise der einzelnen Methoden zu vereinfachen, soll die Regel gelten, dass der
    Nenner einer rationalen Zahl immer positiv ist. Damit kann der Zähler eines
    `Fraction`-Objekts in Abhängigkeit vom Vorzeichen der rationalen Zahl entweder positiv
    oder negativ sein. Achten Sie darauf, dass bei allen Änderungen am Objektzustand (zum
    Beispiel nach einer Subtraktion) der Nenner positiv ist.

  * Gängige Konstruktoren zur Objekterzeugung.

  * Implementieren Sie die folgenden mathematischen Rechenoperationen:
    * Grundrechenoperationen (`+`, `-`, `*` und `/`).
    * Inkrement- und Dekrementoperator (`++` und `--`).
    * Inverse einer rationalen Zahl (Operator `~`).
    * Unärer Minus-Operator (`-`).
    * Vergleichsoperatoren (`==`, `!=`, `<`, `<=`, `>` und `>=`).

  * Implementieren Sie die folgenden mathematischen Rechenoperationen als Methode:
    * Methode `add`, `sub`, `mul`, `div`

  * Methode `gcd` (*greatest common divisor*) zur Bestimmung des größten gemeinsamen Teilers von Zähler und Nenner (*ggT*).
    Die `gcd`-Methode kann von der `reduce`-Methode verwendet werden.

  * Operatoren zur Typumwandlung: Ein `Fraction`-Objekt soll in einem arithmetischen
    Ausdruck auch dann verwendet werden können, wenn auf Grund des Kontextes ein `float` oder
    `double`-Wert erwartet wird.

  * Ein- und Ausgabe: Eine rationale Zahl soll in der Form &ldquo;Zähler / Nenner&ldquo; ausgegeben werden.
    Für Eingaben ist dasselbe Format zu Grunde zu legen. Zwischen den numerischen
    Werten und dem Schrägstrich sind beliebige Leerzeichen und Tabulatoren erlaubt.

---

Eine Hilfestellung: Header-Datei `Fraction.h`

```cpp
class Fraction
{
private:
    // private member data
    int m_num;    // numerator
    int m_denom;  // denominator

public:
    // c'tors
    Fraction();
    Fraction(int, int);

    // conversion c'tor
    Fraction(int);

    // getter / setter
    int getNum() const { return m_num; };
    void setNum(int num);
    int getDenom() const { return m_denom; };
    void setDenom(int denom);

    // unary arithmetic operators
    friend Fraction operator- (const Fraction&);
    friend Fraction operator~ (const Fraction&);

    // binary arithmetic operators
    friend Fraction operator+ (const Fraction&, const Fraction&);
    friend Fraction operator- (const Fraction&, const Fraction&);
    friend Fraction operator* (const Fraction&, const Fraction&);
    friend Fraction operator/ (const Fraction&, const Fraction&);

    // arithmetic-assignment operators
    friend const Fraction & operator+= (Fraction&, const Fraction&);
    friend const Fraction & operator-= (Fraction&, const Fraction&);
    friend const Fraction & operator*= (Fraction&, const Fraction&);
    friend const Fraction & operator/= (Fraction&, const Fraction&);

    // increment/decrement operators (prefix/postfix version)
    friend Fraction & operator++ (Fraction&);           // prefix increment
    friend const Fraction operator++ (Fraction&, int);  // postfix increment
    friend Fraction & operator-- (Fraction&);           // prefix decrement
    friend const Fraction operator-- (Fraction&, int);  // postfix decrement

    // comparison operators
    friend bool operator<= (const Fraction&, const Fraction&);
    friend bool operator<  (const Fraction&, const Fraction&);
    friend bool operator>= (const Fraction&, const Fraction&);
    friend bool operator>  (const Fraction&, const Fraction&);
    friend bool operator== (const Fraction&, const Fraction&);
    friend bool operator!= (const Fraction&, const Fraction&);

    // type conversion operator (Fraction -> double)
    operator double();

    // input / output operators
    friend std::ostream & operator<< (std::ostream&, const Fraction&);
    friend std::istream & operator>> (std::istream&, Fraction&);

    private:
    // private helper methods
    void checkSigns();
    void reduce();

private:
    // private class helper method
    static int gcd(int n, int m);
};
```

---
