#include "databuff.h"
#include "lua.h"

int push_data_source_identifier(
	struct data_buffer *db,
	lua_State *L
	)
{
	signed int iSac,
	signed int iSic,

	/* Get Data Source Identifier */

	/* Get SAC */
	lua_getfield(L, 1, "sac");   /* get table field */
	if (!lua_isnil(L, -1)) {     /* field found */
		int temp;
		temp = luaL_checkint(L, -1);
		if ((temp < 0) || (temp > 255)) {
			/* FIXME: handle error */
		}
		iSac = temp;
	} else {                     /* field not found */
		/* FIXME: handle error */
	}
	lua_pop(L, 1);               /* remove field (or nil) */


	/* Get SIC */
	lua_getfield(L, 1, "sic");   /* get table field */
	if (!lua_isnil(L, -1)) {     /* field found */
		int temp;
		temp = luaL_checkint(L, -1);
		if ((temp < 0) || (temp > 255)) {
			/* FIXME: handle error */
		}
		iSic = temp;
	} else {                     /* field not found */
		/* FIXME: handle error */
	}
	lua_pop(L, 1);               /* remove field (or nil) */

	/* Push SAC and SIC */
	if ( data_buffer_push(db, iSac) || (data_buffer_push(db, iSic) ) {
		/* FIXME: handle error */
		return 0;
	}

	return 1;
}


