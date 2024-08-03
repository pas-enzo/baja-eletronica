void raster () {
  image(fundo4,0,0);
  
  raster_1_check.resize(55, 0);
  raster_1_x.resize(55, 0);
  if (raster_display == 0) image(raster_1_x, 765, 270);
  else image(raster_1_check, 765, 270);
  
  raster_2_check.resize(55,0);
  raster_2_x.resize(55, 0);
  if (raster_telemetria == 0) image(raster_2_x, 765, 410);
  else image(raster_2_check, 765, 410);
  
  raster_3_check.resize(55,0);
  raster_3_x.resize(55, 0);
  if (raster_dianteira == 0) image(raster_3_x, 765, 545);
  else image(raster_3_check, 765, 545);
 
  raster_4_check.resize(55,0);
  raster_4_x.resize(55, 0);
  if (raster_dianteira == 0) image(raster_4_x, 765, 680);
  else image(raster_4_check, 765, 680);
  
  raster_tpms1_check.resize(55, 0);
  raster_tpms1_x.resize(55, 0);
  if (raster_tpms1 == 0) image(raster_tpms1_x, 1060, 230);
  else image(raster_tpms1_check, 1060, 230);
  
  raster_tpms2_check.resize(55, 0);
  raster_tpms2_x.resize(55, 0);
  if (raster_tpms2 == 0) image(raster_tpms2_x, 1300, 230);
  else image(raster_tpms2_check, 1300, 230);
  
  raster_tpms3_check.resize(55, 0);
  raster_tpms3_x.resize(55, 0);
  if (raster_tpms3 == 0) image(raster_tpms3_x, 1060, 800);
  else image(raster_tpms3_check, 1060, 800);

  raster_tpms4_check.resize(55, 0);
  raster_tpms4_x.resize(55, 0);
  if (raster_tpms4 == 0) image(raster_tpms4_x, 1300, 800);
  else image(raster_tpms4_check, 1300, 800);
}
