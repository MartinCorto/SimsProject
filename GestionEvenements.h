#include <stdio.h>
#include <stdlib.h>



typedef struct evt
{
	int id_emet;
	int id_dest;
	int type_act;
	int t_evt;
	/* autres info suivant système */
	struct evt * suiv;
} EVT;


typedef struct
{
	int t_cour;
	int nb_evt;
	EVT * debut;
	/* autres informations suivant système*/
} ECH;