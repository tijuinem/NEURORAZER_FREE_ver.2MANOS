void SALIDA (void)
{
     portada_y_salida = load_bitmap ("graficos/portada-y-salida.pcx", paleta);
     draw_sprite(screen, portada_y_salida, 0, 0);
     clear_keybuf();
     do
     { 
            
     textprintf(screen, font, 10,250, palette_color[12], "PUNTOS CONSEGUIDOS  %d", puntos_ppal); 
     textprintf(screen, font, 10,280, palette_color[12], "PULSA  -ESC- PARA SALIR "); 
            
            
     } while (!key[KEY_ESC]);
     destroy_bitmap(portada_y_salida);
     clear_keybuf();                   
     allegro_exit();
     remove_sound();
     poll_keyboard();
     return;
}
