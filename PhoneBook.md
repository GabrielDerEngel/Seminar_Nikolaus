# Beispiel "Phonebook"

Folgende Aspekte werden betrachtet:
  * Entwicklung einer Anwendung mit der STL (*Standard Template Library*)
  * Anwendung elementarer STL-Container (`std::vector`)
  * Anwendung elementarer STL Algorithmen (`std::find_if`, `std::copy_if`, `std::remove_if`, `std::sort`, `std::accumulate`, `std::for_each`)
  * Einsatz von Funktoren (*Callable Objects*)
  * Sortieren (`std::sort`)
  * Definition einer Schnittstelle (`IPhoneBook`)

*Weiterarbeit*:
In der vorliegenden Realisierung werden die Einträge des Telefonbuchs in einem `std::vector` abgelegt.
Überlegen Sie, ob diese Container-Klasse ideal für den vorliegenden Anwendungsfall ist.
Nehmen Sie eine zweite Realisierung vor, die auf einem `std::unordered_map`-Container fußt.

---
