/*
     This file is part of TTT3D - Steve's 3D TicTacToe Player.
     Copyright (C) 2001  Steve Baker

     TTT3D is free software; you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation; either version 2 of the License, or
     (at your option) any later version.

     TTT3D is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.

     You should have received a copy of the GNU General Public License
     along with TTT3D; if not, write to the Free Software
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

     For further information visit http://plib.sourceforge.net

     $Id: material.cxx 1465 2002-08-30 14:05:59Z wolfram_kuss $
*/


#include "p3d.h"

ssgSimpleState *default_gst, *O_gst, *X_gst, *ground_gst, *ctrls_gst ;

static Material gs_setup [] =
{
  /*    gst          texture_map       clamp, trans,aref,light,frctn,0 */
  { &default_gst, "",                  FALSE, TRUE , 0.0f, FALSE, 1.0, 0 },
  { & ground_gst, "images/ground.rgb", FALSE, FALSE, 0.2f, FALSE, 1.0, 0 },
  { & ctrls_gst, "images/controls.rgb",FALSE, TRUE , 0.2f, FALSE, 1.0, 0 },
  { &      X_gst, "images/X.rgb"     , FALSE, FALSE, 0.2f, TRUE , 1.0, 0 },
  { &      O_gst, "images/O.rgb"     , FALSE, FALSE, 0.2f, TRUE , 1.0, 0 },
  { NULL, "", FALSE, FALSE, 0.0, FALSE, 1.0, 0 }
} ;


void Material::install ( int index )
{
  *gst = new ssgSimpleState ;

  (*gst) -> ref () ;
  (*gst) -> setExternalPropertyIndex ( index ) ;

  if ( texture_map [ 0 ] != '\0' )
  {
    (*gst) -> setTexture ( texture_map, !clamp_tex, !clamp_tex ) ;
    (*gst) -> enable ( GL_TEXTURE_2D ) ;
  }
  else
    (*gst) -> disable ( GL_TEXTURE_2D ) ;

  if ( lighting )
    (*gst) -> enable ( GL_LIGHTING ) ;
  else
    (*gst) -> disable ( GL_LIGHTING ) ;

  (*gst) -> setShadeModel ( GL_SMOOTH ) ;
  (*gst) -> disable ( GL_COLOR_MATERIAL ) ;
  (*gst) -> enable ( GL_CULL_FACE      ) ;
  (*gst) -> setColourMaterial ( GL_AMBIENT_AND_DIFFUSE ) ;
  (*gst) -> setMaterial ( GL_AMBIENT, 0.3f, 0.3f, 0.3f, 1 ) ;
  (*gst) -> setMaterial ( GL_DIFFUSE, 1, 1, 1, 1 ) ;
  (*gst) -> setMaterial ( GL_EMISSION, 0, 0, 0, 1 ) ;
  (*gst) -> setMaterial ( GL_SPECULAR, 0, 0, 0, 1 ) ;
  (*gst) -> setShininess ( 0 ) ;

  if ( transparency )
  {
    (*gst) -> setTranslucent () ;
    (*gst) -> enable ( GL_ALPHA_TEST ) ;
    (*gst) -> setAlphaClamp ( alpha_ref ) ;
    (*gst) -> enable ( GL_BLEND ) ;
  }
  else
  {
    (*gst) -> setOpaque () ;
    (*gst) -> disable ( GL_BLEND ) ;
  }
}



static ssgState *getAppState ( char *fname )
{
  if ( fname == NULL || fname[0] == '\0' )
    return gs_setup [ 0 ] . getState() ;

  char *fn ;

  /* Remove all leading path information. */

  for ( fn = & fname [ strlen ( fname ) - 1 ] ; fn != fname &&
                                               *fn != '/' ; fn-- )
    /* Search back for a '/' */ ;

  if ( *fn == '/' )
    fn++ ;

  char basename [ 1024 ] ;

  strcpy ( basename, fn ) ;

  /* Remove last trailing extension. */

  for ( fn = & basename [ strlen ( basename ) - 1 ] ; fn != basename &&
                                                     *fn != '.' ; fn-- )
    /* Search back for a '.' */ ;

  if ( *fn == '.' )
    *fn = '\0' ;

  for ( int i = 0 ; ! gs_setup [ i ] . isNull () ; i++ )
  {
    char *fname2 = gs_setup [ i ] . getTexFname () ;

    if ( fname2 != NULL && fname2[0] != '\0' )
    {
      char *fn2 ;

      /* Remove all leading path information. */

      for ( fn2 = & fname2 [ strlen ( fname2 ) -1 ] ; fn2 != fname2 &&
                                                     *fn2 != '/' ; fn2-- )
        /* Search back for a '/' */ ;

      if ( *fn2 == '/' )
        fn2++ ;

      char basename2 [ 1024 ] ;

      strcpy ( basename2, fn2 ) ;

      /* Remove last trailing extension. */

      for ( fn2 = & basename2 [ strlen ( basename2 ) - 1 ] ; fn2 != basename2 &&
                                                         *fn2 != '.' ; fn2-- )
        /* Search back for a '.' */ ;

      if ( *fn2 == '.' )
        *fn2 = '\0' ;

      if ( strcmp ( basename, basename2 ) == 0 )
        return gs_setup [ i ] . getState() ;
    }
  }

  return NULL ;
}



void initMaterials ()
{
  for ( int i = 0 ; ! gs_setup [ i ] . isNull () ; i++ )
    gs_setup [ i ] . install ( i ) ;

  ssgSetAppStateCallback ( getAppState ) ;
}


/*Material *getMaterial ( ssgState *s )
{
  return & ( gs_setup [ s -> getExternalPropertyIndex () ] ) ;
}


Material *getMaterial ( ssgLeaf *l )
{
  return getMaterial ( l -> getState () ) ;
}*/

