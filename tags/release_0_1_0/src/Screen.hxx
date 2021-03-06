//  $Id: Screen.hxx,v 1.1 2001/12/12 00:00:33 grumbel Exp $
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

#ifndef SCREEN_HH
#define SCREEN_HH

#include <list>
#include "boost/smart_ptr.hpp"
#include "boost/dummy_ptr.hpp"
#include "GuiObj.hxx"

/** A screen is a collection of gui objects, it basically represents a
    complete screen. */
class Screen
  : public GuiObj
{
private:
  std::list<boost::shared_ptr<GuiObj> > gui_objs;
  typedef std::list<boost::shared_ptr<GuiObj> >::iterator GuiObjIter;
  
public:
  Screen ();
  virtual ~Screen ();

  virtual void draw ();
  virtual void update (float delta);
  virtual void add (boost::shared_ptr<GuiObj> obj);
};

#endif

/* EOF */
