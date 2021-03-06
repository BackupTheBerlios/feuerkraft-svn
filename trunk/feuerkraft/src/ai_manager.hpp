//  $Id: ai_manager.hpp,v 1.3 2003/06/20 20:54:23 grumbel Exp $
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

#ifndef HEADER_AI_MANAGER_HXX
#define HEADER_AI_MANAGER_HXX

#include <vector>

class AI;
class GameObj;

/** The AIManager keeps track of all AI objects around */
class AIManager
{
private:
  static AIManager* instance_;
public:
  static AIManager* instance();

private:
  std::vector<AI*> ais;
public:
  /** @return the AI object that is associated with the given
      game object */
  AI* get_ai(GameObj* obj);

  /** Add an AI object to the AIManager */
  void add(AI* ai);
  void remove(AI* ai);
  void update(float delta);
};

#endif

/* EOF */
