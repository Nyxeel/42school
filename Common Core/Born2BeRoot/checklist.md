# Born2BeRoot – Projektstruktur & Ziele

## 🏗️ Phase 1 – Fundament legen: Planung & Vorbereitung

**Ziel:** Überblick verschaffen, Tools bereitstellen

* [X] PDF-Dokument gründlich lesen
* [X] Entscheidung: **Debian** (empfohlen) oder **Rocky**?
* [X] Virtualisierungssoftware installieren: **VirtualBox** oder **UTM**
* [X] Notizen mit allen Konfigurationszielen anlegen
* [X] Snapshots vermeiden (verboten!)

---

## 🪠 Phase 2 – Betriebssystem installieren

**Ziel:** Minimalistische, CLI-basierte Linux-VM erstellen

* [X] Debian (oder Rocky) **ohne grafische Oberfläche** installieren
* [X] Zwei **verschlüsselte LVM-Partitionen** erstellen
* [X] **Hostname setzen**: deinLogin42
* [ ] **AppArmor** (Debian) oder **SELinux** (Rocky) aktivieren

---

## 🔐 Phase 3 – Sicherheitsstruktur einbauen

**Ziel:** Maschine absichern

* [ ] **UFW (Debian)** oder **firewalld (Rocky)** aktivieren

  * Nur **Port 4242** offen lassen
* [ ] **SSH auf Port 4242** aktivieren, **Root-Login verbieten**
* [ ] Benutzer mit eigenem Login erstellen

  * Gruppen: `sudo`, `user42`
* [ ] **sudo** sicher konfigurieren:

  * [ ] Max. 3 Fehlversuche
  * [ ] Eigene Fehlermeldung
  * [ ] Logging unter `/var/log/sudo/`
  * [ ] TTY-Modus aktivieren
  * [ ] PATH einschränken (z. B. `/usr/local/sbin:/usr/local/bin:...`)

---

## 🔑 Phase 4 – Passwortpolitik einrichten

**Ziel:** Sichere Passwörter erzwingen

* [ ] Ablauf nach **30 Tagen**
* [ ] Mindeständerungszeit: **2 Tage**
* [ ] **Warnung 7 Tage** vor Ablauf
* [ ] Mindestlänge: **10 Zeichen**

  * [ ] Groß-/Kleinbuchstaben, Zahl, keine 3 identischen Zeichen
  * [ ] Kein Benutzername im Passwort
* [ ] **Alle Passwörter** nach Setup ändern, inkl. Root

---

## 📋 Phase 5 – Monitoring-Skript

**Ziel:** Statusanzeige alle 10 Minuten über `wall`

* [ ] In Bash schreiben
* [ ] Anzeige:

  * Architektur, Kernelversion
  * phys./virtuelle CPUs
  * RAM und Speicher (% genutzt)
  * CPU-Auslastung
  * Letzter Reboot
  * LVM-Status
  * Aktive Verbindungen, Nutzeranzahl
  * IPv4- und MAC-Adresse
  * Sudo-Befehlzähler
* [ ] Muss über `cron` alle 10 Minuten laufen
* [ ] Fehlerfrei, unterbrechbar ohne Codeänderung

---

## 🔮 Phase 6 – Verteidigungs-Checkliste

**Ziel:** Alles vollständig verstanden und erklärbar

* [ ] Unterschiede zwischen `apt` und `aptitude`
* [ ] SSH, LVM, Firewall, sudo, Passwortpolitik, AppArmor/SELinux verstehen
* [ ] Monitoring-Skript erklären und beenden können

---
