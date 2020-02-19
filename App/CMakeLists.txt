cmake_minimum_required(VERSION 2.8.9)

#pistache library path
set ( LINK_LIBS_PISTACHE /usr/local/lib/libpistache.so )


#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "*.cpp")

add_executable (${PROJECT_NAME} ${SOURCES})


#target_link_libraries (helloDemo LINK_PUBLIC Hello)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC Threads::Threads ${LINK_LIBS_PISTACHE} restApi alarmService scheduler config deviceEvents deviceInfo deviceRegister device)