//  $Id: Background.hh,v 1.1 2001/05/05 22:16:28 grumbel Exp $
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

#ifndef BACKGROUND_HH
#define BACKGROUND_HH

#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include "GameObj.hh"

class Background 
  : public GameObj
{
private:
  CL_Surface sur;
  
public:
  Background (boost::dummy_ptr<GameWorld> w, const CL_Surface& sur);
  virtual ~Background () {}

  void draw (View* draw);
  void update (float delta) {}

  virtual int  get_z_pos () { return -10; }
};

#endif

/* EOF */
