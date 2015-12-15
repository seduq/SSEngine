#include "SimpleObj.h"
#include <vector>

namespace SSEngine
{
	std::vector<SimpleObj*>* SimpleObj::objects = new std::vector<SimpleObj*>();
	SimpleObj::SimpleObj(void) : DllObject<SimpleObj>(objects)
	{
		if (objects == NULL)
			objects = DllObject::objects;
	}
	SimpleObj::SimpleObj(int val) : DllObject<SimpleObj>(objects), value(val)
	{
		if (objects == NULL)
			objects = DllObject::objects;
	}

	SimpleObj::~SimpleObj(void)
	{
	}
	void SimpleObj::CleanUp(void)
	{
		if (objects != NULL)
			delete objects;
		objects = NULL;
	}
}