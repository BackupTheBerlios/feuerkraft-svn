//  $Id: GameWorld.hxx,v 1.1 2001/12/12 00:00:32 grumbel Exp $
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

#ifndef GAMEWORLD_HH
#define GAMEWORLD_HH

#include <list>
#include "boost/smart_ptr.hpp"
#include "GameObj.hxx"
#include "View.hxx"

class View;
class GameObj;

class GameWorld
{
private:
  std::list<boost::shared_ptr<GameObj> > objects;
  
public:
  typedef std::list<boost::shared_ptr<GameObj> >::iterator ObjIter;

  GameWorld ();
  ~GameWorld ();
  
  /// Return a reference to the objects in the world
  std::list<boost::shared_ptr<GameObj> >& get_objects () { return objects; }
  void add (boost::shared_ptr<GameObj>);
  void add (GameObj*);

  void draw (View* view);
  void update (float delta);
};

#endif

/* EOF */