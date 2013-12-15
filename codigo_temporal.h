/*

  //--------------------------------comprobacion de los datos cogidos
  textprintf(screen, font, 
  coordX_coche_1,                 
  coordY_coche_1, 
  palette_color[12],"%d", color_en_x_coche_1_arriba_izda);
 
  textprintf(screen, font, 
  coordX_coche_1 + size_coche_x,  
  coordY_coche_1, 
  palette_color[12],"%d", color_en_x_coche_1_arriba_decha);
  textprintf(screen, font, 
  coordX_coche_1,  
  coordY_coche_1 + size_coche_y, 
  palette_color[12],  "%d", color_en_y_coche_1_abajo_izda);
  textprintf(screen, font, 
  coordX_coche_1 + size_coche_x,  
  coordY_coche_1 + size_coche_y, 
  palette_color[12], "%d", color_en_y_coche_1_abajo_decha);
  //--------------------fin de comprobacion de los datos cogidos




  color_en_y_coche_2_abajo_decha =  _getpixel16 (screen, coordX_coche_2 + size_coche_x , coordY_coche_2 + size_coche_y );     
  //probado tambien con _getpixel16 y _getpixel . pero no era el problema. error grave, yo en vez de poner screen ponia el fondo1 donde cogia el pixel





*/  



