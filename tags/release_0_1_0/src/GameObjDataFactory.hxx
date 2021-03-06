//  $Id: GameObjDataFactory.hxx,v 1.1 2002/03/23 19:52:19 grumbel Exp $
// 
//  Pingus - A free Lemmings clone
//  Copyright (C) 2000 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
// 
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef GAMEOBJDATAFACTORY_HXX
#define GAMEOBJDATAFACTORY_HXX

#include <guile/gh.h>

class GameObjDataFactory
{
private:

public:
  /** Create a GameObjData out of a symbol and a data, 
      FIXME: Abstractfactory stuff could be usefull here, but might
      FIXME: not be extremly important
      This function might return NULL on error! (no exceptions at the moment)
  */
  static GameObjData* create (SCM symbol, SCM data);
};

#endif

/* EOF */
