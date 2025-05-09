✅ To-Do Liste für ft_printf

1. Grundgerüst vorbereiten

	Funktion ft_printf(const char *format, ...) anlegen

 	va_list args deklarieren

 	va_start(args, format) und va_end(args) korrekt verwenden

2. Formatstring analysieren

 	Formatstring format zeichenweise durchlaufen (while (*format))

 	Bei normalem Zeichen: direkt mit write() ausgeben

 	Bei %:

 	Nächstes Zeichen prüfen:

 	Gültiger Specifier? → Argument verarbeiten

 	%% → % direkt ausgeben

 	Ungültig? → % + Zeichen normal ausgeben

3. Hilfsfunktionen bauen

	is_valid_specifier(char c) → erkennt gültige Formatzeichen (cspdiuxX%)

 	ft_putchar_fd, ft_putstr_fd, ft_putnbr_fd (für direkte Ausgabe)

 	ft_strlen, falls nicht aus libft verwendet

4. va_arg() richtig benutzen

	Bei %c: va_arg(args, int)

 	Bei %s: va_arg(args, char *) (NULL checken!)

 	Bei %d / %i: va_arg(args, int)

 	Bei %u: va_arg(args, unsigned int)

 	Bei %x / %X: va_arg(args, unsigned int) + hex-Konvertierung

 	Bei %p: va_arg(args, void *) + als Adresse ausgeben

5. Temporäre Strings vermeiden / korrekt freigeben

	Bei itoa-ähnlichen Umwandlungen:

 	Entweder: mit malloc → dann sofort free()

 	Oder: char buf[20]-Puffer → eigene itoa_no_malloc() verwenden

 	Niemals write() mit strlen+1, sonst \0 mitausgegeben!

6. Fehlerfälle absichern

 	Unbekannte Formatzeichen → % + Zeichen direkt ausgeben

 	Argumente nicht übermäßig oft mit va_arg() abrufen (→ Zählen!)

 	Funktion, um gültige Argumente im Formatstring vorab zu zählen

	→ Damit du nicht versehentlich zu viele va_arg() machst

7. Bonus (optional)

 	va_copy einsetzen, wenn du Argumente mehrmals brauchst

 	Bonus-Specifier (-, +, 0, Breite etc.) vorbereiten

 	Rückgabewert von ft_printf: Anzahl der ausgegebenen Zeichen zählen
