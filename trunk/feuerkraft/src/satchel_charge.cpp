//  $Id: satchel_charge.cpp,v 1.2 2003/06/20 20:54:23 grumbel Exp $
//
//  Pingus - A free Lemmings clone
//  Copyright (C) 2002 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "view.hpp"
#include "alist.hpp"
#include "explosion.hpp"
#include "property_set.hpp"
#include "resource_manager.hpp"
#include "satchel_charge.hpp"

SatchelCharge::SatchelCharge(const AList& lst)
{
  pos.x = lst.get_float("x-pos");
  pos.y = lst.get_float("y-pos");

  properties->register_float("x-pos", &pos.x);
  properties->register_float("y-pos", &pos.y);

  sprite = resources->get_sprite ("feuerkraft/satchel");
}

void
SatchelCharge::update(float delta)
{
}

void
SatchelCharge::draw(View& view)
{
  view.get_sc().color().draw(sprite, pos.x, pos.y);
}

void
SatchelCharge::detonate()
{
  GameWorld::current()->add (new Explosion(pos, Explosion::MEDIUM));
  remove();
}

/* EOF */
