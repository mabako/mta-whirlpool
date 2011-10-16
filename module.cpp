/* Copyright (c) 2011 mabako.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 *    1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 *
 *     2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *
 *     3. This notice may not be removed or altered from any source
 *     distribution.
 */

#include "module.h"
#include "whirlpool.h"

ILuaModuleManager10 *pModuleManager = NULL;

// Initialisation function (module entrypoint)
MTAEXPORT bool InitModule ( ILuaModuleManager10 *pManager, char *szModuleName, char *szAuthor, float *fVersion )
{
	pModuleManager = pManager;

	// Set the module info - If you can not read this in the console, the module is broken
	strncpy ( szModuleName, MODULE_NAME, MAX_INFO_LENGTH );
	strncpy ( szAuthor, MODULE_AUTHOR, MAX_INFO_LENGTH );
	(*fVersion) = MODULE_VERSION;

	return true;
}


MTAEXPORT void RegisterFunctions ( lua_State * luaVM )
{
    if ( pModuleManager && luaVM )
    {
		pModuleManager->RegisterFunction ( luaVM, "whirlpool", CFunctions::whirlpool );
    }
}


MTAEXPORT bool DoPulse ( void )
{
    return true;
}

MTAEXPORT bool ShutdownModule ( void )
{
    
    return true;
}
