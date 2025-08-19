#!/bin/bash

# EJERCICIO 1: Modelo del procesador
cat /proc/cpuinfo | grep "model name" | head -1

# EJERCICIO 2: Número de unidades de ejecución (cores)
cat /proc/cpuinfo | grep "cpu cores" | wc -l

# EJERCICIO 3: Lista de nombres de usuarios para red social de superhéroes
curl -s https://raw.githubusercontent.com/dariomalchiodi/superhero-datascience/master/content/data/heroes.csv | grep -v "Identity" | grep -v | cut -d ',' -f2 | tr '[:upper:]' '[:lower:]' | sed 's/ /_/g' > superheroes_usuarios.txt
curl -s https://raw.githubusercontent.com/dariomalchiodi/superhero-datascience/master/content/data/heroes.csv | cut -d',' -f2 | grep -v "Identity" | grep -v '^$' | tr '[:upper:]' '[:lower:]' | tr ' ' '_' > superheroes_usuarios.txt

# EJERCICIO 4A: Día de máxima temperatura en Córdoba
[su comando aquí]

# EJERCICIO 4B: Día de mínima temperatura en Córdoba
[su comando aquí]

# EJERCICIO 5: Ordenar jugadores de tenis por ranking
[su comando aquí]

# EJERCICIO 6: Ordenar tabla de Superliga por puntos y diferencia de goles
[su comando aquí]

# EJERCICIO 7: MAC address de la placa WiFi del equipo
[su comando aquí]

# EJERCICIO 8: Renombrar archivos de subtítulos
[su comando aquí]

# EJERCICIO 9A: Recortar video con ffmpeg
[su comando aquí]

# EJERCICIO 9B: Mezclar audio con ffmpeg
[su comando aquí]
