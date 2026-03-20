_This project has been created as part of the 42 curriculum by enrgil-p._
<h1>Description</h1>
so_long is my first project that displays a window on screen, working with images and managing keyboard events. 
Consist on a game in 2D, with a character that must collect one item at least and then move to an exit point from a map.


The player can interact with 'W', 'A', 'S' and 'D' keys to move the character on the game map.
Another option is to press Esc or the 'x' button from the window with mouse to close the game's window.

Textures done by Jaime Gil Piqueras.

https://github.com/user-attachments/assets/45b776cc-0b13-4ad0-a51c-b7521c306e48


<h4>Main learnings from this project</h4>

  • **Parse**: To execute the game, you may give a filename of a map as an argument, to play with it. Strict parse of this file is done to make sure that
  it is in correct format and can be played.

  • **Use of foreign code**: To display a window on screen and manage keyboard events, we use X Window System. 
  To make easier this managment, we are allowed to use <a href="https://github.com/42paris/minilibx-linux">Minilibx</a>.
  So, it is first time we are asked to read, understand and apply source code not made by us, as 42's students -besides allowed libc functions, of course.

<p><a href="https://commons.wikimedia.org/wiki/File:X_client_server_example.svg#/media/Archivo:X_client_server_example.svg"><img src="https://upload.wikimedia.org/wikipedia/commons/0/03/X_client_server_example.svg" alt="Ejemplo de despliegue del servidor X: el servidor X recibe la entrada de un teclado y de un ratón locales y exhibe hacia una pantalla. Un navegador web y un emulador de terminal se ejecuta en la estación de trabajo del usuario y un emulador de terminal se ejecuta en un computador remoto pero es controlado y monitoreado desde la máquina del usuario." height="422" width="250"></a><br>Por Original by David Gerard, recreated by <a href="//commons.wikimedia.org/w/index.php?title=User:Efitu&amp;action=edit&amp;redlink=1" class="new" title="User:Efitu (page does not exist)">Efitu</a> - <a href="//commons.wikimedia.org/wiki/File:X_client_server_example.png" title="File:X client server example.png">Wikimedia Commons</a>, <a href="http://creativecommons.org/licenses/by-sa/3.0/" title="Creative Commons Attribution-Share Alike 3.0">CC BY-SA 3.0</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=1391232">Enlace</a></p>

<h1>Instructions</h1>

<h3>Compilation</h3>

This project has a Makefile to compile. Possible options from it are:
    
    make ---> Regular compile

    make fsanitize ---> Compile with fsanitize, to check if there is some error on execution

    make clean ---> Remove objects created on compilation

    make fclean ---> Remove objects + exectuable

    make re ---> Executes make fclean and make


<h3>Execution</h3>

For execute this program, it is required a machine with X11.

<h6>Expected usage</h6>

      ./so_long maps/[name_of_map].ber

There are some example maps on maps/ folder, so program can be tested with correct and wrong formats. A map with correct format must have a name ended by ".ber", rectangular size completely surronded by char '1', at least one item to collect, one character, one exit, and a free way to reach every item and exit point.

<img width="284" height="352" alt="map_format" src="https://github.com/user-attachments/assets/bbbe1614-812d-4863-92d3-9698b1e00860" />

P is initial position for player. E, exit. C are items to collect before you can enter on exit. 1 represents obstacles, and 0 are free positions in which player can move on.

You can close program by click on Esc key, or click with mouse to 'x' on window. Also, if you collect all the items and reach the exit, the window will be closed as end of the program execution.


