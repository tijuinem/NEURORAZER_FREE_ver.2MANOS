void PRESENTACION (void)
{
     portada_y_salida = load_bitmap ("graficos/portada-y-salida.pcx", paleta); 
     draw_sprite(screen, portada_y_salida, 0, 0);
     clear_keybuf();
     
     do
     {    
     textprintf(screen, font, 20,250, palette_color[12], "NEURORAZER, Edicion Gratuita. version 2Ccohes2Manos ");
     textprintf(screen, font, 20,260, palette_color[10], "COCHE 1 - Teclas: Z=Derecha X=Izquierda ");
     textprintf(screen, font, 20,270, palette_color[10], "COCHE 2 - Teclas: M=Derecha N=Izquierda ");
     textprintf(screen, font, 20,285, palette_color[10], "TECLAS -F1/F2- Para Aumentar/Disminuir la Velocidad.");
     textprintf(screen, font, 20,295, palette_color[10], "TECLAS F11/F12 frenaaada !!! o TURBO  ");
     textprintf(screen, font, 20,310, palette_color[10], "TECLA -F9- para activar la segunda tarea   (Punto Rojo)");
     textprintf(screen, font, 20,320, palette_color[10], "Barra Espaciadora para Eliminar el AVISO del Punto Rojo en Pantalla");    
     textprintf(screen, font, 20,335, palette_color[10], "TECLAS -F3/F4- para activar y aumentar la presencia de Bicis.");
     textprintf(screen, font, 20,345, palette_color[10], "TECLAS -F5/F6- para activar y aumentar la presencia de Coches.");
     textprintf(screen, font, 20,355, palette_color[10], "TECLAS -F7/F8- para activar y aumentar la presencia de Camiones.");
      
     textprintf(screen, font, 175,390, palette_color[12], " PULSA ENTER cuando estes listo");
     textprintf(screen, font, 175,400, palette_color[10], "PULSA ESC para abandonar el juego");

     textprintf(screen, font, 20,430, palette_color[9], "Distribuido Open Source bajo licencias GPL-GNU. Y bajo las condiciones CC");

     textout(screen, font,  programadores , 20, 460, palette_color[9]); 
     textout(screen, font,  version_ultima, 20, 470, palette_color[9]);
   
          if  (key[KEY_ESC]) 
          {
          destroy_bitmap(portada_y_salida);
          allegro_exit();
          remove_sound();
          poll_keyboard();
          } 
     } while (!key[KEY_ENTER]);
     clear_keybuf();
     destroy_bitmap(portada_y_salida);
     return;     
}
