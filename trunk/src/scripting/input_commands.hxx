//  $Id: input_commands.hxx,v 1.3 2003/05/14 08:48:48 grumbel Exp $
// 
//  Pingus - A free Lemmings clone
//  Copyright (C) 2002 Ingo Ruhnke <grumbel@gmx.de>
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

#ifndef HEADER_INPUT_COMMANDS_HXX
#define HEADER_INPUT_COMMANDS_HXX

/** @addtogroup scripting */
//@{

/** @brief Register a callback on a key press event 
 *  @param key   a string representing the key, see keys.hxx
 *  @param func  a procedure taking zero arguments
 * 
 *  Currently this is a bit limited and buggy, mouse events and other
 *  input events might also be grabbed when the correct string is
 *  \a key string supplied.
 */
void input_register_callback(const char* key, SCM func);

/** @brief Return the current mouse x position */
int  input_get_mouse_x();

/** @brief Return the current mouse y position */
int  input_get_mouse_y();

//@}


#endif

/* EOF */