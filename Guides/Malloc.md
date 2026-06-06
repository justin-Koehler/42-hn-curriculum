# Memory Allocation (malloc & free)

`malloc` und `free` sind deine Werkzeuge für die ultimative Kontrolle über den RAM. Standardvariablen werden automatisch auf dem *Stack* erstellt und gelöscht. Mit `malloc` forderst du stattdessen Speicherplatz auf dem unbegrenzten *Heap* an, der so lange bestehen bleibt, bis du ihn eigenhändig wieder vernichtest.

---

### Die 3 Regeln

1. **Es fordert rohe Bytes.** `malloc` (Memory Allocation) reserviert einen zusammenhängenden Block im RAM. Du musst über `sizeof()` exakt berechnen, wie viele Bytes du für deine Daten brauchst.
2. **Es kann fehlschlagen.** Wenn der Arbeitsspeicher voll ist oder das System blockiert, gibt `malloc` eine Nulladresse (`NULL`) zurück. Du musst diesen Fall zwingend prüfen, bevor du auf den Speicher zugreifst.
3. **Du musst aufräumen.** Jeder einzelne Byte-Block, den du mit `malloc` öffnest, **muss** mit `free()` wieder freigegeben werden. Vergisst du das, entsteht ein Speicherleck (*Memory Leak*), das den RAM deines Computers schleichend auffrisst.

---

### Verwendung im Code

Die dynamische Speicherverwaltung folgt einer unumstößlichen Kette aus Anforderung, Prüfung und Freigabe:

```c
#include <stdlib.h> // Zwingend erforderlich für malloc und free
#include <unistd.h>

int main(void)
{
    char *str;

    // 1. Allocation: Reserviere Platz für 3 Chars (z.B. '4', '2', '\0')
    str = (char *)malloc(sizeof(char) * 3);

    // 2. Protection: Sofort prüfen, ob das System den Speicher freigegeben hat
    if (str == NULL)
        return (1);

    str[0] = '4';
    str[1] = '2';
    str[2] = '\0';
    write(1, str, 2);

    // 3. Free: Gib den Speicher wieder an das System zurück
    free(str);
    return (0); // Sauberes Ende. Kein Memory Leak.
}
```

---

### Warum es wichtig ist

Ohne `malloc` ist dein Programm starr. Du müsstest vor dem Kompilieren exakt wissen, wie groß ein String oder ein Array sein wird (z. B. `char str[100]`). Wenn der Benutzer dann Text mit 101 Zeichen eingibt, stürzt dein Programm ab. `malloc` macht deine Software dynamisch. Es erlaubt dir, dich zur Laufzeit exakt an die Datengröße anzupassen, die der Benutzer eingibt. Es ist das Fundament für komplexe Datenstrukturen wie verkettete Listen (*Linked Lists*) und professionelles Speichermanagement.

---

Möchtest du als Nächstes sehen, wie wir dieses Wissen nutzen, um ein echtes Piscine-Meisterwerk wie **`ft_strdup`** (einen String dynamisch kopieren) zu bauen, oder steht ein anderes **Spezialthema** an?
