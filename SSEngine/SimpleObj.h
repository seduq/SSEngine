#ifndef SSENGINE_SIMPLEOBJ_H
#define SSENGINE_SIMPLEOBJ_H

#include "DllObject.h"
#include <vector>

namespace SSEngine
{

	class SimpleObj : public DllObject<SimpleObj>
	{
	public:
		static std::vector<SimpleObj*>* objects;
		int value;
		SimpleObj(void);
		SimpleObj(int val);

		~SimpleObj(void);
		static void CleanUp();
	};
}
#endif