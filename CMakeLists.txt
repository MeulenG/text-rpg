cmake_minimum_required(VERSION 3.28)

project(text-rpg)

add_executable(game)

target_sources(game
  PRIVATE
    src/state_machine.cpp
    src/game.cpp
    src/main.cpp
)