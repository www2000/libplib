if BUILD_SSG

noinst_PROGRAMS = load save

load_SOURCES = load.cxx
save_SOURCES = save.cxx

load_LDADD = -lplibssg -lplibsg -lplibul $(GLUT_LIBS) $(OGL_LIBS)
save_LDADD = -lplibssg -lplibsg -lplibul $(GLUT_LIBS) $(OGL_LIBS)

endif

EXTRA_DIST = load.dsp save.dsp

