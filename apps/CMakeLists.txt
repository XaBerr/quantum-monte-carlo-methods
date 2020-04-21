add_executable(
  "${PROJECT_NAME}App"
  example.cpp
)
target_link_libraries(
  "${PROJECT_NAME}App"
  ${PROJECT_NAME}
)