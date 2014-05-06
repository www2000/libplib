
set(SOURCES 
    sg.cxx
    sgd.cxx
    sgdIsect.cxx
    sgIsect.cxx
    sgPerlinNoise.cxx
    )

set(HEADERS sg.h)

add_library(plibsg STATIC ${SOURCES})

install(TARGETS plibsg ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${HEADERS} DESTINATION include/plib/)
