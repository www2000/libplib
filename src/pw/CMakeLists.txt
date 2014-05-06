
set(SOURCES 
    pw.cxx
    pwMacOSX.cxx
    pwWindows.cxx
    pwX11.cxx
    )

set(HEADERS pw.h)

add_library(plibpw STATIC ${SOURCES})

install(TARGETS plibpw ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${HEADERS} DESTINATION include/plib/)
