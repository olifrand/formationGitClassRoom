/**
 * @file
 * @date      $Date$
 * @version   =TAG=
 * @author    C-S Team
 * @copyright CNES (MDM project)
 *
 * @brief Ce module est le point d'entree de la partition CC.
 *
 */
#include "partition_main.h"
#include "Sequenceur/sequenceur_cc.h"
#include "Initialisateur/initialisateur_cc.h"
#include <xm.h>

#define C_PARTITION_MAIN_RETURN (1)

/**
 * Point d'entree de la partition CC.
 * Il initialise la partition CC puis lance la tache de fond.
 *
 * @return C_PARTITION_MAIN_RETURN
 */
T_INT32 PartitionMain(void)
{
  /* Init de la partition */
  INITIALISATEUR__InitialiserCC();

  /* Boucle infinie */
  while(LIBTOOLS__BouclerInfiniment() == TRUE)
  {
    /* Execution de la tache de fond */
    SEQUENCEUR_CC__ExecuterTacheFond();
  }

  /* Retour de la fonction */
  return (C_PARTITION_MAIN_RETURN);
}
