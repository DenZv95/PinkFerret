SFML Tiled Map Loader v0.1

So here it is. A C++, SFML-based class for handling Tiled map files.

Usage should be very straightforward, but there are a few points I need to make:

-I don't support compressed tmx files (yet). You have to change your Tiled preferences to save as plain xml.
-This currently only handles one tilesheet. This shouldn't really be a problem - I don't really see the need to have more than one just yet.
-Currently doesn't support for isometric maps (I will be working on this soon).


A quick guide:
To build your project you will need tinyxml. You need obtain, build and link it yourself. In a later version I will be providing a pre-built binary lib to simplify this.
http://www.grinninglizard.com/tinyxml/

You obviously need to link to the SFML libs as you normally would.

Now that you have a project set up,

Include the level.h file wherever you need it.

Create an instance of Level.

Level level;

To load a map file,

level.LoadFromFile("example.tmx");

You MUST set drawing bounds before attempting to display the level.

level.SetDrawingBounds(somesfview.GetRect());

I recommend using an sf::View to "scroll" the map, rather than moving the map itself. This way you don't have to worry about objects (NPCs etc) on your map moving (or not) correctly.
You will find you need to implement some system to only move the view by whole numbers, otherwise you will see gaps between tiles.

Then to draw you simply pass your renderwindow to the Draw function.

level.Draw(window);


Planned features:
-Higher level of of not-crashiness. For example, if you try and get an object (GetObject()) That doesn't exist, the program will crash.
-Support for compressed maps - Base64(gzip), Base64(zlib) - some or all of these.
-Isometric map support
-Support for multiple tilesets in one map



See www.mapeditor.org to get Tiled.


Note that I am in no way affiliated with Tiled, SFML or tinyxml.