SET( PROJECT calculator)
project( ${PROJECT} )

SET (HEADERS
	parserText.h
)

SET (SOURCE_ROOT ${${PROJECT}_SOURCE_DIR})

AUX_SOURCE_DIRECTORY(${SOURCE_ROOT} SOURCES)

include_directories(
	${SOURCE_ROOT}
)

add_executable (${PROJECT} ${HEADERS} ${SOURCES})
