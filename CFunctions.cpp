/*********************************************************
*
*  Multi Theft Auto: San Andreas - Deathmatch
*
*  ml_base, External lua add-on module
*
*  Copyright © 2003-2008 MTA.  All Rights Reserved.
*
*  Grand Theft Auto is © 2002-2003 Rockstar North
*
*  THE FOLLOWING SOURCES ARE PART OF THE MULTI THEFT
*  AUTO SOFTWARE DEVELOPMENT KIT AND ARE RELEASED AS
*  OPEN SOURCE FILES. THESE FILES MAY BE USED AS LONG
*  AS THE DEVELOPER AGREES TO THE LICENSE THAT IS
*  PROVIDED WITH THIS PACKAGE.
*
*********************************************************/

extern "C"
{
#include "whirlpool.h"
}
#include "CFunctions.h"
#include "extra/CLuaArguments.h"

int CFunctions::whirlpool( lua_State* luaVM )
{
	if( luaVM )
	{
		CLuaArguments args;
		if( lua_type( luaVM, 1 ) == LUA_TSTRING || lua_type( luaVM, 1 ) == LUA_TNUMBER )
		{
			const char* data = lua_tostring( luaVM, 1 );
			char out[DIGESTBYTES*2+1] = {0};

			struct NESSIEstruct w;
			u8 digest[DIGESTBYTES];

			NESSIEinit(&w);
			NESSIEadd((const unsigned char*)data, strlen(data)*8, &w);
			NESSIEfinalize(&w, digest);

			for(int i=0; i < DIGESTBYTES; ++i)
				sprintf(out, "%s%02x", out, digest[i]);

			args.PushString( out );
		}
		else
		{
			luaL_error( luaVM, "Bad argument @ 'whirlpool'" );
			args.PushBoolean( false );
		}
		args.PushArguments( luaVM );
		return 1;
	}
	return 0;
}
