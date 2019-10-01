
/******************************************************************************
  Project #4 skeleton
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal Init, Clock, w, x, y, z;

  Pulser ((SD("1a"), "c - Clock"), Clock, 'c', 10000);
  Pulser ((SD("1a"), "i - Init"), Init, 'i', 10000);

  circuits( SD("1b-4b"), Init, Clock, w, x, y, z );

  Probe ( (SD("1g"), "w"), w );
  Probe ( (SD("2g"), "x"), x );
  Probe ( (SD("3g"), "y"), y );
  Probe ( (SD("4g"), "z"), z );
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits
******************************************************************************/

void circuits( SD sd, Signal Init, Signal Clock, 
  Signal w, Signal x, Signal y, Signal z )
{
  Module( (sd, "circuits"), (Init, Clock), (w, x, y, z) );

  Signal toW, toX, toY, toZ;
  Signal notw, notx, noty, notz, isx;
  Signal Wy, WY, wz, Xy, Yz;
  Signal xyZ;

  Dff ( SD(sd,"1d") , ( Init, toW, Clock, Zero ), w );
  Dff ( SD(sd,"2d") , ( Zero, toX, Clock, Init ), x );
  Dff ( SD(sd,"3d") , ( Init, toY, Clock, Zero ), y );
  Dff ( SD(sd,"4d") , ( Zero, toZ, Clock, Init ), z );

  Not ( SD(sd,"1a"), w, notw );
  Not ( SD(sd,"2a"), x, notx );
  Not ( SD(sd,"3a"), y, noty );
  Not ( SD(sd,"4a"), z, notz );
  Not ( SD(sd,"5a"), notx, isx );
  
  And ( SD(sd,"1c"), (w, noty), Wy );
  And ( SD(sd,"2c"), (notx, noty, z), xyZ);
  And ( SD(sd,"3c"), (w, y), WY );
  And ( SD(sd,"4c"), (x, noty), Xy );
  And ( SD(sd,"5c"), (notw, notz), wz );
  And ( SD(sd,"6c"), (y, notz), Yz );

  Or ( SD(sd,"1e"), (Wy, xyZ), toW );
  Or ( SD(sd,"2e"), (WY, Xy), toX );
  Or ( SD(sd,"3e"), (isx, Wy), toY );
  Or ( SD(sd,"4e"), (wz, Yz), toZ );
  
}

