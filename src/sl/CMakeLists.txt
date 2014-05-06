
set(SOURCES_sl 
    slDSP.cxx
    slEnvelope.cxx
    slMODdacio.cxx
    slMODfile.cxx
    slMODinst.cxx
    slMODnote.cxx
    slMODPlayer.cxx
    slPlayer.cxx
    slSample.cxx
    slSamplePlayer.cxx
    slScheduler.cxx
    )

set(SOURCES_sm smMixer.cxx)

set(HEADERS
    sl.h
    slPortability.h
    sm.h
    )

add_library(plibsl STATIC ${SOURCES_sl})
add_library(plibsm STATIC ${SOURCES_sm})

install(TARGETS plibsl ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(TARGETS plibsm ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${HEADERS} DESTINATION include/plib/)
