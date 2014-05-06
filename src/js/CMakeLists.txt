
set(SOURCES 
    js.cxx
    jsBSD.cxx
    jsLinux.cxx
    jsLinuxOld.cxx
    jsMacOS.cxx
    jsMacOSX.cxx
    jsNone.cxx
    jsWindows.cxx
    )

set(HEADERS js.h)

add_library(plibjs STATIC ${SOURCES})

install(TARGETS plibjs ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${HEADERS} DESTINATION include/plib/)
