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

     $Id: load_save.h 1425 2002-08-17 23:58:38Z ude $
*/


void   loadCB ( puObject * ) ;
void scloadCB ( puObject * ) ;
void bnloadCB ( puObject * ) ;
void bnsaveCB ( puObject * ) ;
void twsaveCB ( puObject * ) ;

void loadFile      ( char *fname, int interactive ) ;
void loadBoneFile  ( char *fname, int interactive ) ;
void saveTweenFile ( char *fname, int interactive ) ;

void setTweenInterval ( float t ) ;

