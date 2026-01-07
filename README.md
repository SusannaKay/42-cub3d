# Cub3D - README

## Stato attuale del progetto

- **Parsing file .cub:** gestiamo texture, colori (floor/ceiling) e mappa; le righe vuote dentro la sezione mappa generano errore.
- **Validazioni:** `verify_map` controlla player unico e chiusura della mappa, ma lavora su righe di lunghezza variabile.
- **Setup grafico:** `init_game` aggancia MLX e crea una finestra 300x300; non esiste ancora un buffer di rendering né hook per input/uscita.
- **Struttura:**
  - `main.c`: entry point, avvia parsing e avvia `mlx_loop`
  - `includes/cub3d.h`: header principale
  - `libraries/`: contiene libft, ft_printf, mlx
  - `parsing/`: funzioni per il parsing del file .cub
  - `maps/`: file di esempio per la mappa
  - `utils/`: funzioni di utilità e cleanup

## Flusso attuale del parsing

1. **Apertura file .cub**
2. **Lettura riga per riga**
   - Se la riga è vuota o solo `\n`, viene saltata finché la mappa non è iniziata
   - Se la mappa è iniziata, una riga vuota provoca errore e termina il parsing
   - Se la riga è una texture, viene gestita da `parse_textures`
   - Se la riga è un colore (F/C), viene gestita da `parse_rgb`
   - Se la riga è parte della mappa, viene gestita separatamente (gli spazi NON vengono rimossi)
3. **Controlli di validità**
   - Verifica che tutte le texture e i colori siano stati settati
   - Verifica che la mappa sia presente e corretta (fase successiva)

## Cosa manca per completare la fase 1

- Normalizzare la mappa in una matrice rettangolare (width/height) prima dei controlli e blindare la chiusura gestendo spazi e bordi.
- Rendere sicuro il cleanup duplicando `argv[1]` (filename) e liberando solo risorse effettivamente allocate (no literal in `graphics->flags`).
- Test con file .cub "strani" (spazi, righe vuote, errori di sintassi)

---

**Obiettivo fase 1:** parsing affidabile e caricamento dati in memoria, pronto per la fase di rendering e gestione input.

## Prossimi passi per la fase 2 (setup grafica)

- Consolidare la configurazione MLX centralizzando dimensioni della finestra e gestendo correttamente failure path (messaggi + cleanup).
- Introdurre una struttura immagine (es. `t_img`) con buffer, `bpp`, `line_len`, `endian` e un helper per `mlx_new_image`/`mlx_get_data_addr`.
- Caricare le texture trovate in `graphics->paths` tramite `mlx_xpm_file_to_image`, salvando handler e dimensioni in `graphics->wall_img`.
- Implementare un convertitore `rgb_to_trgb` che trasformi i valori `floor/ceiling` in int32 e predisporre un `draw_background` che riempia l'immagine.
- Collegare un ciclo di rendering (`mlx_loop_hook`) e gli hook di input (`mlx_hook` per tasti/uscita) per poter gestire aggiornamenti e chiusura pulita.
- Completare il percorso di cleanup liberando immagini, texture, finestra e display MLX sia in uscita normale sia negli errori.
