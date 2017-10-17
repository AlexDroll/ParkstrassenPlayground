message(${PROJECT_SOURCE_DIR})

file(GLOB HEADERS "*.h")
file(GLOB SOURCES "*.cpp")



add_library(LibTools SHARED ${SOURCES} ${HEADERS})


set(LIBS ${LIBS})
TARGET_LINK_LIBRARIES(LibTools ${LIBS})
