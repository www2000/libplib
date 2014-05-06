
set(SOURCES 
    fnt.cxx
    fntBitmap.cxx
    fntTXF.cxx
    )

set(HEADERS fnt.h)

add_library(plibfnt STATIC ${SOURCES})

install(TARGETS plibfnt ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${HEADERS} DESTINATION include/plib/)
