
set(SOURCES 
    ul.cxx
    ulClock.cxx
    ulError.cxx
    ulLinkedList.cxx
    ulList.cxx
    ulRTTI.cxx
    )

set(HEADERS
    ul.h
    ulRTTI.h
    )

add_library(plibul STATIC ${SOURCES})

install(TARGETS plibul ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${HEADERS} DESTINATION include/plib/)
