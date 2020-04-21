include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.9.1
)
FetchContent_MakeAvailable(catch2)
file(GLOB autopilot_sources "algorithms/**.cpp" "lib/**.cpp" "models/**.cpp")
SET(autopilot ${autopilot_sources})
add_executable(
  "${PROJECT_NAME}Test"
  test.cpp
  ${autopilot}
)
target_link_libraries(
  "${PROJECT_NAME}Test"
  PRIVATE
  ${PROJECT_NAME}
  Catch2::Catch2
)