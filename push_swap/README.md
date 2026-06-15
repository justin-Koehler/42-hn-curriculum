# Architectural Blueprint: push_swap Masterclass

Diese 6-Dateien-Struktur reizt die Norminette-Grenzen (maximal 5 Funktionen pro Datei) optimal aus. Sie eliminiert redundanten Code durch universelle Operations-Wrapper und bündelt alle vom neuen PDF-Subjekt geforderten Metriken und Strategien.

---

## 1. main.c
### Die Ablaufsteuerung (2 von 5 Funktionen ausgelastet)
*   **check_flags**
    *   Prüft CLI-Argumente zeichenbasiert auf Hardware-Ebene.
    *   Aktiviert die Leistungsmessung im Instrumentierungs-Struct (--bench).
    *   Mappt die Sortierstrategie über ein direktes ID-System (1 bis 4).
*   **main**
    *   Zentraler Start- und Endpunkt des Programms mit Single-Exit-Garantie (return 0).
    *   Nullt das Benchmark-Struct via ft_bzero und filtert Steuerungs-Flags über einen Pointer-Vorschub (argv++).
    *   Delegiert die Ausführung sequenziell an Parser, Indexierung, Strategie-Gateway und Speicherbereinigung.

---

## 2. parser.c
### Die Validierungsschicht (3 von 5 Funktionen ausgelastet)
*   **has_duplicate**
    *   Prüft in einer komprimierten Schleife, ob ein konvertierter Wert bereits im Stack existiert.
*   **is_invalid_input**
    *   Validiert jeden String zeichenweise unter Nutzung von ft_isdigit aus der Libft.
    *   Überwacht das mathematische Wachstum eines 64-Bit-long, um 32-Bit-Integer-Overflows (INT_MAX/INT_MIN) abzufangen.
*   **init_program**
    *   Liest die verbleibenden CLI-Argumente linear bis zum Nullterminator ein.
    *   Erstellt die Heap-Allokationen für Stack A und bricht bei Fehlern sicher und leckfrei ab.

---

## 3. utils.c
### Die mathematischen Hilfsfunktionen (5 von 5 Funktionen ausgelastet)
*   **stack_size**
    *   Misst die exakte Länge einer verketteten Liste in einer Schleife ohne Rumpf.
*   **stack_add_back**
    *   Hängt eine neue Node ohne temporäre Hilfsvariablen direkt an das Ende der Liste an.
*   **free_stack**
    *   Befreit den belegten Heap-Speicher sequenziell und nullt den originalen Pointer automatisch.
*   **is_sorted**
    *   Prüft linear, ob die Werte im Stack von oben nach unten aufsteigend sortiert sind.
*   **compute_disorder**
    *   Subjekt-Pflichtmetrik: Berechnet den exakten Prozentsatz der Fehlstellungen (Mistakes / Total Pairs * 100).

---

## 4. operations.c
### Die mechanischen Grundzüge (5 von 5 Funktionen ausgelastet)
*   **swap**
    *   Tauscht die obersten zwei Elemente eines beliebigen Stacks über Pointer-Manipulation.
*   **push**
    *   Verschiebt die oberste Node eines Stacks an die Spitze eines anderen Stacks.
*   **rotate**
    *   Schiebt das oberste Element eines Stacks an die unterste Position.
*   **reverse_rotate**
    *   Schiebt das unterste Element eines Stacks an die oberste Position.
*   **normalize_indices**
    *   Koordinaten-Komprimierung: Ersetzt rohe Zahlen durch fortlaufende IDs von 0 bis N-1, um mathematische Sicherheit gegen Overflows bei der Sortierung zu garantieren.

---

## 5. instructions.c
### Die Befehlsgeber und Instrumentierung (5 von 5 Funktionen ausgelastet)
*   **exec_swap**
    *   Befehlsverteiler für sa, sb und den synchronen Doppelzug ss.
    *   Inkrementiert die spezifischen Register im t_bench-Struct und schreibt die Anweisung auf stdout.
*   **exec_push**
    *   Befehlsverteiler für pa und pb inklusive automatischer Statistik-Inkrementierung.
*   **exec_rotate**
    *   Befehlsverteiler für ra, rb und den synchronen Doppelzug rr.
*   **exec_rev_rotate**
    *   Befehlsverteiler für rra, rrb und den synchronen Doppelzug rrr.
*   **print_bench_results**
    *   Subjekt-Pflichtausgabe: Schreibt die exakte Strichliste aller 11 Züge sowie die finale Disorder-Metrik formatiert ohne printf auf stderr.

---

## 6. sort.c
### Die algorithmischen Kerne (5 von 5 Funktionen ausgelastet)
*   **strategy_simple**
    *   Der O(n^2)-Algorithmus (Insertion Sort) für Kleinstmengen (kleiner oder gleich 3 Elemente).
*   **strategy_medium**
    *   Der O(n * sqrt(n))-Algorithmus. Teilt den Stack mathematisch exakt in die Quadratwurzel aus N Chunks auf.
*   **strategy_complex**
    *   Der O(n log n)-Algorithmus (Turk-Algorithmus unter Nutzung synchroner Züge) für Mengen bis 100/500 Elemente.
*   **strategy_adaptive**
    *   Subjekt-Pflichtstrategie: Liest vorab compute_disorder aus und wählt basierend auf der Unordnung dynamisch den besten mathematischen Kern.
*   **execute_strategy**
    *   Zentrales Gateway für die main.c, welches den vom CLI-Flag erzwungenen oder vom System gewählten Modus zündet.
