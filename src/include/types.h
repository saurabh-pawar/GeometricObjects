#ifndef TYPES_H
#define TYPES_H

#include <string>
#include <vector>

typedef struct {
	std::string key;
	std::string value;
}ObjectProperty;

typedef std::vector<ObjectProperty> ObjectData;

typedef std::vector<ObjectData> CollectionData ;


#endif
