#ifndef IVALIDATOR_H
#define IVALIDATOR_H
#pragma once

class IValidator
{
public:
	virtual ~IValidator() = default;
	virtual bool Validate() = 0;
};

#endif //IVALIDATOR_H
