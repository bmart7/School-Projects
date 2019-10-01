
/******************************************************************************
  Project #3 skeleton
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, 
  Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal w, x, y, z, Present, a, b, c, d, e, f, g;

  Signal Strobe (1);
  Signal ResetA (1);
  Signal ResetB (1);

  Pulser ((SD("1a"), "r -- Reset counter"),  ResetA, 'r', 10000);
  Pulser ((SD("2a"), "s -- Strobe counter"), Strobe, 's', 10000);

  Not (SD("1b"), ResetA, ResetB);

  Counter ((SD("1c-2c"), "4-bit counter"), (ResetB, Strobe), (w, x, y, z));

  circuits( SD("1d-4d"), w, x, y, z, Present, a, b, c, d, e, f, g);

  Probe ( (SD("1f"), "Present"), Present );
  Probe ( (SD("2f"), "a"), a );
  Probe ( (SD("3g"), "b"), b );
  Probe ( (SD("5g"), "c"), c );
  Probe ( (SD("6f"), "d"), d );
  Probe ( (SD("5e"), "e"), e );
  Probe ( (SD("3e"), "f"), f );
  Probe ( (SD("4f"), "g"), g );
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits

  Do not alter the interface -- function "circuits" must receive four
  signals as inputs and return eight signals as outputs.
******************************************************************************/

void circuits( SD sd, Signal w, Signal x, Signal y, Signal z, 
  Signal Present, Signal a, Signal b, Signal c, Signal d, Signal e,
  Signal f, Signal g )    
{
  Module( (sd, "circuits"), (w, x, y, z), (Present, a, b, c, d, e, f, g) );

  Signal notw, notx, noty, notz;
  Signal wY, yz;
  Signal Wxz, wxZ, wyZ, xyz;
  Signal wXYz;

  Not ( SD(sd,"1a"), w, notw );
  Not ( SD(sd,"2a"), x, notx );
  Not ( SD(sd,"3a"), y, noty );
  Not ( SD(sd,"4a"), z, notz );
  Not ( SD(sd,"5a"), x, b );
  Not ( SD(sd,"6a"), z, e );

  And ( SD(sd,"1c"), (notx, noty, notz), xyz );
  And ( SD(sd,"2c"), (w, notx, notz), Wxz );
  And ( SD(sd,"3c"), (notw, noty, z), wyZ );
  And ( SD(sd,"4c"), (notw, notx, z), wxZ );
  And ( SD(sd,"5c"), (notw, x, y, notz), wXYz );
  And ( SD(sd,"6c"), (notw, y), wY );
  And ( SD(sd,"7c"), (noty, notz), yz );

  Or ( SD(sd,"1e"), (xyz, Wxz, wyZ, wxZ, wXYz), Present );
  Or ( SD(sd,"2e"), (x, y, notz), a );
  Or ( SD(sd,"3e"), (One, One), c );
  Or ( SD(sd,"4e"), (wY, yz, x), d );
  Or ( SD(sd,"5e"), (x, notz), f);
  Or ( SD(sd,"6e"), (w, x, y), g);
  
}

