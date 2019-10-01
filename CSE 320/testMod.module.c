
/******************************************************************************
  Implements the Boolean function F = ab' + bc'd'

  Uses a two-level hierarchy (function "simnet" calls function "circuit")
******************************************************************************/

#include <Sim.h>

void circuit( SD, Signal, Signal, Signal, Signal );

/******************************************************************************
  Function "simnet" -- test bed for circuit
******************************************************************************/

void simnet()
{
  Signal a, b, c, d, F, G;                   // Switch and output objects 

  Switch ( SD("1a"), a, 'a' );            // Switch a controlled by 'a' key
  Switch ( SD("2a"), b, 'b' );            // Switch b controlled by 'b' key
 
  circuit( SD("1c-4c"), a, b, F, G );

  Probe ( (SD("2e"), "F"), F );           // Probe
  Probe ( (SD("4e"), "G"), G );
}


/******************************************************************************
  Function "circuit" -- implementation of function F
******************************************************************************/


void circuit( SD sd, Signal a, Signal b, Signal F, Signal G )
{
  Module( (sd, "circuit"), (a, b), (F, G) );
  
  Signal nota, notb;
  Signal and1;


  Not ( SD(sd,"3b"), b, notb );
  Not ( SD(sd,"2b"), a, nota );

  And ( SD(sd,"1d"), (nota, notb), and1 );
  
  Or ( SD(sd,"3e"), (a, notb), F );
  Or ( SD(sd,"6e"), (a, and1), G );
 
  
}


