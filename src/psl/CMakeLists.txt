
set(SOURCES 
    psl.cxx
    pslCodeGen.cxx
    pslCompiler.cxx
    pslContext.cxx
    pslDump.cxx
    pslError.cxx
    pslExpression.cxx
    pslFileIO.cxx
    pslProgram.cxx
    pslSymbols.cxx
    pslToken.cxx
    )

set(HEADERS psl.h)

add_library(plibpsl STATIC ${SOURCES})

install(TARGETS plibpsl ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${HEADERS} DESTINATION include/plib/)
