cmake_minimum_required(VERSION 3.10)
project(TPComputacionII)

# Incluir todos los directorios necesarios
include_directories(lib src)

# Crear la biblioteca DataStructures
add_library(DataStructures INTERFACE)
target_include_directories(DataStructures INTERFACE lib)

# Componentes core (compartidos)
set(CORE_COMPONENTS Node)

# Estructuras principales
set(DATA_STRUCTURE_COMPONENTS LinkedList)

# Añadir componentes core
foreach(component ${CORE_COMPONENTS})
    target_sources(DataStructures INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/data_structures/core/${component}/${component}.h
        # lib/data_structures/core/${component}/${component}.tpp
    )
endforeach()

# Añadir estructuras de datos
foreach(structure ${DATA_STRUCTURE_COMPONENTS})
    target_sources(DataStructures INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/data_structures/${structure}/${structure}.h
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/data_structures/${structure}/${structure}.tpp
    )
endforeach()

# Programa principal
add_executable(tp_computacion_II main.cpp src/ObjetivoSeis.cpp)
target_link_libraries(tp_computacion_II DataStructures)