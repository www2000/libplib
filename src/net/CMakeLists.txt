
set(SOURCES 
    netBuffer.cxx
    netChannel.cxx
    netChat.cxx
    netMessage.cxx
    netMonitor.cxx
    netSocket.cxx
    )

set(HEADERS
    netBuffer.h
    netChannel.h
    netChat.h
    netMessage.h
    netMonitor.h
    netSocket.h
    net.h
    )

add_library(plibnet STATIC ${SOURCES})

install(TARGETS plibnet ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${HEADERS} DESTINATION include/plib/)
