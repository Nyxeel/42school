1. Command not found (ohne Slash, PATH normal)

[ ] noch nicht erledigt
[x] erledigt
# pipex
./pipex infile "cat" "greep" outfile
echo $?

# bash
< infile cat | greep > outfile
echo $?


Erwartung:
stderr → greep: command not found
Exitcode → 127


###### #################################################
2. PATH leer/unsetzbar

[] noch nicht erledigt || bash gibt exit code 0 aus und schreibt echo hello in outfile, wie wenn command PATH weg ?
[X] erledigt
# pipex
env -i ./pipex infile "cat" "echo hi" outfile
echo $?

# bash
env -i < infile cat | echo hi > outfile
echo $?


Erwartung:
stderr → echo: command not found
Exitcode → 127


###### #################################################
3. Absoluter Pfad existiert nicht
[ ] noch nicht erledigt
[X] erledigt
# pipex
./pipex infile "cat" "/bin/doesnotexist" outfile
echo $?

# bash
< infile cat | /bin/doesnotexist > outfile
echo $?


Erwartung:
stderr → /bin/doesnotexist: No such file or directory
Exitcode → 127


###### #################################################
4. Is a directory (EISDIR)
[] noch nicht erledigt
[X] erledigt
# pipex
./pipex infile "cat" "/bin" outfile
echo $?

# bash
< infile cat | /bin > outfile
echo $?

# bash exit code = 0, und echo hi landet im outfile.
# 👉 Das ist korrektes Bash-Verhalten, weil:
# echo ist in bash ein builtin.
# Builtins brauchen keinen $PATH, d. h. auch wenn die PATH-Variable komplett fehlt, kennt bash noch ihre eingebauten Befehle.
# Deshalb läuft echo hi trotzdem, Exitcode = 0.

Erwartung:
stderr → /bin: Is a directory
Exitcode → 126



###### #################################################
5. Not a directory (ENOTDIR)
[] noch nicht erledigt
[X] erledigt
# Vorbereitung
printf "dummy" > /tmp/nodir

# pipex
./pipex infile "cat" "/tmp/nodir/ls" outfile
echo $?

# bash
< infile cat | /tmp/nodir/ls > outfile
echo $?


Erwartung:
stderr → /tmp/nodir/ls: Not a directory
Exitcode → 126


###### #################################################
6. Permission denied (kein x-Bit)
[] noch nicht erledigt
[X] erledigt
# Vorbereitung
printf '#!/bin/sh\necho HI\n' > ./myscript
chmod 644 ./myscript

# pipex
./pipex infile "cat" "./myscript" outfile
echo $?

# bash
< infile cat | ./myscript > outfile
echo $?


Erwartung:
stderr → ./myscript: Permission denied
Exitcode → 126


###### #################################################
7. Exec format error (ENOEXEC)
[] noch nicht erledigt | bash gibt keinen execformat error aus und exitstatus ist 0!
[X] erledigt
# Vorbereitung
: > ./empty
chmod 755 ./empty

# pipex
./pipex infile "cat" "./empty" outfile
echo $?

# bash
< infile cat | ./empty > outfile
echo $?



# bash → kein Fehlertext, exit code = 0.

# 👉 Erklärung:

# Der Kernel meldet tatsächlich ENOEXEC (Exec format error), wenn du eine leere Datei oder eine Datei ohne gültigen Header startest.

# bash fängt diesen Fehler ab: wenn execve mit ENOEXEC fehlschlägt, probiert bash automatisch, die Datei mit /bin/sh zu interpretieren.

# Bei einer komplett leeren Datei macht sh einfach nichts und beendet sich mit Exitcode 0.

# Wichtig für pipex:

# Du sollst nicht das Bash-internen Fallback (sh) implementieren.

# Dein pipex ruft direkt execve auf. Wenn der Kernel ENOEXEC zurückgibt:

# → "./empty: Exec format error"

# → Exitcode 126


Erwartung:
stderr → ./empty: Exec format error
Exitcode → 126


###### #################################################
8. Letztes Kommando liefert bewusst Fehlercode ≠ 0
[ ] noch nicht erledigt
[X] erledigt
# pipex
./pipex infile "cat" "grep ZZZ" outfile
echo $?

# bash
< infile cat | grep ZZZ > outfile
echo $?

Erwartung:
Exitcode → 1 (grep findet nichts)



##### ###################################################
9. infile fehlt (Open-Fehler, Pipeline startet nicht)

[X] noch nicht erledigt | bash gibt exitcode 0 aus, warum muss ich 1 ausgeben ?
[ ] erledigt

Setup: rm -f infile ; : > outfile
pipex: ./pipex infile "cat" "wc -c" outfile ; echo $?
bash: < infile cat | wc -c > outfile ; echo $?
pipex-stderr: infile: No such file or directory
pipex-Exit: 1
Erwartung: outfile unverändert/leer.


###### ###################################################
3) outfile ist ein Verzeichnis (Redirection-Fehler)

[ ] noch nicht erledigt
[X] erledigt

Setup: printf "x" > infile ; mkdir -p outdir
pipex: ./pipex infile "cat" "wc -c" outdir ; echo $?
bash: < infile cat | wc -c > outdir ; echo $?
pipex-stderr: outdir: Is a directory
pipex-Exit: 1



###### ###################################################
cmd not found (ohne Slash, PATH normal) am Ende

[ ] noch nicht erledigt
[X] erledigt

Setup: printf "hello\n" > infile ; : > outfile
pipex: ./pipex infile "cat" "greep 1" outfile ; echo $?
bash: < infile cat | greep 1 > outfile ; echo $?
pipex-stderr: greep: command not found
pipex-Exit: 127
Erwartung: outfile leer.

###### ###################################################

Absoluter Pfad existiert nicht am Ende

[ ] noch nicht erledigt
[X] erledigt

Setup: printf "x" > infile ; : > outfile
pipex: ./pipex infile "cat" "/bin/doesnotexist" outfile ; echo $?
bash: < infile cat | /bin/doesnotexist > outfile ; echo $?
pipex-stderr: /bin/doesnotexist: No such file or directory
pipex-Exit: 127
Erwartung: outfile leer.

###### ###################################################

outfile ohne Schreibrecht (Redirection-Fehler)

[ ] noch nicht erledigt
[X] erledigt

Setup: printf "x\n" > infile ; : > outfile ; chmod 400 outfile
pipex: ./pipex infile "cat" "wc -l" outfile ; echo $?
bash: < infile cat | wc -l > outfile ; echo $?
pipex-stderr: outfile: Permission denied
pipex-Exit: 1


###### ###################################################

Großer Input (Stabilität)

[ ] noch nicht erledigt
[X] erledigt

Setup: yes "abc" | head -n 50000 > infile ; : > outfile
pipex: ./pipex infile "grep abc" "wc -l" outfile ; echo $?
bash: < infile grep abc | wc -l > outfile ; echo $?
pipex-stderr: (leer)
pipex-Exit: 0
Check: 50000 outfile (Zahl muss passen).

###### ###################################################
