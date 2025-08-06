
Fensterverwaltung & Grundlegendes
mlx_init

„Stecker in die Steckdose“ – Initialisiert die Verbindung zur Grafik.

mlx_new_window

„Fenster aufmachen“ – Öffnet das Spielfenster mit gewünschter Breite, Höhe und Titel.

mlx_destroy_window

„Fenster wieder zumachen“ – Schließt das Spielfenster.

Bilder/Sprites laden und anzeigen
mlx_xpm_file_to_image

„Fotoalbum aufschlagen“ – Lädt eine .xpm-Datei als Bild, das du nutzen kannst.

mlx_put_image_to_window

„Bild aufhängen“ – Hängt ein Bild/Sprite an eine bestimmte Position im Fenster.

mlx_destroy_image

„Bild entsorgen“ – Gibt den Speicherplatz für das Bild wieder frei.

Pixelweise Zeichnen (meist für Bonus)
mlx_new_image

„Leinwand anlegen“ – Erzeugt ein komplett neues, leeres Bild (z.B. für eigenes Pixelzeichnen).

mlx_get_data_addr

„Stift holen“ – Gibt dir Zugriff auf die einzelnen Pixel der Leinwand.

mlx_put_image_to_window

Wie oben: Bringt deine Leinwand ins Fenster.

Events & Interaktion
mlx_hook

„Türklingel installieren“ – Reagiert auf bestimmte Ereignisse wie Tastendrücke, Mausklicks, etc.

mlx_key_hook

„Spezielle Türklingel für Tasten“ – Einfacher Weg, um auf Tastendrücke zu reagieren (z.B. für Bewegung).

mlx_mouse_hook

„Türklingel für die Maus“ – (Optional für Bonus)

mlx_loop

„Motor starten“ – Startet die Hauptschleife, damit alles am Laufen bleibt.

mlx_loop_hook

„Regelmäßiger Kontrollgang“ – Führt eine Funktion immer wieder aus (praktisch für Animationen).

Sonstiges
mlx_clear_window

„Tafel abwischen“ – Entfernt alles im Fenster (z.B. für das Neuzeichnen).

mlx_string_put

„Notiz aufhängen“ – Schreibt Text ins Fenster (nur für Bonus sinnvoll: Bewegungscounter anzeigen).

Wichtig!
Nicht jede Funktion musst du nutzen. Konzentriere dich auf das, was für dich Sinn macht:

Pflicht:
Fenster öffnen/schließen, Bild/Sprite laden & zeichnen, Tasteneingaben abfragen, Eventloop.

Bonus:
Animation (über loop_hook), Textanzeige (string_put), eigenes Pixelzeichnen.

