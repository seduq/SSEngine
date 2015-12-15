#include <iostream>
#include <vector>
template <class T>
class DllObject
{
public:
	DllObject(std::vector<T*>* ref)
	{
		objects = ref;
		objects->push_back((T*)this);
		objectId = objects->size() - 1;
	}
	virtual ~DllObject(void)
	{
		if (objectId > -1)
			(*objects)[objectId] = NULL;
	}
protected:
	int objectId;
	std::vector<T*>* objects;
};

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
std::vector<SimpleObj*>* SimpleObj::objects = new std::vector<SimpleObj*>();
SimpleObj::SimpleObj(void) : DllObject(objects)
{
}
SimpleObj::SimpleObj(int val) : DllObject(objects), value(val)
{
}

SimpleObj::~SimpleObj(void)
{

}
void SimpleObj::CleanUp(void)
{
	delete objects;
}

int main()
{
	SimpleObj* obj = new SimpleObj(10);
	std::cout << obj->value;
	delete obj;
	obj->CleanUp();
	return 0;
}