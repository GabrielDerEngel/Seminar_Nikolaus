# Beispiel "Bankkonten"

Erstellen Sie eine Klasse `Account`, die das Guthaben eines Kontos verwaltet.
Zum Anlegen eines Kontos benötigt man (zur Vereinfachung der Aufgabenstellung) nur eine Kontonummer.
Die Klasse soll Methoden `deposit` zum Einzahlen und `withdrawal` zum Abheben besitzen.
Auskünfte über das Bankkonto können mit Hilfe der Eigenschaften `getNumber` (Kontonummer)
und `getBalance` (Kontostand) eingeholt werden.

Für Überweisungen von einem Konto auf ein anderes gibt es die Methode `transfer`.

*Hinweis*: 
Die Methode `transfer` lässt sich nur sinnvoll betrachten,
wenn wir ein Bankinstitut haben. Überlegen Sie sich trotzdem,
wie sich eine solche Methode realisieren ließe.

---

# Schnittstellen und abstrakte Klassen

Überlegen Sie, wie eine Schnittstelle `IAccount` und eine abstrakte Basisklasse `Account`
in der Realisierung einfließen könnten.

---

Da das Abheben eines Betrags offensichtlich abhängig vom Kontotyp ist, bietet es sich an,
in der Klasse `Account` nur eine abstrakte Vorlage einer `withdrawal`-Methode festzulegen.
In speziellen Ausprägungen eines Bankkontos wie etwa einem Girokonto oder einem Sparbuch kann man festlegen,
inwieweit beispielsweise das Konto beim Abheben überzogen werden darf oder nicht.
Durch den Rückgabewert `bool` teilt die `withdrawal`-Methode mit, 
ob eine Abhebung erfolgreich war oder nicht.

## Girokonten und Sparbücher

Schreiben Sie drei weitere Klassen `CurrentAccount` (Girokonto), `StudentsAccount` (Konto ohne Überziehungsrahmen) und `DepositAccount` (Sparbuch), die Sie geeignet mit der Klasse `Account` in Beziehung setzen.
Die drei Klassen sollen folgende Eigenschaften aufweisen:

  * Klasse `CurrentAccount`</br>Ein Girokonto darf um ein Dispolimit überzogen werden,
    das bei der Kontoeröffnung festzulegen ist. Das Dispolimit ist als Eigenschaft der Klasse `CurrentAccount` zu realisieren
    und kann zu einem späteren Zeitpunkt auch angepasst werden.
    Der Einfachheit halber legen wir zu Grunde, dass für das Überziehen des Girokontos keine Zinsen zu entrichten sind.

  * Klasse `StudentsAccount`</br>Ein Konto für Schüler und Studenten verhält sich im Prinzip
    wie ein Girokonto. Der einzige Unterschied besteht darin, dass es keinen Überziehungsrahmen besitzt.

  * Klasse `DepositAccount`</br>Auf einem Sparkonto fallen für das eingezahlte Geld Zinsen an.
    Der Zinssatz des Sparkontos ist als Eigenschaft der Klasse `DepositAccount` darzustellen.
    Nach der Kontoeröffnung kann der Zinssatz nicht mehr geändert werden.
    Für die Gutschrift der Zinsen auf dem Sparkonto bedarf es einer zusätzlichen Methode `computeInterest`.
    Diese Methode besitzt als Parameter die Anzahl der Tage, für die die Zinsen gutzuschreiben sind.
    Die Zinsen sind nach der Formel

    <img src="Bankkonto_Zinssatz.png" width="350">

    zu berechnen.

---

Die Programmausgabe studieren Sie an folgenden Codefragmenten:

*Beispiel*:

```cpp
CurrentAccount ca(123456, 1000);
ca.deposit(100);
ca.withdraw(40);
std::cout << ca << std::endl;

StudentsAccount sa(343434);
sa.deposit(50);
sa.withdraw(25);
std::cout << sa << std::endl;

DepositAccount da(654321, 4.0);
da.deposit(200);
da.withdraw(120);
da.computeInterest(31);
std::cout << da << std::endl;
```

*Ausgabe*:

```cpp
Testing accounts:
CurrentAccount [Nr. 123456]:
   Balance=60;
   Limit=1000.

StudentsAccount [Nr. 343434]:
   Balance=25;

DepositAccount [Nr. 654321]:
   Balance=80.2718;
   InterestRate=4.
```
