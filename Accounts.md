# Beispiel "Bankkonten"

Erstellen Sie eine Klasse `Account`, die das Guthaben eines Kontos verwaltet.
Zum Anlegen eines Kontos ben�tigt man (zur Vereinfachung der Aufgabenstellung) nur eine Kontonummer.
Die Klasse soll Methoden `deposit` zum Einzahlen und `withdrawal` zum Abheben besitzen.
Ausk�nfte �ber das Bankkonto k�nnen mit Hilfe der Eigenschaften `getNumber` (Kontonummer)
und `getBalance` (Kontostand) eingeholt werden.

F�r �berweisungen von einem Konto auf ein anderes gibt es die Methode `transfer`.

*Hinweis*: 
Die Methode `transfer` l�sst sich nur sinnvoll betrachten,
wenn wir ein Bankinstitut haben. �berlegen Sie sich trotzdem,
wie sich eine solche Methode realisieren lie�e.

---

# Schnittstellen und abstrakte Klassen

�berlegen Sie, wie eine Schnittstelle `IAccount` und eine abstrakte Basisklasse `Account`
in der Realisierung einflie�en k�nnten.

---

Da das Abheben eines Betrags offensichtlich abh�ngig vom Kontotyp ist, bietet es sich an,
in der Klasse `Account` nur eine abstrakte Vorlage einer `withdrawal`-Methode festzulegen.
In speziellen Auspr�gungen eines Bankkontos wie etwa einem Girokonto oder einem Sparbuch kann man festlegen,
inwieweit beispielsweise das Konto beim Abheben �berzogen werden darf oder nicht.
Durch den R�ckgabewert `bool` teilt die `withdrawal`-Methode mit, 
ob eine Abhebung erfolgreich war oder nicht.

## Girokonten und Sparb�cher

Schreiben Sie drei weitere Klassen `CurrentAccount` (Girokonto), `StudentsAccount` (Konto ohne �berziehungsrahmen) und `DepositAccount` (Sparbuch), die Sie geeignet mit der Klasse `Account` in Beziehung setzen.
Die drei Klassen sollen folgende Eigenschaften aufweisen:

  * Klasse `CurrentAccount`</br>Ein Girokonto darf um ein Dispolimit �berzogen werden,
    das bei der Kontoer�ffnung festzulegen ist. Das Dispolimit ist als Eigenschaft der Klasse `CurrentAccount` zu realisieren
    und kann zu einem sp�teren Zeitpunkt auch angepasst werden.
    Der Einfachheit halber legen wir zu Grunde, dass f�r das �berziehen des Girokontos keine Zinsen zu entrichten sind.

  * Klasse `StudentsAccount`</br>Ein Konto f�r Sch�ler und Studenten verh�lt sich im Prinzip
    wie ein Girokonto. Der einzige Unterschied besteht darin, dass es keinen �berziehungsrahmen besitzt.

  * Klasse `DepositAccount`</br>Auf einem Sparkonto fallen f�r das eingezahlte Geld Zinsen an.
    Der Zinssatz des Sparkontos ist als Eigenschaft der Klasse `DepositAccount` darzustellen.
    Nach der Kontoer�ffnung kann der Zinssatz nicht mehr ge�ndert werden.
    F�r die Gutschrift der Zinsen auf dem Sparkonto bedarf es einer zus�tzlichen Methode `computeInterest`.
    Diese Methode besitzt als Parameter die Anzahl der Tage, f�r die die Zinsen gutzuschreiben sind.
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
