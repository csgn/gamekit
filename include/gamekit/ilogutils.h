#ifndef ILOGUTILS_H
#define ILOGUTILS_H
#include <string>

class ILogUtils
{
public:
	virtual ~ILogUtils() = default;
	virtual const std::string ToString() const = 0;
};

#endif //ILOGUTILS_H
