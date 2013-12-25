//      by Tijuinem :   tijuinem -at- gmail -dot- com                   //desarrollado con el proposito de aprender allegro :)
//      NeuroRAZER version "a dos manos2. versión libre del juego Neuroracer , en este caso poniendolo algo más dificil con dos coches en pantalla. Neuroracer es un videojuego creado para mejorar el rendimiento cognitivo. El primero que realmente funciona  ...
//      Indice de versiones:
//      versión alfa 1.0  11-12-2013                                    //version modo local
//      versión alfa 1.1  12-12-2013                                    //carga pantallas ok.                                              
//      versión alfa 1.2  13-12-2013                                    //desde esta versión se libera el código en github. se permite editar, borrar, coger, fork... aunque se agradecerán ampliaciones y mejoras.
//      versión Beta 1.0  25-12-2013                                    //coches. camiones. activo segunda tarea cuando quiero. jugable.

       char version_ultima[80] = "version Beta 1.0  25-12-2013";        //actualizar aqui la versión a la hora de compilar
       char  programadores[80] = "tijuinem at gmail dot com";           //añade tu nombre o mail, para aparecer actualizado en los créditos :)

/*   ______   ___    ___
    /\  _  \ /\_ \  /\_ \
    \ \ \ \ \\//\ \ \//\ \      __     __   _ __   ___
     \ \  __ \ \ \ \  \ \ \   /'__`\ /'_ `\/\`'__\/ __`\
      \ \ \/\ \ \_\ \_ \_\ \_/\  __//\ \ \ \ \ \//\ \ \ \
       \ \_\ \_\/\____\/\____\ \____\ \____ \ \_\\ \____/
        \/_/\/_/\/____/\/____/\/____/\/___ \ \/_/ \/___/
                                       /\____/
                                       \_/__/     Versión 4 */                                     
//------------------------------------------------------------------------------globales
#include <allegro.h>

//------------------------------------------------------------------------------modo grafico del juego
#define modo_pantallaX  640
#define modo_pantallaY 480
#define numero_de_bits 16 

 int fondo_pantalla = 0;
 BITMAP *fondo1, *fondo2, *fondo3, *fondo4, *fondo5, *fondo6, *fondo7, *fondo8, *fondo9;
 BITMAP *portada_y_salida;
 BITMAP *bicis_extra, *coches_extra, *camiones_extra;
 BITMAP *coches_extra_doble_buffer, *bicis_extra_doble_buffer, *camiones_extra_doble_buffer;
 BITMAP *cochePPAL1 , *cochePPAL2 ;
 PALLETE paleta;
 int size_mapa_x = 640;
 int size_mapa_y = 8000;
 long int vida_ppal = 4664;
 int puntos_ppal =0, pantallas_recorridas=0;
 int velocidad_scroll = 1; //1 aconsejable si no funciona el fps.
 int retraso_pintar = 1;   //1 si no FPS
 bool mostramos_coches=false, mostramos_bicis =false, mostramos_camiones = false;
 int numero_coches_a_incrementar =0, numero_bicis_a_incrementar =0 ,numero_camiones_a_incrementar =0; 
 char esto_es_si_bicis [20]=      "BICIS       SI",      esto_es_no_bicis [30]= "BICIS     NO(F3)";
 char esto_es_si_coches [20]=     "COCHES      SI",     esto_es_no_coches [30]= "COCHES    NO(F4)"; 
 char esto_es_si_camiones [20]=   "CAMIONES    SI",   esto_es_no_camiones [30]= "CAMIONES  NO(F5)"; 
 char esto_es_si_p_rojo [20]=     "P.ROJO      SI",     esto_es_no_p_rojo [30]= "P.ROJO    NO(F9)";

 
//-----------------------------------------------------------------------------cargo ficheros externos
#include "carga_pantallas.h" 
#include "codigo_temporal.h" 
#include "presentacion.h"
#include "salida.h"
#include "coches_a_mostrar.h"


//------------------------------------------------------------------------------funcion ppal 
void main(void) 
{ 
//modo grafico del juego + defines arriba
int fin_juego = 0;
 allegro_init();                                                                //Initialize Allegro.  
 set_color_depth(numero_de_bits);                                               //selecciono X bits
 set_gfx_mode(GFX_SAFE, modo_pantallaX , modo_pantallaY, 0, 0);                 //Set the resolution  with SAFE autodetection.
 install_keyboard();   
 install_timer(); 
 srand(time(NULL));
                                          
//-------------------------------------------------------------------------------cargo  graficos
clear_keybuf();                                                                 //Borra el buffer del teclado 
acquire_screen();                                                               //Bloquea screen antes de dibujar en él, screen es el BITMAP por donde nos moveremos 

//------------------------------------------------------------------------------tamaño coche_ppal
int size_coche_x = 20; 
int size_coche_y = 50; 
int coordX_coche_1 = 150 , coordY_coche_1= 350 ;
int coordX_coche_2 = 475 , coordY_coche_2= 350 ;
int incremento_corrdenadas = 1;  
int fondoX = 0 , fondoY= 0 ;
int limite_pantalla_X = modo_pantallaX - size_coche_x, limite_pantalla_Y  = modo_pantallaY - size_coche_y; //limites de pantalla para el objeto.
 cochePPAL1 = load_bitmap   ("graficos/coche316bitsFUCSIA-1.pcx", paleta);
 cochePPAL2 = load_bitmap   ("graficos/coche316bitsFUCSIA-2.pcx", paleta);
 coches_extra = load_bitmap ("graficos/6coches25pixels-ancho.pcx", paleta);
 bicis_extra  = load_bitmap ("graficos/6bicis25pixels-ancho.pcx", paleta);
 camiones_extra  = load_bitmap ("graficos/7camiones50pixels-ancho.pcx", paleta);
 fondo1 = load_bitmap ("graficos/circuitos2coches.pcx", paleta); 
 fondo2 = load_bitmap ("graficos/circuitos2coches (1).pcx", paleta); 
 fondo3 = load_bitmap ("graficos/circuitos2coches (2).pcx", paleta); 
 fondo4 = load_bitmap ("graficos/circuitos2coches (3).pcx", paleta);
 fondo5 = load_bitmap ("graficos/circuitos2coches (4).pcx", paleta); 
 fondo6 = load_bitmap ("graficos/circuitos2coches (5).pcx", paleta);
 fondo7 = load_bitmap ("graficos/circuitos2coches (6).pcx", paleta); 
 fondo8 = load_bitmap ("graficos/circuitos2coches (7).pcx", paleta); 
 fondo9 = load_bitmap ("graficos/circuitos2coches (7).pcx", paleta); 
 
//-------------------------------------------------------------------------------para coger los colores que rodean al coche   
int color_en_x_coche_1_arriba_decha;   
int color_en_x_coche_1_arriba_izda;
int color_en_y_coche_1_abajo_decha;   
int color_en_y_coche_1_abajo_izda;   
int color_en_x_coche_2_arriba_decha;   
int color_en_x_coche_2_arriba_izda;
int color_en_y_coche_2_abajo_decha;   
int color_en_y_coche_2_abajo_izda;    

//-------------------------------------------------------------------------------preparando scroll
 int recorre_y =0;
 int size_pantalla_mostar = 480;
 int fin_de_circuito_Y = size_mapa_y ;
 int pantallas_en_disco = 10; //aleatorio para las pantallas


//------------------------------------------------------------------------------para usar aleatorios
  int aleatorio;
  int dificultad_aleatorio = 5000;
  int x_aleatorio, y_aleatorio;
  int punto_rojo_en_pantalla = 0;
  bool activar_punto_rojo= false; 
  BITMAP *punto_rojo;
  punto_rojo = load_bitmap ("graficos/punto_rojo.pcx", paleta);
 
//------------------------------------------------------------------------------sonido
SAMPLE *choque;
    if (install_sound(DIGI_AUTODETECT, MIDI_NONE, "") != 0) 
    {
        allegro_message("problema tarjeta sonido");
        return;
    }
//------------------------------------------------------------------------------carga del archivo de sonido
    choque = load_sample("sonido/choque_pared.wav");
    if ((!choque))
    {
        allegro_message("no encuentro el archivo de audio");
        return;
    }
//------------------------------------------------------------------------------presentación del juego
clear(screen);                                                                                      
PRESENTACION ();
clear(screen);
carga_pantalla (fondo_pantalla);
    if (mostramos_bicis  == true )                                       
        { bicis_a_mostrar  (6);}
    if (mostramos_coches == true )
        { coches_a_mostrar  (6);}

//------------------------------------------------------------------------------programacion ppal del juego   
do
{ 
 

 if (recorre_y <= size_mapa_y + modo_pantallaY)
 {
      recorre_y = recorre_y + velocidad_scroll;
      blit(fondo1, screen, 0, size_mapa_y - modo_pantallaX  - recorre_y , 0, 0, modo_pantallaX , modo_pantallaY );       //la primera pantalla empieza en el tamaño del mapa menos 480.
      
      textprintf(screen, font, 10,10, palette_color[12], "Pantalla  %d", fondo_pantalla);
      textprintf(screen, font, 10,20, palette_color[12], "VIDA PPAL  %d", vida_ppal);
      textprintf(screen, font, 10,30, palette_color[12], "PUNTOS     %d", puntos_ppal);
      textprintf(screen, font, 10,40, palette_color[12], "VELO       %d  F1-F2", velocidad_scroll);
      textprintf(screen, font, 10,50, palette_color[12], "TURBO      %d  F11-F12", retraso_pintar);
      if (mostramos_bicis == true) 
         { textout(screen, font, esto_es_si_bicis, 10, 70, palette_color[12]);   } 
         else {textout(screen, font, esto_es_no_bicis, 10, 70, palette_color[9]);}
      if (mostramos_coches == true) 
         { textout(screen, font, esto_es_si_coches, 10, 80, palette_color[12]);   } 
         else {textout(screen, font, esto_es_no_coches, 10, 80, palette_color[9]);}
      if (mostramos_camiones == true) 
         { textout(screen, font, esto_es_si_camiones, 10, 90, palette_color[12]);   } 
         else {textout(screen, font, esto_es_no_camiones, 10, 90, palette_color[9]);}
      if (activar_punto_rojo == true) 
         { textout(screen, font, esto_es_si_p_rojo, 10, 100, palette_color[12]);   } 
         else {textout(screen, font, esto_es_no_p_rojo, 10, 100, palette_color[9]);}     
      
      
      textprintf(screen, font, 10,200, palette_color[12], "8000 a  0   %d", fin_de_circuito_Y);
      textprintf(screen, font, 10,210, palette_color[12], "Recorre y   %d", recorre_y);
      draw_sprite(screen, cochePPAL1, coordX_coche_1, coordY_coche_1); 
      draw_sprite(screen, cochePPAL2, coordX_coche_2, coordY_coche_2);

          if ( (recorre_y >= size_mapa_y) &&  (fin_juego == 0)) 
          {
          fondo_pantalla =  rand() % pantallas_en_disco ;                       //cojo una pantalla aleatoria
          recorre_y = - modo_pantallaY;
          pantallas_recorridas ++;
          size_pantalla_mostar = 0;
          //textprintf(screen, font, 310,50, palette_color[15], "Vida + 100   %d", vida_ppal);
          vida_ppal = vida_ppal +100;
          carga_pantalla (fondo_pantalla);
          if (mostramos_bicis  == true )                                        //lamo a los vehiculos a mostrar tantas veces como vaya marcando. cada vez, 6 coches.
              {
              for (int nbi=1; nbi <= numero_bicis_a_incrementar; nbi ++)
                  { bicis_a_mostrar  (6);}
              }
          if (mostramos_coches == true ) 
              {
              for (int nci=1; nci <= numero_coches_a_incrementar; nci ++)
                  { coches_a_mostrar  (6);}              
              }
          if (mostramos_camiones == true ) 
              {
              for (int ncci=1; ncci <= numero_camiones_a_incrementar; ncci ++)
                  { camiones_a_mostrar  (7);}              
              }
          x_aleatorio = rand() % 550;                                           //para mostrar el punto rojo en diferentes sitios en cada circuito
          y_aleatorio = rand() % 375;
          }
           if (key[KEY_ESC] || (fin_juego == 1))                                //escape de juego
           {
           fin_juego = 1;
           clear_keybuf();                 
           }           
        //-----------------------------------------------------------------------coche 1
        if (key[KEY_Z]) 
         if (coordX_coche_1 >= 0 )
         {
         coordX_coche_1 = coordX_coche_1 - incremento_corrdenadas; 
         }            
        if (key[KEY_X]) 
         if (coordX_coche_1 <= limite_pantalla_X )
         {
         coordX_coche_1 = coordX_coche_1 + incremento_corrdenadas;
         }
        //----------------------------------------------------------------------coche 2
        if (key[KEY_N]) 
         if (coordX_coche_2 >= 0 )
         {
         coordX_coche_2 = coordX_coche_2 - incremento_corrdenadas; 
         }          
        if (key[KEY_M]) 
         if (coordX_coche_2 <= limite_pantalla_X )
         {
         coordX_coche_2 = coordX_coche_2 + incremento_corrdenadas;
         }
         rest(retraso_pintar); //por si corre demasiado, aqui lo freno. para no FPS.            
//-------------------------------------------------------------------------------colores que rodean al coche. para choques
  color_en_x_coche_1_arriba_izda =  _getpixel16 (screen, coordX_coche_1 , coordY_coche_1);
  color_en_x_coche_1_arriba_decha = _getpixel16 (screen, coordX_coche_1 + size_coche_x, coordY_coche_1);
  color_en_y_coche_1_abajo_izda =   _getpixel16 (screen, coordX_coche_1 , coordY_coche_1 + size_coche_y);
  color_en_y_coche_1_abajo_decha =  _getpixel16 (screen, coordX_coche_1 + size_coche_x , coordY_coche_1 + size_coche_y );      
  color_en_x_coche_2_arriba_izda =  _getpixel16 (screen, coordX_coche_2 , coordY_coche_2);
  color_en_x_coche_2_arriba_decha = _getpixel16 (screen, coordX_coche_2 + size_coche_x, coordY_coche_2);
  color_en_y_coche_2_abajo_izda =   _getpixel16 (screen, coordX_coche_2 , coordY_coche_2 + size_coche_y);
  color_en_y_coche_2_abajo_decha =  _getpixel16 (screen, coordX_coche_2 + size_coche_x , coordY_coche_2 + size_coche_y );     
  //probado tambien con _getpixel16 y _getpixel . pero no era el problema. error grave, yo en vez de poner screen ponia el fondo1 donde cogia el pixel
      
//------------------------------------------------------------------------------fuera del circuito o detro
   if (( color_en_y_coche_1_abajo_izda == 000000 ) && 
   (  color_en_y_coche_1_abajo_decha == 000000 ) &&  
   (color_en_x_coche_1_arriba_decha == 000000 ) &&  
   (color_en_x_coche_1_arriba_izda== 000000 ) &&  
   (fin_juego == 0) )
  {
  //textprintf(screen, font, coordX_coche_1, coordY_coche_1 + 75, palette_color[12], "1-DENTRO ");
  puntos_ppal ++;
  } else
    {
    //textprintf(screen, font, coordX_coche_1, coordY_coche_1 + 75, palette_color[12], "1-FUERA ");
    play_sample(choque, 255, -255, 1000, FALSE); //int play_sample(const SAMPLE *spl, int vol, int pan, int freq, int loop);
    vida_ppal --;
    }
   if (( color_en_x_coche_2_arriba_izda != 000000 ) || 
   ( color_en_x_coche_2_arriba_decha != 000000) || (
   color_en_y_coche_2_abajo_izda!= 000000) || 
   (color_en_y_coche_2_abajo_decha!= 000000) &&  
   (fin_juego == 0) )
  {
  //textprintf(screen, font, coordX_coche_2 ,coordY_coche_2+75, palette_color[12], "2-FUERA   %d", punto_rojo_en_pantalla);
  play_sample(choque, 255, +255, 1500, FALSE); 
  vida_ppal --;
  } else  
    {
    //textprintf(screen, font, coordX_coche_2 ,coordY_coche_2+75, palette_color[12], "2-DENTRO   %d", punto_rojo_en_pantalla);
    puntos_ppal ++;
    }                                                                           //compruebo un coche de cada forma a ver cual da mejores resultados
        
//------------------------------------------------------------------------------ 
  if (keypressed()) 
  {
    switch (readkey() >> 8) 
    {
        case KEY_F1:
            velocidad_scroll ++;
            break;
        case KEY_F2:
            if ( velocidad_scroll < 1) { velocidad_scroll = 1; puntos_ppal --;}
            velocidad_scroll --;
            break;
        case KEY_F3:
            numero_bicis_a_incrementar ++;
            mostramos_bicis =   true;
            break;
        case KEY_F4:
            numero_coches_a_incrementar ++;
            mostramos_coches =  true;
            break;
        case KEY_F5:
            numero_camiones_a_incrementar ++;
            mostramos_camiones =  true;
            break;
       case KEY_F9:
            activar_punto_rojo= true;
            break;
        case KEY_F11:
            retraso_pintar ++ ;
            break;
        case KEY_F12:
            if ( retraso_pintar < 1) { retraso_pintar = 1; puntos_ppal --;}
            retraso_pintar --;
            break;
        case KEY_P:
            puntos_ppal= puntos_ppal + 1000;                                    //haciendo trampas 
            break;
    }
  }
  
//------------------------------------------------------------------------------aleatorio mostrar avisos
  aleatorio =  rand() % dificultad_aleatorio;
  //textprintf(screen, font, 10,120, palette_color[12], "numero aleatorio %d", aleatorio);
  if ((aleatorio == 69) && (activar_punto_rojo== true))  { punto_rojo_en_pantalla = 1; }
  if ((key[KEY_SPACE])  && (punto_rojo_en_pantalla == 1)){ punto_rojo_en_pantalla = 0; }
  if ( punto_rojo_en_pantalla == 1 ) 
  { 
  draw_sprite(screen, punto_rojo, x_aleatorio, y_aleatorio); 
  play_sample(choque, 255, 0, 2000, FALSE); 
  vida_ppal -- ;
  }
//------------------------------------------------------------------------------penalizar que no ponga siempre el dedo en la barra espaciadora

//-------------------------------------------------------------------------------trampas y puntos
  if ( (puntos_ppal > 1000000) ) { velocidad_scroll = 10; }
  if ( (puntos_ppal > 2000000) ) { velocidad_scroll = 25; }
  if ( (puntos_ppal > 5000000) ) { retraso_pintar   = 0; }                
  if (  vida_ppal <= 0 ) { 
        fin_juego = 1; textout(screen, font, 
        "Vida principal terminada. FIN de JUEGO", 200,200, palette_color[15]); 
        rest (2000); 
        SALIDA(); }

rest (retraso_pintar);  

 } //fin del ciclo  de recorrer fondos y juego
} while (fin_juego==0);


SALIDA ();

//------------------------------------------------------------------------------salir de allegro, con alegría.
 poll_keyboard();                                                               //no deberia ser necesario , pero parece que lo es.
 clear_keybuf();
 allegro_exit();
//------------------------------------------------------------------------------destruyo todas las memorias usadas
 destroy_bitmap(fondo1);
 destroy_bitmap(fondo2);
 destroy_bitmap(fondo3);
 destroy_bitmap(fondo4);
 destroy_bitmap(fondo5);
 destroy_bitmap(fondo6);
 destroy_bitmap(fondo7);
 destroy_bitmap(fondo8);
 destroy_bitmap(fondo9);
 destroy_bitmap(cochePPAL1);
 destroy_bitmap(cochePPAL2);
 destroy_bitmap(punto_rojo);
 destroy_bitmap(bicis_extra);
 destroy_bitmap(coches_extra);
 destroy_bitmap(camiones_extra);
  
//------------------------------------------------------------------------------destruyo todas las memorias audio
 destroy_sample(choque);
//------------------------------------------------------------------------------remove the sound driver
 remove_sound();
return;     
}     
END_OF_MAIN();
