1. push (Oberstes Element von einer Liste auf die andere)

Schritte:
--Merke dir das erste Element (head) von Liste 1.
--Setze den head-Pointer von Liste 1 auf das zweite Element.
--Das gemerkte Element zeigt jetzt mit next auf das erste Element der Liste 2.
--Setze den head-Pointer von Liste 2 auf dieses gemerkte Element.

BILDLICH:
Das erste Element „springt“ von Liste 1 an die Spitze von Liste 2.



2. swap (Tauscht die beiden obersten Elemente einer Liste)

Schritte:
--Merke dir das erste Element (head) und das zweite Element.
--Das erste Element zeigt jetzt mit next auf das Element nach dem zweiten.
--Das zweite Element zeigt mit next auf das erste Element.
--Setze den head-Pointer der Liste auf das zweite Element.

BILDLICH:
Die beiden obersten Elemente tauschen einfach die Plätze.
(Aus [A] → [B] → ... wird [B] → [A] → ...)



3. rotate (Oberstes Element nach unten)

Schritte:
--Merke dir das erste Element (head).
--Setze den head-Pointer auf das zweite Element.
--Gehe bis ans Ende der Liste.
--Hänge das ursprünglich erste Element ans Ende der Liste.
--Setze das next-Feld des ursprünglichen Elements auf NULL.

BILDLICH:
--Das erste Element „läuft“ ans Ende, alle anderen rutschen nach oben.



4. reverse rotate (Unterstes Element nach oben)

Schritte:
--Gehe durch die Liste, bis du das vorletzte Element findest.
--Das letzte Element wird zum neuen head-Pointer.
--Das vorletzte Element zeigt jetzt mit next auf NULL.
--Das neue head zeigt mit next auf das ehemalige erste Element.

BILDLICH:
Das letzte Element „schwimmt nach oben“ an die Spitze der Liste,
und der Rest rutscht eine Position runter.


Kurzmerkzettel:
Befehl	Schritt für Schritt

push	
1. Erstes Element von Liste 1 merken → 2. Kopf von Liste 1 auf das nächste setzen → 3. Gemerktes Element mit next auf Liste 2 zeigen lassen → 4. Kopf von Liste 2 auf dieses Element setzen.

swap	1. Kopf und zweites Element merken → 2. Kopf zeigt auf Element nach dem zweiten → 3. Zweites Element zeigt auf Kopf → 4. Kopf auf das zweite setzen.

rotate	1. Erstes Element merken → 2. Kopf auf das zweite setzen → 3. Am Ende der Liste das gemerkte erste Element anhängen → 4. next des gemerkten auf NULL setzen.

reverse rotate	1. Vorletztes und letztes Element finden → 2. Vorletztes zeigt auf NULL → 3. Letztes wird Kopf → 4. Letztes zeigt auf das alte Kopf-Element.



5. Doppel-Swap (ss)
Führt gleichzeitig sa (swap auf Stack A) und sb (swap auf Stack B) aus.
Beide Stacks tauschen ihre ersten beiden Elemente – gleichzeitig, mit nur einem Befehl.

6. Doppel-Rotate (rr)
Führt gleichzeitig ra (rotate auf Stack A) und rb (rotate auf Stack B) aus.
In beiden Stacks rutscht das oberste Element nach unten.

7. Doppel-Reverse Rotate (rrr)
Führt gleichzeitig rra (reverse rotate auf Stack A) und rrb (reverse rotate auf Stack B) aus.
In beiden Stacks rutscht das unterste Element nach oben.