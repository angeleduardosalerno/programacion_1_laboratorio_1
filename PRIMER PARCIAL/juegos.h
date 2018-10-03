#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

 typedef struct
 {
     int codigoJuego;
     char descripcionJuego[51];
     float importeJuego;
     int isEmpty;

 } Juegos;

    int initJuegos(Juegos arrayJuegos [], int longitudArray);

    int utn_buscarLugarVacioJuegos (Juegos arrayJuegos [],int longitudArray);

    int addJuegos (Juegos arrayJuegos [], int longitudArray, int codigoJuego , char descripcion[], float importe);

    int findJuegoById(Juegos arrayJuegos [], int longitudArray, int codigoJuego);

    int removeJuegos (Juegos arrayJuegos [], int longitudArray, int codigoJuego);

    int sortJuegos (Juegos arrayJuegos [], int longitudArray);

    int printJuegos(Juegos arrayJuegos [], int longitudArray);


 #endif
