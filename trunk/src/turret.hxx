#ifndef TURRET_HH
#define TURRET_HH

#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include "game_obj.hxx"

class Tank;

class Turret : public GameObj
{
private:
  boost::dummy_ptr<Tank> tank;

  CL_Sprite fire_sur;
  CL_Sprite sur;
  CL_Sprite shadow;

  // The angle of the turent relative to the tank in radians
  float angle;

  bool fireing;
  int  reloading;
  int  reloading_speed;

public:
  Turret (boost::dummy_ptr<GameWorld>  w,
	  Tank*, int reloading_speed, std::string, std::string);
  ~Turret ();

  void draw (View* view);
  void update (float);

  void increase_angle (float delta);
  void decrease_angle (float delta);
  void start_fire ();
  void stop_fire ();
  void set_angle (float angle);
};

#endif // TURRET_HH

// EOF