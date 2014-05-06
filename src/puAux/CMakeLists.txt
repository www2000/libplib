
set(SOURCES 
    puAux.cxx
    puAuxBiSlider.cxx
    puAuxBiSliderWithEnds.cxx
    puAuxChooser.cxx
    puAuxComboBox.cxx
    puAuxCompass.cxx
    puAuxFileSelector.cxx
    puAuxLargeInput.cxx
    puAuxList.cxx
    puAuxScrollBar.cxx
    puAuxSelectBox.cxx
    puAuxSliderWithInput.cxx
    puAuxSpinBox.cxx
    puAuxTriSlider.cxx
    puAuxVerticalMenu.cxx
    )

set(HEADERS puAux.h)

add_library(plibpuaux STATIC ${SOURCES})

install(TARGETS plibpuaux ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${HEADERS} DESTINATION include/plib/)
