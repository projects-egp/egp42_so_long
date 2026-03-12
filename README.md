_This project has been created as part of the 42 curriculum by enrgil-p._
<h1>Description</h1>
so_long is my first project that displays a window on screen, working with images and managing key events. 
Consist on a game in 2D, with a character that must collect one item at least and then move to an exit point from a map.

The player can interact with 'W', 'A', 'S' and 'D' keys to move the character on the game map.
Another option is to press Esc or the 'x' button from the window with mouse to close the game's window.

<h4>Main learnings from this project</h4>

  • **Parse**: To execute the game, you may give a filename of a map as an argument, to play with it. Strict parse of this file is done to make sure that
  it is in correct format and can be played.

  • **Use of foreign code**: To display a window on screen and manage key events, we use X Window System. 
  To make easier this managment, we are allowed to use <a href="https://github.com/42paris/minilibx-linux">Minilibx</a>.
  So, it is first time we are asked to read, understand and apply source code not made by us, as 42's students -besides allowed libc functions, of course.

<p><a href="https://commons.wikimedia.org/wiki/File:X_client_server_example.svg#/media/Archivo:X_client_server_example.svg"><img src="https://upload.wikimedia.org/wikipedia/commons/0/03/X_client_server_example.svg" alt="Ejemplo de despliegue del servidor X: el servidor X recibe la entrada de un teclado y de un ratón locales y exhibe hacia una pantalla. Un navegador web y un emulador de terminal se ejecuta en la estación de trabajo del usuario y un emulador de terminal se ejecuta en un computador remoto pero es controlado y monitoreado desde la máquina del usuario." height="422" width="250"></a><br>Por Original by David Gerard, recreated by <a href="//commons.wikimedia.org/w/index.php?title=User:Efitu&amp;action=edit&amp;redlink=1" class="new" title="User:Efitu (page does not exist)">Efitu</a> - <a href="//commons.wikimedia.org/wiki/File:X_client_server_example.png" title="File:X client server example.png">Wikimedia Commons</a>, <a href="http://creativecommons.org/licenses/by-sa/3.0/" title="Creative Commons Attribution-Share Alike 3.0">CC BY-SA 3.0</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=1391232">Enlace</a></p>
