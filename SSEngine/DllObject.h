#ifndef SSENGINE_DLLOBJECT_H
#define SSENGINE_DLLOBJECT_H

#include <vector>
namespace SSEngine
{
	template <class T>
	class DllObject
	{
	public:
		int objectId;
		DllObject(std::vector<T*>* ref)
		{
			if (ref == NULL)
				objects = new std::vector<T*>();
			else
				objects = ref;
			objects->push_back((T*)this);
			objectId = (int)objects->size() - 1;
		}
		virtual ~DllObject(void)
		{
			if (objectId > -1)
				(*objects)[objectId] = NULL;
		}
	protected:
		std::vector<T*>* objects;
	};
}
#endif