# Cub3D - README

## Stato attuale del progetto

- **Parsing file .cub:** In fase di sviluppo. Gestiamo texture, colori (floor/ceiling) e mappa.
- **Struttura:**
  - `main.c`: entry point
  - `includes/cub3d.h`: header principale
  - `libraries/`: contiene libft, ft_printf, mlx
  - `parsing/`: funzioni per il parsing del file .cub
  - `maps/`: file di esempio per la mappa
  - `utils/`: funzioni di utilità

## Flusso attuale del parsing

1. **Apertura file .cub**
2. **Lettura riga per riga**
   - Se la riga è vuota o solo `\n`, viene saltata
   - Se la riga è una texture, viene gestita da `parse_textures`
   - Se la riga è un colore (F/C), viene gestita da `parse_rgb`
   - Se la riga è parte della mappa, viene gestita separatamente (gli spazi NON vengono rimossi)
3. **Controlli di validità**
   - Verifica che tutte le texture e i colori siano stati settati
   - Verifica che la mappa sia presente e corretta (fase successiva)

## Come sarà il flusso a fine fase 1 (parsing)

- Il parsing sarà robusto:
  - Salta righe vuote
  - Gestisce correttamente texture e colori
  - Riconosce e salva la mappa senza alterare gli spazi
- Tutti i dati necessari saranno caricati in `t_game` e sottostrutture
- In caso di errore, il programma stampa un messaggio e termina

## Cosa manca per completare la fase 1

- Validazione completa della mappa (contorni, caratteri validi, player, ecc.)
- Gestione errori più dettagliata
- Test con file .cub "strani" (spazi, righe vuote, errori di sintassi)

---

**Obiettivo fase 1:** parsing affidabile e caricamento dati in memoria, pronto per la fase di rendering e gestione input.
