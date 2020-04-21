file(
  GLOB
  HEADER_LISTCONFIGURE_DEPENDS
  "${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/*.h"
)
file(GLOB autopilot_sources "algorithms/**.cpp" "lib/**.cpp" "models/**.cpp")
SET(autopilot ${autopilot_sources})
add_library(
  ${PROJECT_NAME}
  ${autopilot}
)
target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
  ../include
)

