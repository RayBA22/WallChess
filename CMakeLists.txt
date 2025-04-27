cmake_minimum_required(VERSION 3.10)
project(Echec)

# Recherche des paquets SFML nécessaires
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

# Ajouter les fichiers sources et en-têtes
file(GLOB SOURCE_FILES src/*.cpp)
file(GLOB HEADER_FILES src/*.h)

# Créer l'exécutable
add_executable(Echec ${SOURCE_FILES} ${HEADER_FILES})

# Définir les répertoires de sortie
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_OBJECT_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../obj)

# Lier les bibliothèques SFML à l'exécutable
target_link_libraries(Echec sfml-graphics sfml-window sfml-system sfml-audio)

# Inclure les répertoires d'en-têtes
target_include_directories(Echec PRIVATE src)
