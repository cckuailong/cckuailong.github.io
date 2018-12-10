#include "config.h"
#include "bgpcorsaro_int.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "utils.h"
#include "wandio_utils.h"

#include "bgpcorsaro_io.h"
#include "bgpcorsaro_log.h"
#include "bgpcorsaro_plugin.h"

#include "bgpcorsaro_elemcounter.h"

/** @file
 *
 * @brief Bgpcorsaro Elem Counter plugin implementation
 *
 */

/** The name of this plugin */
#define PLUGIN_NAME "elemcounter"

/** The version of this plugin */
#define PLUGIN_VERSION "0.1"

/** Common plugin information across all instances */
static bgpcorsaro_plugin_t bgpcorsaro_elemcounter_plugin = {
  PLUGIN_NAME,                                  /* name */
  PLUGIN_VERSION,                               /* version */
  BGPCORSARO_PLUGIN_ID_ELEMCOUNTER,                 /* id */
  BGPCORSARO_PLUGIN_GENERATE_PTRS(bgpcorsaro_elemcounter), /* func ptrs */
  BGPCORSARO_PLUGIN_GENERATE_TAIL,
};


/** Holds the state for an instance of this plugin */
struct bgpcorsaro_elemcounter_state_t {

  /* useful variables HERE*/
  
};


/** Extends the generic plugin state convenience macro in bgpcorsaro_plugin.h */
#define STATE(bgpcorsaro)						\
  (BGPCORSARO_PLUGIN_STATE(bgpcorsaro, elemcounter, BGPCORSARO_PLUGIN_ID_ELEMCOUNTER))

/** Extends the generic plugin plugin convenience macro in bgpcorsaro_plugin.h */
#define PLUGIN(bgpcorsaro)						\
  (BGPCORSARO_PLUGIN_PLUGIN(bgpcorsaro, BGPCORSARO_PLUGIN_ID_ELEMCOUNTER))

/** Print usage information to stderr */
static void usage(bgpcorsaro_plugin_t *plugin)
{
  fprintf(stderr,
	  "plugin usage: %s [options HERE]\n",
	  plugin->argv[0]);
}

/** Parse the arguments given to the plugin */
static int parse_args(bgpcorsaro_t *bgpcorsaro)
{
  bgpcorsaro_plugin_t *plugin = PLUGIN(bgpcorsaro);
  int opt;

  if(plugin->argc <= 0)
    {
      return 0;
    }

  /* NB: remember to reset optind to 1 before using getopt! */
  optind = 1;

  while((opt = getopt(plugin->argc, plugin->argv, ":h?")) >= 0)
    {
      switch(opt)
	{
	case 'h':
	case '?':
	case ':':
	default:
	  usage(plugin);
	  return -1;
	}
    }

  return 0;
}




/* == PUBLIC PLUGIN FUNCS BELOW HERE == */

/** Implements the alloc function of the plugin API */
bgpcorsaro_plugin_t *bgpcorsaro_elemcounter_alloc(bgpcorsaro_t *bgpcorsaro)
{
  return &bgpcorsaro_elemcounter_plugin;
}

/** Implements the init_output function of the plugin API */
int bgpcorsaro_elemcounter_init_output(bgpcorsaro_t *bgpcorsaro)
{
  struct bgpcorsaro_elemcounter_state_t *state;
  bgpcorsaro_plugin_t *plugin = PLUGIN(bgpcorsaro);
  assert(plugin != NULL);

  if((state = malloc_zero(sizeof(struct bgpcorsaro_elemcounter_state_t))) == NULL)
    {
      bgpcorsaro_log(__func__, bgpcorsaro,
		     "could not malloc bgpcorsaro_elemcounter_state_t");
      goto err;
    }
  bgpcorsaro_plugin_register_state(bgpcorsaro->plugin_manager, plugin, state);

  /* initialize state variables HERE */
  
  /* parse the arguments */
  if(parse_args(bgpcorsaro) != 0)
    {
      return -1;
    }

  return 0;

 err:
  bgpcorsaro_elemcounter_close_output(bgpcorsaro);
  return -1;
}

/** Implements the close_output function of the plugin API */
int bgpcorsaro_elemcounter_close_output(bgpcorsaro_t *bgpcorsaro)
{

  struct bgpcorsaro_elemcounter_state_t *state = STATE(bgpcorsaro);

  if(state != NULL)
    {

      /* deallocate dynamic memory in state HERE */
      
      bgpcorsaro_plugin_free_state(bgpcorsaro->plugin_manager, PLUGIN(bgpcorsaro));
    }
  return 0;
}

/** Implements the start_interval function of the plugin API */
int bgpcorsaro_elemcounter_start_interval(bgpcorsaro_t *bgpcorsaro,
                                          bgpcorsaro_interval_t *int_start)
{
  
  /* interval start operations HERE */

  return 0;
}

/** Implements the end_interval function of the plugin API */
int bgpcorsaro_elemcounter_end_interval(bgpcorsaro_t *bgpcorsaro,
                                        bgpcorsaro_interval_t *int_end)
{

  /* interval end operations HERE */

  return 0;
}

/** Implements the process_record function of the plugin API */
int bgpcorsaro_elemcounter_process_record(bgpcorsaro_t *bgpcorsaro,
                                          bgpcorsaro_record_t *record)
{

  /* interval process record operations HERE */

  return 0;
}
