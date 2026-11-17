# Projects Settings
cmake_minimum_required(VERSION 4.2)
project(sald-breakout)

# `cmake --install` goes to release/ unless a prefix is given (--prefix <dir>)
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/release" CACHE PATH "Install directory" FORCE)
endif()

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
    src/main.cpp
    src/BallObject.cpp
    src/BreakoutApp.cpp
    src/GameLayer.cpp
    src/GameLevel.cpp
    src/GameObject.cpp
)

add_subdirectory(vendor/sald)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_link_libraries(${PROJECT_NAME} PRIVATE sald)

# The game loads its assets relative to the working directory:
# copy them next to the executable so it can be run straight from the build tree
foreach(ASSET_DIR Shaders Textures Levels)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
            ${CMAKE_CURRENT_SOURCE_DIR}/src/${ASSET_DIR}
            $<TARGET_FILE_DIR:${PROJECT_NAME}>/${ASSET_DIR}
    )
endforeach()

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

install(TARGETS ${PROJECT_NAME}
    DESTINATION .
)

install(DIRECTORY src/Shaders src/Textures src/Levels
    DESTINATION .
)
