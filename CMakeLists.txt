cmake_minimum_required(VERSION 3.10)
project(TPComputacionII)

# Incluir todos los directorios necesarios
include_directories(lib src)

# Crear la biblioteca data_structures
add_library(data_structures INTERFACE)
target_include_directories(data_structures INTERFACE lib)

# Componentes core (compartidos)
set(CORE_COMPONENTS Node)

# Estructuras principales
set(DATA_STRUCTURE_COMPONENTS LinkedList)

# Añadir componentes core
foreach(component ${CORE_COMPONENTS})
    target_sources(data_structures INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/data_structures/core/${component}/${component}.h
        # lib/data_structures/core/${component}/${component}.tpp
    )
endforeach()

# Añadir estructuras de datos
foreach(structure ${DATA_STRUCTURE_COMPONENTS})
    target_sources(data_structures INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/data_structures/${structure}/${structure}.h
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/data_structures/${structure}/${structure}.tpp
    )
endforeach()


# Agregar la biblioteca de algoritmos
add_library(algoritmos INTERFACE)
target_include_directories(algoritmos INTERFACE lib)
set(ALGORITHMS_COMPONENTS selection_sort)

# Añadir algoritmos
foreach(algorithm ${ALGORITHMS_COMPONENTS})
    target_sources(algoritmos INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/algoritmos/${algorithm}.h
    )
endforeach()

# Programa principal
add_executable(tp_computacion_II main.cpp src/objetivo_cinco.cpp src/objetivo_seis.cpp src/objetivo_siete.cpp)
target_link_libraries(tp_computacion_II data_structures algoritmos)