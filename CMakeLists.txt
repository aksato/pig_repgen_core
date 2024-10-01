cmake_minimum_required(VERSION 3.15)
project(pig_repgen LANGUAGES CXX)

# Find required dependencies
find_package(inja CONFIG REQUIRED)
find_package(SQLiteCpp CONFIG REQUIRED)


# Add the pig_repgen_core library
add_library(pig_repgen_core STATIC
    db.cpp
    repgen/repgen.cpp
)

# Link libraries to pig_repgen_core
target_link_libraries(pig_repgen_core PRIVATE pantor::inja SQLiteCpp)
target_compile_features(pig_repgen_core PRIVATE cxx_std_17)

# Add the executable
add_executable(pig_repgen main.cpp)

# Link the core library with the executable
target_link_libraries(pig_repgen PRIVATE pig_repgen_core)
target_compile_features(pig_repgen PRIVATE cxx_std_17)

# Config install directory
set(INSTALL_DIR "$<CONFIG>")

# Install headers
install(FILES db.h DESTINATION "${CMAKE_INSTALL_PREFIX}/${INSTALL_DIR}/include")
install(FILES repgen/repgen.h DESTINATION "${CMAKE_INSTALL_PREFIX}/${INSTALL_DIR}/include/repgen")

# Install the executable
install(TARGETS pig_repgen_core DESTINATION "${CMAKE_INSTALL_PREFIX}/${INSTALL_DIR}/lib")
