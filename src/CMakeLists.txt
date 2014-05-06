
include_directories(fnt js net psl puAux pui pw sg sl ssg ssgAux util)

if(ENABLE_FNT)
    add_subdirectory(fnt)
endif(ENABLE_FNT)

if(ENABLE_JS)
    add_subdirectory(js)
endif(ENABLE_JS)

if(ENABLE_NET)
    add_subdirectory(net)
endif(ENABLE_NET)

if(ENABLE_PSL)
    add_subdirectory(psl)
endif(ENABLE_PSL)

if(ENABLE_PUAUX)
    add_subdirectory(puAux)
endif(ENABLE_PUAUX)

if(ENABLE_PUI)
    add_subdirectory(pui)
endif(ENABLE_PUI)

if(ENABLE_PW)
    add_subdirectory(pw)
endif(ENABLE_PW)

if(ENABLE_SG)
    add_subdirectory(sg)
endif(ENABLE_SG)

if(ENABLE_SL)
    add_subdirectory(sl)
endif(ENABLE_SL)

if(ENABLE_SSG)
    add_subdirectory(ssg)
endif(ENABLE_SSG)

if(ENABLE_SSGAUX)
    add_subdirectory(ssgAux)
endif(ENABLE_SSGAUX)

if(ENABLE_UTIL)
    add_subdirectory(util)
endif(ENABLE_UTIL)

