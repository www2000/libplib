
set(SOURCES 
    pu.cxx
    puArrowButton.cxx
    puBox.cxx
    puButton.cxx
    puButtonBox.cxx
    puDial.cxx
    puDialogBox.cxx
    puFont.cxx
    puFrame.cxx
    puGroup.cxx
    puInput.cxx
    puInputBase.cxx
    puInterface.cxx
    puListBox.cxx
    puMenuBar.cxx
    puObject.cxx
    puOneShot.cxx
    puPopup.cxx
    puPopupMenu.cxx
    puRange.cxx
    puSlider.cxx
    puText.cxx
    puValue.cxx
    )

set(HEADERS
    pu.h
    puGLUT.h
    puFLTK.h
    puSDL.h
    puNative.h
    puPW.h
    )

add_library(plibpu STATIC ${SOURCES})

install(TARGETS plibpu ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${HEADERS} DESTINATION include/plib/)
