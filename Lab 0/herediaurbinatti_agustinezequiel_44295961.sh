#!/bin/bash

# EJERCICIO 1: Modelo del procesador
cat /proc/cpuinfo | grep "model name" | head -1

# EJERCICIO 2: Número de unidades de ejecución (cores)
cat /proc/cpuinfo | grep "cpu cores" | wc -l

# EJERCICIO 3: Lista de nombres de usuarios para red social de superhéroes
curl -s https://raw.githubusercontent.com/dariomalchiodi/superhero-datascience/master/content/data/heroes.csv | cut -d ';' -f2 | tr 'A-Z' 'a-z' | tr ' ' '_' | grep -v "Identity" | grep -v "^$" | sed '1d' > superheroes_usuarios.txt

# EJERCICIO 4A: Día de máxima temperatura en Córdoba
cat datos/weather_cordoba.in | sort -k5 -n -r | head -1 | awk '{print $1"-"$2"-"$3}'

# EJERCICIO 4B: Día de mínima temperatura en Córdoba
cat datos/weather_cordoba.in | sort -k6 -n | head -1 | awk '{print $1"-"$2"-"$3}'

# EJERCICIO 5: Ordenar jugadores de tenis por ranking
cat datos/atpplayers.in | sort -k3 -n 

# EJERCICIO 6: Ordenar tabla de Superliga por puntos y diferencia de goles
awk '{print $0, ($7-$8)}' datos/superliga.in | sort -k2,2nr -k9,9nr | cut -d' ' -f1-8

# EJERCICIO 7: MAC address de la placa WiFi del equipo
ip link show | grep -o -E '([0-9a-f]{2}:){5}[0-9a-f]{2}'

# EJERCICIO 8: Renombrar archivos de subtítulos
for f in serie_prueba/*_es.srt; do mv "$f" "${f%_es.srt}.srt"; done

# EJERCICIO 9A: Recortar video con ffmpeg
ffmpeg -ss 00:00:10 -i prueba1.mp4 -to 00:00:30 -c copy recorte_prueba1.mp4

# EJERCICIO 9B: Mezclar audio con ffmpeg
ffmpeg -i audio1.mp3 -i audio2.mp3 -filter_complex amix=inputs=2 output_audios.mp3