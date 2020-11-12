#pragma once
#include <string>
#include <vector>

#include "Helpers/Utils.h"

class FunctionDescriptor
{
public:
	FunctionDescriptor(const std::string& name, ArgCount argCount, const std::vector<std::string>& argTypes);

	FunctionResult Run(ArgCount argCount, va_list& args) const;

	std::string GetName() const;

	virtual ~FunctionDescriptor() { };

protected:
	virtual FunctionResult Execute(ArgCount argCount, const va_list& args) const = 0;

	virtual bool checkValidArgTypes(ArgCount argCount, va_list& args) const = 0;

private:
	const std::string m_Name;

	const ArgCount m_ArgCount;
	const std::vector<std::string> m_ArgTypes;

};

