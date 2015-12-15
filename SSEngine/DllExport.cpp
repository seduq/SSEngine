#include <iostream>
#include "SimpleObj.h"

using namespace SSEngine;
#define DllExport __declspec (dllexport)
extern "C"
{
	DllExport int CreateSimpleObj(int value)
	{
		SimpleObj* obj = new SimpleObj(value);
		return obj->objectId;
	}
	DllExport int SetSimpleObjValue(int id, int value)
	{
		if (SimpleObj::objects == NULL)
			return -1;
		if (id < 0 || id >(int)SimpleObj::objects->size())
			return 1;
		SimpleObj::objects->at(id)->value = value;
		return 0;
	}
	DllExport int GetSimpleObjValue(int id)
	{
		if (SimpleObj::objects == NULL)
			return -1;
		if (id < 0 || id >(int)SimpleObj::objects->size())
			return 1;
		return SimpleObj::objects->at(id)->value;
	}
	DllExport int DeleteSimpleObj(int id)
	{
		if (id < 0 || id >(int)SimpleObj::objects->size())
			return 1;
		if (SimpleObj::objects->at(id) == NULL)
			return 1;
		delete SimpleObj::objects->at(id);
		return 0;
	}
	DllExport void CleanUp()
	{
		SimpleObj::CleanUp();
	}

	
}