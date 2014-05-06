/*
     This file is part of ExPoser - A Tool for Animating PLIB Critters.
     Copyright (C) 2001  Steve Baker

     ExPoser is free software; you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation; either version 2 of the License, or
     (at your option) any later version.

     ExPoser is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.

     You should have received a copy of the GNU General Public License
     along with ExPoser; if not, write to the Free Software
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

     For further information visit http://plib.sourceforge.net

     $Id: bones.cxx 2100 2006-11-03 22:31:54Z fayjf $
*/


#include "exposer.h"

static sgVec3          curr_translate = { 0.0f, 0.0f, 0.0f } ;

static ssgSimpleState *boneState      = NULL ;
static Bone           *bone           = NULL ;

ssgSimpleState *getBoneState ()     { return boneState ;        }
float          *getCurrTranslate () { return curr_translate ;   }
Bone           *getBone ( int i )   { return & ( bone [ i ] ) ; }


void init_bones ()
{
  if ( bone == NULL )
    bone = new Bone [ 1000 ] ;

  sgZeroVec3 ( curr_translate ) ;
}


Bone::Bone ()
{
  parent = -1 ;
}

 
void Bone::read ( FILE *fd )
{
  char name [ PUSTRING_MAX ] ;
  char shb, spb, srb ;
 
  fscanf ( fd, "BONE \"%s %c%c%c\n",
    name, & shb, & spb, & srb ) ;
 
  if ( name[strlen(name)-1] == '\"' )
    name[strlen(name)-1] = '\0' ;
 
  na -> setValue ( name ) ;
  hb -> setValue ( (shb == 'H') ? 0 : 1 ) ;
  pb -> setValue ( (spb == 'P') ? 0 : 1 ) ;
  rb -> setValue ( (srb == 'R') ? 0 : 1 ) ;

  hide_headingCB ( hb ) ;
  hide_pitchCB   ( pb ) ;
  hide_rollCB    ( rb ) ;
}
 
 
void Bone::write ( FILE *fd )
{
  fprintf ( fd, "BONE \"%s\" %c%c%c\n",
    na->getStringValue(),
    hb->getValue() ? '.' : 'H',
    pb->getValue() ? '.' : 'P',
    rb->getValue() ? '.' : 'R' ) ;
}


void Bone::setAngles ( float h, float p, float r )
{
  sgVec3  hpr ;
  sgSetVec3 ( hpr, h, p, r ) ;
  setAngles ( hpr ) ;
}


void Bone::setAngle ( int which, float a )
{
  getXForm() -> hpr [ which ] = a ;
  setAngles ( getXForm() -> hpr ) ;
}


void Bone::setAngles ( sgVec3 src )
{
  sgCopyVec3 ( getXForm() -> hpr, src ) ;
}


float *Bone::getDialAngles ()
{
  static sgVec3 dst ;
  dst[0] = sh -> getFloatValue () * 360.0f - 180.0f ;
  dst[1] = sp -> getFloatValue () * 360.0f - 180.0f ;
  dst[2] = sr -> getFloatValue () * 360.0f - 180.0f ;
  return dst ;
}


sgCoord *Bone::getXForm ( Event *prev, Event *next, float lerptime )
{
  static sgCoord c ;

  sgCoord *coord0 = prev->getBoneCoord ( id ) ;
  sgCoord *coord1 = next->getBoneCoord ( id ) ;

  sgCopyVec3 ( c.xyz, xlate ) ;

  sgLerpAnglesVec3 ( c.hpr, coord0->hpr, coord1->hpr, lerptime ) ;

  sh -> setValue ( (c.hpr[0] + 180.0f) / 360.0f ) ;
  sp -> setValue ( (c.hpr[1] + 180.0f) / 360.0f ) ;
  sr -> setValue ( (c.hpr[2] + 180.0f) / 360.0f ) ;

  return & c ;
}


sgCoord *Bone::getXForm ()
{
  if ( eventList->getCurrentEvent() != NULL )
  {
    sgCoord *coord = eventList->getCurrentEvent()->getBoneCoord ( id ) ;
    sgCopyVec3 ( coord->xyz, xlate ) ;
    return coord ;
  }

  static sgCoord coord ;
  sgZeroCoord ( & coord ) ;
  sgCopyVec3 ( coord.xyz, xlate ) ;
  return &coord ;
}


void Bone::computeTransform ( Event *prev, Event *next, float t )
{
  effector -> setTransform ( getXForm( prev, next, t ) ) ;
}


void Bone::transform ( sgVec3 dst, sgVec3 src )
{
  sgXformPnt3 ( dst, src, netMatrix ) ;
  sgAddVec3   ( dst, curr_translate ) ;
}


void Bone::swapEnds()
{
  sgVec3 tmp ;

  /* Swap vertices so that vx0 is always the root. */

  sgCopyVec3 ( tmp, vx[0] ) ;
  sgCopyVec3 ( vx[0], vx[1] ) ;
  sgCopyVec3 ( vx[1], tmp ) ;

  sgCopyVec3 ( tmp, orig_vx[0] ) ;
  sgCopyVec3 ( orig_vx[0], orig_vx[1] ) ;
  sgCopyVec3 ( orig_vx[1], tmp ) ;
}


void Bone::init ( ssgLeaf *l, sgMat4 newmat, short vv[2], int ident )
{
  parent = -1 ;
  sgCopyVec3  ( vx [ 0 ], l -> getVertex ( vv[0] ) ) ;
  sgCopyVec3  ( vx [ 1 ], l -> getVertex ( vv[1] ) ) ;
  sgXformPnt3 ( vx [ 0 ], newmat ) ;
  sgXformPnt3 ( vx [ 1 ], newmat ) ;

  sgCopyVec3 ( orig_vx [ 0 ], vx [ 0 ] ) ;
  sgCopyVec3 ( orig_vx [ 1 ], vx [ 1 ] ) ;

  id = ident ;
  if ( sgEqualVec3 ( vx [ 0 ], vx [ 1 ] ) )
    fprintf ( stderr, "exposer: Zero length bone found.\n" ) ;
}


void Bone::print ( FILE *fd, int which )
{
  fprintf ( fd, "Bone %d: vx  (%f,%f,%f) -> (%f,%f,%f)  Parent = %d\n",
             which, 
             vx[0][0],vx[0][1],vx[0][2],
             vx[1][0],vx[1][1],vx[1][2],
             parent ) ;
}


#define NUM_COLOURS 13

static sgVec4 colourTable [] =
{
  { 1, 0, 0, 0.3f }, { 0, 1, 0, 0.3f }, { 0, 0, 1, 0.3f },
  { 1, 1, 0, 0.3f }, { 1, 0, 1, 0.3f }, { 0, 1, 1, 0.3f },

  { 0.5f, 0.5f, 0.5f, 0.3f },

  { 1, 0.5f, 0.5f, 0.3f }, { 0.5f,  1  , 0.5f, 0.3f }, { 0.5f, 0.5f, 1, 0.3f },
  { 1,  1  , 0.5f, 0.3f }, {  1  , 0.5f,  1  , 0.3f }, { 0.5f, 1, 1, 0.3f } 
} ;


ssgBranch *Bone::generateGeometry ( int root )
{
  static int nextColIndex = 0 ;

  ssgTransform *b = new ssgTransform ;

  b -> setUserData ( this ) ;
  effector = b ;
  sgZeroVec3 ( getXForm()->hpr ) ;
  sgCopyVec3 ( xlate, vx[0] ) ;
  sgZeroVec3 ( vx[0] ) ;
  sgSubVec3  ( vx[1], xlate ) ;

  sgMat4 mat ;
  sgMakeCoordMat4 ( mat, getXForm() ) ;
  b -> setTransform ( mat ) ;

  offsetChildBones ( root, xlate ) ;

  sgCopyVec4 ( colour, colourTable[nextColIndex] ) ;

  createJoint () ;

  ssgaCube *shape = new ssgaCube () ;
  sgVec3 org ; sgCopyVec3  ( org, vx[1] ) ;
  sgVec3 siz ; sgCopyVec3  ( siz, vx[1] ) ;

  sgScaleVec3 ( org, 0.5 ) ;

  siz[0] = (float)fabs ( siz[0] ) ; if ( siz[0] <= 0.1f ) siz [ 0 ] = 0.1f ;
  siz[1] = (float)fabs ( siz[1] ) ; if ( siz[1] <= 0.1f ) siz [ 1 ] = 0.1f ;
  siz[2] = (float)fabs ( siz[2] ) ; if ( siz[2] <= 0.1f ) siz [ 2 ] = 0.1f ;

  if ( boneState == NULL )
  {
    boneState = new ssgSimpleState () ;
    boneState -> setColourMaterial ( GL_AMBIENT_AND_DIFFUSE ) ;
    boneState -> setMaterial ( GL_SPECULAR, 0, 0, 0, 1 ) ;
    boneState -> setMaterial ( GL_EMISSION, 0, 0, 0, 1 ) ;
    boneState -> enable ( GL_BLEND ) ;
  }

  shape -> setCenter ( org ) ;
  shape -> setSize   ( siz ) ;
  shape -> setColour ( colourTable[nextColIndex] ) ;
  shape -> setKidState ( boneState ) ;

  nextColIndex = ( nextColIndex + 1 ) % NUM_COLOURS ;

  b -> addKid ( shape ) ;

  for ( int i = 0 ; i < getNumBones() ; i++ )
    if ( i != root && getBone(i)->parent == root )
      b -> addKid ( getBone(i)->generateGeometry ( i ) ) ;

  return b ;
}


