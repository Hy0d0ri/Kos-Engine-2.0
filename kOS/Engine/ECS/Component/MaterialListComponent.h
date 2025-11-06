#ifndef MATERIALLISTCOMPONENT_H
#define MATERIALLISTCOMPONENT_H

#include "Component.h"
namespace ecs {
	class MaterialListComponent :public Component {
	public:
		std::vector<utility::GUID> materialGUIDList{};
		REFLECTABLE(MaterialListComponent, materialGUIDList);
	};
}
#endif