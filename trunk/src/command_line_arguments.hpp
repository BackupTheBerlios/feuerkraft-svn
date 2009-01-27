//  $Id: command_line_arguments.hpp,v 1.5 2003/10/31 23:24:41 grumbel Exp $
// 
//  Feuerkraft - A Tank Battle Game
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

#ifndef HEADER_FEUERKRAFT_COMMAND_LINE_ARGUMENTS_HXX
#define HEADER_FEUERKRAFT_COMMAND_LINE_ARGUMENTS_HXX

#include <string>

/** */
struct CommandLineArguments
{
public:
  int screen_width;
  int screen_height;
  
  /** Mission file to start, empty() if non is given */
  std::string mission_file;

  /** Path to all the datafiles */
  std::string datadir;
  std::string controller_file;

  /** File to which all input events should be logged */
  std::string event_record_file;

  /** Directory to which gameplay-video (aka screenshots) get saved */
  std::string video_record_directory;

  /** File from which recorded events will be played back */
  std::string playback_file;

  /** number of fps to which the game should limit itself */
  float fps;

  /** Number of the joystick to use, -1 for keyboard support */
  int joystick;

  bool music_enabled;
  bool sound_enabled;

  bool fullscreen;

  bool verbose;

  CommandLineArguments();
  CommandLineArguments(int argc, char** argv);

  void load_defaults();
  void parse_arguments(int argc, char** argv);
};

extern CommandLineArguments* args;

#endif

/* EOF */
