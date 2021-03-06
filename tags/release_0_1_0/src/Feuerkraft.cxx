/*
	Loads a single surface from a pcx file without using resource files.
*/

#include <ClanLib/jpeg.h>
#include <ClanLib/png.h>
#include <ClanLib/core.h>
#include <ClanLib/application.h>
#include <ClanLib/gl.h>
#include <guile/gh.h>

#include "Feuerkraft.hxx"
#include "GameWorld.hxx"
#include "KeyboardController.hxx"
#include "JoystickController.hxx"
#include "Tank.hxx"
#include "Jeep.hxx"
#include "Tree.hxx"
#include "Flag.hxx"
#include "Helicopter.hxx"
#include "Turret.hxx"
#include "Playfield.hxx"
#include "Soldier.hxx"
#include "VehicleView.hxx"
#include "VehicleStatus.hxx"
#include "Radar.hxx"
#include "Screen.hxx"
#include "Background.hxx"
#include "Stone.hxx"
#include "System.hxx"
#include "Ambulance.hxx"
#include "LevelMap.hxx"
#include "StartScreen.hxx"

#include "groundmap/GroundMap.hxx"
#include "groundmap/GroundMapData.hxx"
#include "groundmap/GroundMapDataFactory.hxx"

#include "buildings/BuildingMapData.hxx"
#include "buildings/BuildingMap.hxx"
#include "generic/ofstreamext.hxx"

#include <SphriteLib/sphritelibGL.h>

SpriteProviderStorage* storage;
CL_ResourceManager* resources;
CL_ResourceManager* tile_resources;
Pathfinder datafiles;

// FIXME: Ugly global variable, should be removed as soon as possible
VehicleView* vehicle_view;

void inner_main (void* closure, int argc, char* argv[]);

class Feuerkraft : public CL_ClanApplication
{
public:
  virtual char *get_title() { return "Surface application"; }

  virtual int main(int argc, char** argv)
  {
    scm_boot_guile (argc, argv,::inner_main, 0);
    return 0;
  }
	
  virtual int inner_main(void* closure, int argc, char** argv)
  {
    // Create a console window for text-output if not available
    CL_ConsoleWindow console("Console");
    console.redirect_stdio();

    try
      {
	srand (time (0));

	float sec_fraction = 20.0f;
	if (argc == 3)
	  {
	    if (strcmp (argv[1], "--speed") == 0
		&& sscanf (argv[2], "%f", &sec_fraction) == 1)
	      {

	      }
	    else
	      {
		std::cout << "Wrong args: " << argv[1] << " " << argv[2] << std::endl;
	      }
	  }

	datafiles.add_sig_files ("data/feuerkraft.scr");
	datafiles.add_back (".");
	datafiles.add_back ("..");
	datafiles.print ();

	/*
	  try {
	  System::change_dir(datafiles.find_path ("data/feuerkraft.scr"));
	  } catch (Pathfinder::FileNotFound e) {
	  std::cout << "Pathfinder:FileNotFound: " << e.filename << std::endl;
	  }*/

	std::cout << "New Fraction Time: " << sec_fraction << std::endl;
		
	CL_SetupCore::init();
	CL_SetupGL::init();
	CL_SetupDisplay::init();
	CL_SetupPNG::init ();
	CL_SetupJPEG::init ();

	// Set mode: 320x200 16 bpp
	CL_Display::set_videomode(800, 600, 32, false, false);
	CL_OpenGL::begin_2d();

	//glAlphaFunc ( GL_GREATER, 0.1 ) ;

	CL_Display::clear_display ();
	CL_Display::flip_display ();

	std::cout << "Trying this:" << std::endl;
	resources =  new CL_ResourceManager ("data/feuerkraft.scr", false);
	tile_resources =  new CL_ResourceManager ("data/tiles.scr", false);
	storage = new SpriteProviderStorage ();
	storage->add(resources);
	storage->add(tile_resources);
	std::cout << "DoneTrying this:" << std::endl;



	GameWorld* world;
	{
	  std::cout << "<<<<<<<<<<<<< Parsing map <<<<<<<<<<<<<" << std::endl;
	  SCM fdes = scm_open_file (gh_str02scm("data/missions/test.feu"), 
				    gh_str02scm("r"));
	  SCM lst  = scm_read (fdes);

	  GameWorldData data(lst);
	  world = new GameWorld (lst);

	  scm_close (fdes);

	  std::cout << ">>>>>>>>>>>>> Parsing map >>>>>>>>>>>>>" << std::endl;
	}
	// End: Test of parsing code

	Screen    screen;

	Tank* tank2 = new Tank(world, CL_Vector (800, 200), 5, "feuerkraft/tank", "feuerkraft/turret", "feuerkraft/fire");
	Tank* tank1 = new Tank(world, CL_Vector (560, 1245), 5, "feuerkraft/tank2", "feuerkraft/turret2", "feuerkraft/fire2");

	Helicopter* heli = new Helicopter (world, CL_Vector (320, 200));
	//Helicopter* heli2 = new Helicopter (CL_Vector (320, 200));
	Jeep* jeep = new Jeep (world, CL_Vector (250, 250));

	Vehicle* current_vehicle = tank1;
	Controllable* current_controllable = tank1;

	KeyboardController kcontroller (current_controllable);
	JoystickController controller(heli);

	//Radar radar1 (CL_Vector(800-64, 64), 
	//world, tank1);

	//Radar radar2 (CL_Vector(64, 64), 
	//world, tank2);

	Sprite keys (storage->get ("feuerkraft/keys"));
	keys.setHotSpot (0,0);


	boost::shared_ptr<GuiObj> radar 
	  = boost::shared_ptr<GuiObj>(new Radar (CL_Vector(64, 64), 
						 world, current_vehicle));
	screen.add (radar);
	screen.add (boost::shared_ptr<GuiObj>(new VehicleStatus (current_vehicle)));
	//View view (world, 10, 10, 790, 590);

	world->add (jeep);
	world->add (heli);
	//world->add (heli2);
	world->add (tank1);
	world->add (tank2);
	world->add (new Background (world, CL_Surface ("feuerkraft/sand", resources)));
	world->add (new Playfield (world));
	world->add (new Flag (world, CL_Vector(200.0f, 200.f)));
	//world->add (new Tower (world, 400.0, 200.0));
	//world->add (new Tower (world, 500.0, 300.0));
	//world->add (new Tower (world, 300.0, 140.0));
	world->add (new Ambulance (world));
	
	for (int i = 0; i < 20; ++i)
	  {
	    world->add (new Stone (world, CL_Vector (rand () % 2048 - 1024,
						     rand () % 2048 - 1024)));
	  }

	/*byebye trees...world->add (new Tree (world, CL_Vector (100, 400), "feuerkraft/tree"));
	world->add (new Tree (world, CL_Vector (400, 440), "feuerkraft/tree"));
	world->add (new Tree (world, CL_Vector (200, 440), "feuerkraft/tree"));

	world->add (new Tree (world, CL_Vector (150, 300), "feuerkraft/tree2"));
	world->add (new Tree (world, CL_Vector (450, 120), "feuerkraft/tree2"));
	world->add (new Tree (world, CL_Vector (250, 330), "feuerkraft/tree2"));
	*/
	world->add (new Soldier (world, CL_Vector (200, 200)));
	world->add (new Soldier (world, CL_Vector (300, 300)));
	world->add (new Soldier (world, CL_Vector (150, 400)));
	world->add (new Soldier (world, CL_Vector (550, 400)));
	world->add (new Soldier (world, CL_Vector (550, 100)));
	
	/** 1/30sec = 1.0delta
	 */
	float delta;
	unsigned int last_time = CL_System::get_time ();

	int loops = 0;
	float deltas = 0.0;

	VehicleView view (world, current_vehicle, 0, 0, 800, 600);
	view.set_zoom (0.5f);
	view.set_view (400, 300);

	vehicle_view = &view;
	

	//VehicleView view1 (world, heli, 0, 0, 399, 600);
	//VehicleView view2 (world, current_vehicle, 400, 0, 800, 600);
	
	int start_time = CL_System::get_time ();
	int frames = 0;

	CL_System::keep_alive();

	int wannahavefps = 30;
	int delta_wait = 1000/wannahavefps;

	LevelMap levelmap (world);
	
	StartScreen start_screen;
	{
	unsigned int last_time = CL_System::get_time ();
	while (!start_screen.done())
	  {
	    start_screen.update ((CL_System::get_time () - last_time) / 1000.0f);
	    last_time = CL_System::get_time ();

	    start_screen.draw ();
	    CL_Display::flip_display ();
	    CL_System::keep_alive ();
	    CL_System::sleep (10);
	  }
	}

	// Loop until the user hits escape:
	while (start_screen.logo_mode != StartScreen::S_QUIT)
	  {
	    // Poor mans pause button
	    if (CL_Keyboard::get_keycode(CL_KEY_P))
	      {
		while (CL_Keyboard::get_keycode(CL_KEY_P))
		  CL_System::keep_alive();
		while (!CL_Keyboard::get_keycode(CL_KEY_P))
		  CL_System::keep_alive();
		while (CL_Keyboard::get_keycode(CL_KEY_P))
		  CL_System::keep_alive();

		last_time = CL_System::get_time ();
	      }

	    CL_System::sleep (0);

	    /* Switch between hard and variable updates here */
	    //delta = ((CL_System::get_time () - last_time) / 1000.0f);
	    delta = delta_wait/1000.0f;

	    last_time = CL_System::get_time ();
	    world->update (delta);
	    
	    deltas += delta;
	    ++loops;

	    //glRotatef (angle, 0.0, 0.0, 1.0);
	    //glTranslatef (-320,-200, 0);

	    view.draw ();
	    view.update (delta);

	    screen.update (delta);
	    screen.draw ();

	    if (CL_Mouse::left_pressed ())
	      {
		while (CL_Mouse::left_pressed ())
		  CL_System::keep_alive ();
		CL_Vector pos (view.screen_to_world (CL_Vector(CL_Mouse::get_x (), CL_Mouse::get_y ())));
		std::cout << "Mouse: " <<  pos << " | "
			  << world->get_groundmap ()->get_groundtype (pos.x, pos.y) 
			  << " | " <<  int(pos.x) / 40  << " " << int(pos.y) / 40
			  << std::endl;
	      }
	    
	    controller.update (delta);
	    kcontroller.update (delta);
	    
	    // Comment out for variable frame rate
	    int sleep_time = (last_time + delta_wait) - CL_System::get_time();
	    if (sleep_time > 0)
	      CL_System::sleep (sleep_time);

	    if (CL_Keyboard::get_keycode(CL_KEY_M))
	      {
		levelmap.draw ();
	      }

	    keys.draw (CL_Display::get_width () - keys.getWidth (0),
		       CL_Display::get_height () - keys.getHeight (0));

	    start_screen.draw ();
	    start_screen.update (delta);

	    // Flip front and backbuffer. This makes the changes visible:
	    CL_Display::flip_display(true);
	    ++frames;
	    
	    // Update keyboard input and handle system events:
	    // Exits the loop if ClanLib requests shutdown - for instance if
	    // someone closes the window.
	    CL_System::keep_alive();
	  }

	std::cout << "Avarage delta: " << deltas/loops << std::endl;
	std::cout << "Avarage fps:   " 
		  << float (frames) / (CL_System::get_time () - start_time) * 1000.0 << std::endl;

	CL_SetupJPEG::deinit ();
	CL_SetupPNG::deinit ();
	CL_SetupDisplay::deinit();
	CL_SetupCore::deinit();
      }
    catch (CL_Error err)
      {
	std::cout << "CL_Error: " << err.message.c_str() << std::endl;
      }

    // Display console close message and wait for a key
    console.display_close_message();

    return 0;
  }
} feuerkraft;

// Wrapper to call the member func
void inner_main (void* closure, int argc, char* argv[])
{
  feuerkraft.inner_main (closure, argc, argv);
}

// EOF 
