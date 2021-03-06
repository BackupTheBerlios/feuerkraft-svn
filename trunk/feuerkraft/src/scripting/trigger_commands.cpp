//  $Id: trigger_commands.cpp,v 1.3 2003/06/03 14:11:22 grumbel Exp $
//
//  Feuerkraft - A Tank Battle Game
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

#include "../trigger_manager.hpp"
#include "../scm_functor.hpp"
#include "trigger_commands.hpp"

// FIXME: return handles to the triggers to allow removal of them

void
trigger_add_timed(float seconds, SCM func)
{
  TriggerManager::current()->add_timed_trigger(seconds, SCMFunctor(func));
}

void
trigger_add_tile(int x, int y, SCM func)
{
  TriggerManager::current()->add_tile_trigger(x, y, SCMFunctor(func));
}

void
trigger_add_region(int x1, int y1, int x2, int y2, SCM func)
{
}

/* EOF */
