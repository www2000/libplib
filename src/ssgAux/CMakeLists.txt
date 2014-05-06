
set(SOURCES
    ssgAux.cxx
    ssgaShapes.cxx
    ssgaPatch.cxx
    ssgaParticleSystem.cxx
    ssgaWaveSystem.cxx
    ssgaLensFlare.cxx
    ssgaLensFlareTexture.cxx
    ssgaFire.cxx
    ssgaScreenDump.cxx
    ssgaSphere.cxx
    ssgaCelestialBody.cxx
    ssgaCloudLayer.cxx
    ssgaStars.cxx
    ssgaSkyDome.cxx
    ssgaSky.cxx
    ssgaTeapot.cxx
    ssgaBillboards.cxx
    )

set(HEADERS
    ssgAux.h
    ssgaShapes.h
    ssgaLensFlare.h
    ssgaParticleSystem.h
    ssgaWaveSystem.h
    ssgaScreenDump.h
    ssgaSky.h
    ssgaSphere.h
    ssgaFire.h
    ssgaBillboards.h
    )

add_library(plibssgaux STATIC ${SOURCES})

install(TARGETS plibssgaux ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${HEADERS} DESTINATION include/plib/)
