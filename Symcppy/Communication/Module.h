#pragma once
#include <string>
#include <vector>

#include"../Helpers/PyEnums.h"
#include "FunctionDescriptor.h"

class Module
{
	friend class ModuleFactory;

public:
	enum EFunction
	{
		Invalid=0,
		Count
	};

	Module& operator=(Module&) = delete;

	virtual EModule GetModuleEnum() const = 0;
	std::string GetName() const;

	FunctionResult CallFunction(FunctionIndex functionIndex, ArgCount argCount, va_list& args) const;

	virtual ~Module() { };

protected:
	Module(const std::string& name) : m_Name(name) { }

	void AddFunction(const FunctionDescriptor* function, EFunction typeOfFunction);

	std::vector<const FunctionDescriptor*> m_Functions;

private:
	const std::string m_Name;


};

